#ifndef DICTIONARYACTION_H
#define DICTIONARYACTION_H

#include <QAction>
#include <datamodel/dictionary.h>

class DictionaryAction : public QAction
{
Q_OBJECT

public:
    DictionaryAction();

public slots:
    void showDictionary(bool b);

private:
    dictionary *dic;
};

#endif // DICTIONARYACTION_H
