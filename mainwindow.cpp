#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "guirepository.h"
#include "guiconfig.h"
#include <QToolBar>


MainWindow::MainWindow(QWidget *parent) :
    GuiMainWindow(parent)
{
    QToolBar *tb = new QToolBar("MainTb",this);
    QAction *rfaction=tb->addAction("read_file",this,SLOT(readFile()));

    rfaction->setIcon(GuiConfig::getInstance()->getIcon("read_file"));
    rfaction->setText("Read File");

    addToolBar(tb);
}

MainWindow::~MainWindow()
{

}

void MainWindow::readFile()
{
    qDebug() << "read File called";
}
