#include "actress.h"
#include "actressmapper.h"

actress::actress()
{
       list_filme = 0;
       setMapper(actressmapper::getInstance());
}

string actress::getVorname()
{
    return vname;
}

void actress::setVorname(string n)
{
    vname=n;
    setName(vname + " " + nname);
}

string actress::getNachname()
{
    return nname;
}

void actress::setNachname(string n)
{
    nname=n;
    setName(vname + " " + nname);
}

string actress::getJapaneseName()
{
    return jname;
}

void actress::setJapaneseName(string n)
{
    jname=n;
}


list<film*> *actress::getFilme()
{
    if(list_filme == 0){
        list_filme = actressmapper::getInstance()->findFilme(getID());
    }
    return list_filme;
}

void actress::addToFilme(film *f)
{
    getFilme()->push_back(f);
}

void actress::deleteFromFilme(film *f)
{
    getFilme()->remove(f);
}

string actress::getName()
{
    if(getJapaneseName()!=""){
        return getJapaneseName();
    } else {
        return PObject::getName();
    }

}
