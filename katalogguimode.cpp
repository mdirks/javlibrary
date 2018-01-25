#include "katalogguimode.h"

#include <guirepository.h>
#include <guiconfig.h>
#include <datamodel/actressmapper.h>

KatalogGuiMode::KatalogGuiMode()
    : GuiMode("KatalogMode")
{
    sp=0;

    QPixmap pm = GuiConfig::getInstance()->getIcon("KatalogMode");
    if(pm.isNull()){
        GuiConfig::getInstance()->selectIcon("KatalogMode");
        pm = GuiConfig::getInstance()->getIcon("KatalogMode");
    }
    setIcon(pm);
}

void KatalogGuiMode::setupMode()
{
    GuiRepository *guirep=GuiRepository::getInstance();
    QStackedWidget *sw=guirep->getCentralWidget();

    guirep->setActiveMode(this);
    if(!sp){
        sp = new QSplitter(sw);
        aview = new PObjectIconView(actressmapper::getInstance(),sp);
        RepositoryEntry *re=Repository::getInstance()->getRepositoryEntry("actress");
        if(re){
            rp_film=re->getProperty("Filme");
        }
        mview = new PObjectIconView(sp);
        mview->setItemTemplate(GuiRepository::getInstance()->getPObjectIconViewItemTemplate("film",mview));

        connect(aview,SIGNAL(currentChanged()),this,SLOT(resetActress()));
        videow = new QVideoWidget(sp);

        GuiRepository::getInstance()->registerVideoWidget(videow);

        sp->addWidget(aview);
        sp->addWidget(mview);
        sp->addWidget(videow);
    }
    sp->setMinimumHeight(800);
    sp->setMinimumWidth(1200);
    sw->setCurrentWidget(sp);
    sp->setVisible(true);
    aview->setVisible(true);


}


void KatalogGuiMode::resetActress()
{
    PObject *o=aview->getSelected();
    if(o){
        actress *a=dynamic_cast<actress*>(o);
        if(a){
            mview->setObjectListProvider(new RpListProvider(rp_film,a));
            }
    }

}
