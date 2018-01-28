#include "dicentry.h"
#include "dicentrymapper.h"

dicentry::dicentry()
{
    setMapper(dicentrymapper::getInstance());
}

void dicentry::setVorname(string n)
{
    vn=n;
}

string dicentry::getVorname()
{
    return vn;
}


void dicentry::setNachname(string n)
{
    nn=n;
}

string dicentry::getNachname()
{
    return nn;
}


void dicentry::setJapanese(string j)
{
    jn=j;
}

string dicentry::getJapanese()
{
    return jn;
}

