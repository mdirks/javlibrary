#ifndef READFILEACTION_H
#define READFILEACTION_H

#include <QAction>

class ReadFileAction : public QAction
{
Q_OBJECT

public:
    ReadFileAction();

public slots:
    virtual void readFile(bool b);
};

#endif // READFILEACTION_H
