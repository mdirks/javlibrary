#include "dictionaryaction.h"
#include "datamodel/dictionarymapper.h"
#include <repository/repositoryproperty.h>
#include <pobjecttable.h>
#include <guiconfig.h>
#include <guirepository.h>
#include <transactions/transactions.h>
#include <list>

DictionaryAction::DictionaryAction()
    : QAction("ShowDic",0)
{
    dic=0;
    setIcon(GuiConfig::getInstance()->getIcon("show_dic"));
    connect(this,SIGNAL(triggered(bool)),this,SLOT(showDictionary(bool)));
}

void DictionaryAction::showDictionary(bool b)
{
    PObjectTable *pt = new PObjectTable("actress",
                                        GuiRepository::getInstance()->getCentralWidget(),
                                        true);
    GuiRepository::getInstance()->showDialog(pt);
    pt->load();

    /*if(!dic){
        list<dictionary*> *ldic = dictionarymapper::getInstance()->find();
        if(ldic->size()==0){
            dic=dictionarymapper::create();
            Transactions::getCurrentTransaction()->add(dic);
        } else {
            dic=ldic->front();
        }
        RepositoryEntry *re=Repository::getInstance()->getRepositoryEntry("dictionary");
            if(re){
                RepositoryProperty *rp = re->getProperty("Entries");
                if(rp){
                    PObjectTable *pt = new PObjectTable(rp,dic);
                    GuiRepository::getInstance()->showDialog(pt);

                }
            }

    }
    */
}
