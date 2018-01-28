#include "mainwindow.h"
#include <QApplication>
#include <mapping/mappingcontroler.h>
#include <transactions/transactions.h>
#include "guirepository.h"
#include "datamodel/datamodelrepository.h"
#include "readfileaction.h"
#include <standardguimode.h>
#include "filmitemtemplate.h"
#include "katalogguimode.h"
#include "dictionaryaction.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString dbName=a.arguments().at(1);
    MappingControler::setDatabaseName(dbName);
    MappingControler::getInstance();

    DatamodelRepository::init();
    GuiRepository::getInstance()->initGui();
    GuiRepository::getInstance()->addMode(new StandardGuiMode());
    GuiRepository::getInstance()->addMode(new KatalogGuiMode());
    GuiRepository::getInstance()->addGlobalAction(new ReadFileAction());
    GuiRepository::getInstance()->addGlobalAction(new DictionaryAction());
    GuiRepository::getInstance()->registerPObjectIconViewItemTemplate(QString("film"),new FilmItemTemplate());
    /*
    MainWindow w;
    w.show();
    */


    return a.exec();
}
