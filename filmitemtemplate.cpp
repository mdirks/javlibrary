#include "filmitemtemplate.h"
#include "datamodel/film.h"
#include "datamodel/cover.h"
#include <pobjecticonview.h>
#include <guirepository.h>
#include <QPixmap>


FilmItem::FilmItem(PObject *o, QListWidget *iv)
    : PObjectIconViewItemBase(o,iv)
{

}


void FilmItem::activateItem()
{
    if( film *f = dynamic_cast<film*>(getObject()) ){
        QString mf = QString::fromStdString(f->getMovieFile());
        //if(mf != QString()){
            GuiRepository::getInstance()->showMovie(mf);

        //}
    }
}


FilmItemTemplate::FilmItemTemplate()
{
    iv=0;
}


FilmItemTemplate::FilmItemTemplate(QListWidget *iv)
{
    this->iv=iv;
    if(PObjectIconView *iconv = dynamic_cast<PObjectIconView*>(iv)){
        connect(iconv,SIGNAL(resized()),this,SLOT(resizeIcons()));
    }
}

PObjectIconViewItemTemplate* FilmItemTemplate::getInstanceFor(QListWidget *lv)
{

    return new FilmItemTemplate(lv);
}


PObjectIconViewItemBase* FilmItemTemplate::createItem(PObject *o)
{
    FilmItem *item=new FilmItem(o,iv);
    if(film *fm = dynamic_cast<film*>(o)){
        this->fm=fm;
        cover *c = fm->getCover();
        if(c){
            string cf = c->getFileName();
            QPixmap pm(200,100);
            pm.load(cf.c_str());
            item->setIcon(QIcon(pm));
        }
    }
    return item;
}

void FilmItemTemplate::resizeIcons()
{
    if(iv){
        iv->setIconSize(iv->viewport()->size());
    }
}

void FilmItemTemplate::activateItem()
{
    if(fm){
        QString movieFile=QString::fromStdString(fm->getMovieFile());
        if(movieFile!=QString()){
            GuiRepository::getInstance()->showMovie(movieFile);
        }
    }
}
