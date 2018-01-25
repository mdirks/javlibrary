#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <guimainwindow.h>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public GuiMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void readFile();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
