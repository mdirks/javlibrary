#ifndef READFILEACTION_H
#define READFILEACTION_H

#include <datamodel/dictionary.h>
#include <QAction>

class ReadFileAction : public QAction
{
Q_OBJECT

public:
    ReadFileAction();

public slots:
    virtual void readFile(bool b);

private:
    void addToDic(QString vn,QString nn);
    dictionary *dic;
};

#endif // READFILEACTION_H
