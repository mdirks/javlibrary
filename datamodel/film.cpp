#include "film.h"
#include "filmmapper.h"

film::film()
{
    act=0;
    cv=0;

    setMapper(filmmapper::getInstance());
}


string film::getTitle()
{
    return title;
}

void film::setTitle(string t)
{
    title=t;
}

string film::getCode()
{
    return code;
}

void film::setCode(string c)
{
    code=c;
    setName(code);
}

string film::getCoverFile()
{
    return coverFile;
}

void film::setCoverFile(string cf)
{
    coverFile=cf;
}


void film::setCover(cover *c)
{
    this->cv=c;
}

cover *film::getCover()
{
    if(!cv){
        cv=(cover*) filmmapper::getInstance()->findReference("Cover",getID());
    }
    return cv;
}

string film::getMovieFile()
{
    return movieFile;
}

void film::setMovieFile(string mf)
{
    movieFile=mf;
}


actress* film::getActress()
{
    if(act==0){
        act= (actress*) filmmapper::getInstance()->findReference("Actress",getID());
    }
    return act;
}

void film::setActress(actress *a)
{
    act=a;
}
