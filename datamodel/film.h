#ifndef FILM_H
#define FILM_H

#include <transactions/transactionobject.h>

class actress;
class cover;

class film : public TransactionObject
{
public:
    film();
    ~film(){};

    string getTitle();
    void setTitle(string t);

    string getCode();
    void setCode(string c);

    string getCoverFile();
    void setCoverFile(string cf);

    string getMovieFile();
    void setMovieFile(string mf);

    actress* getActress();
    void setActress(actress *act);

    cover* getCover();
    void setCover(cover *c);

private:
    string title, code;
    string coverFile,movieFile;
    actress *act;
    cover *cv;
};

#endif // FILM_H
