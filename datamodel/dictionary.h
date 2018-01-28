#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <transactions/transactionobject.h>
#include <list>

class dicentry;


class dictionary : public TransactionObject
{
public:
    dictionary();
    ~dictionary(){};

    list<dicentry*> *getEntries();
    void addToEntries(dicentry* de);
    void deleteFromEntries(dicentry* de);

    void addEntry(string vn, string nn, string jn);
    dicentry* find(string vn, string nn);
    dicentry* find(string jn);
    //string find(string jn);

private:
    string getGKey(string vn, string nn);
    string getGKey(dicentry*);
    string getJKey(dicentry*);
    void load();

private:
    list<dicentry*> *list_entries;
    map<string,dicentry*> germtojap;
    map<string,dicentry*> japtogerm;
};

#endif // DICTIONARY_H
