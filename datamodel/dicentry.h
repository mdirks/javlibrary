#ifndef DICENTRY_H
#define DICENTRY_H

#include <transactions/transactionobject.h>

class dicentry : public TransactionObject
{
public:
    dicentry();
    ~dicentry(){};

    string getVorname();
    void setVorname(string vn);

    string getNachname();
    void setNachname(string vn);


    string getJapanese();
    void setJapanese(string j);

private:
    string vn,nn,jn;
};

#endif // DICENTRY_H
