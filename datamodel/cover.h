#ifndef COVER_H
#define COVER_H

#include <transactions/transactionobject.h>
#include <string>

class cover : public TransactionObject
{
public:
    cover();
    ~cover(){};

    string getFileName();
    void setFileName(string fn);

private:
    string fileName;
};

#endif // COVER_H
