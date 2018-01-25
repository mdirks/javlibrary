#ifndef ACTRESS_H
#define ACTRESS_H


#include <transactions/transactionobject.h>
#include <list>

class film;

class actress : public TransactionObject
{

public:
    actress();
    ~actress(){};

    virtual string getVorname();
    void setVorname(string n);
    string getNachname();
    void setNachname(string n);


    list<film*> *getFilme();
    void addToFilme(film*);
    void deleteFromFilme(film*);

private:
    string vname,nname;
    list<film*> *list_filme;
};

#endif // ACTRESS_H
