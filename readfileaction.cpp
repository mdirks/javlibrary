#include "readfileaction.h"

#include <guiconfig.h>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QDir>

#include <pobjectlistprovider.h>
#include <filter/stringpropertyfilter.h>
#include <repository/repositoryproperty.h>
#include <repository/repository.h>

#include "datamodel/actressmapper.h"
#include "datamodel/filmmapper.h"
#include "datamodel/covermapper.h"

#include <transactions/transactions.h>

ReadFileAction::ReadFileAction()
    : QAction("ReadFile",0)
{
    setIcon(GuiConfig::getInstance()->getIcon("read_file"));
    connect(this,SIGNAL(triggered(bool)),this,SLOT(readFile(bool)));
}

void ReadFileAction::readFile(bool b)
{
    QString dirname=QFileDialog::getExistingDirectory();
    QDir dir(dirname);

    PObjectListProvider *lp_actress= new MapperListProvider("actress");
    PObjectListProvider *lp_film= new MapperListProvider("film");

    RepositoryEntry *re = Repository::getInstance()->getRepositoryEntry("actress");
    RepositoryProperty *rp= re->getProperty("Vorname");
    StringPropertyFilter *f_a_vn=new StringPropertyFilter(rp,"test");

    rp= re->getProperty("Nachname");
    StringPropertyFilter *f_a_nn=new StringPropertyFilter(rp,"test");

    re = Repository::getInstance()->getRepositoryEntry("film");
    rp= re->getProperty("Code");
    StringPropertyFilter *f_f_c=new StringPropertyFilter(rp,"test");

    QString coverFile;
    QString movieFile;
    bool isCover,isMovie;
    QStringList entries=dir.entryList();
    for(QStringList::iterator it=entries.begin(); it!=entries.end(); it++){
        QString fn=(*it);
        if(fn.contains(".jpg")){
            isCover=true;
            isMovie=false;
            coverFile = dir.absoluteFilePath(fn);
        }
        if(fn.contains(".mp4")){
            isMovie=true;
            isCover=false;
            movieFile = dir.absoluteFilePath(fn);
        }

        fn=fn.remove(".jpg");
        fn=fn.remove(".mp4");
        QStringList sl = fn.split("-");
        if(sl.size()==4){
            QString code=sl.at(0) + "-" + sl.at(1);
            QString vname=sl.at(2);
            QString nname=sl.at(3);

            qDebug() << code << " by " << nname << " " << vname;
            f_a_vn->setValueString(vname.toStdString());
            f_a_nn->setValueString(nname.toStdString());
            list<PObject*> *actress_match=new list<PObject*>();
            f_a_vn->apply(lp_actress->objectList(),actress_match);
            f_a_nn->apply(actress_match);

            actress *ac=0;
            if(actress_match->size()>0){
                qDebug() << "found existing actress";
                ac=(actress*)(actress_match->front());
            } else {
                ac = actressmapper::getInstance()->create();
                ac->setVorname(vname.toStdString());
                ac->setNachname(nname.toStdString());
                lp_actress->addObject(ac);
            }

            f_f_c->setValueString(code.toStdString());
            list<PObject*> *film_match = new list<PObject*>();
            f_f_c->apply(lp_film->objectList(),film_match);

            film *f=0;
            if(film_match->size()>0){
                qDebug() << "found existing film";
                f=(film*)film_match->front();
            } else {
                f = filmmapper::getInstance()->create();
                f->setCode(code.toStdString());

                lp_film->addObject(f);
            }
            f->setActress(ac);
            if(isCover){
                cover *c=covermapper::getInstance()->create();
                c->setFileName(coverFile.toStdString());
                c->setName(code.toStdString());
                f->setCover(c);
                Transactions::getCurrentTransaction()->add(c);
            }
            if(isMovie) f->setMovieFile(movieFile.toStdString());
            ac->deleteFromFilme(f);
            ac->addToFilme(f);
            Transactions::getCurrentTransaction()->add(f);
            Transactions::getCurrentTransaction()->add(ac);

        }
    }
}
