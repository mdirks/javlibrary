#include "dictionary.h"
#include "dictionarymapper.h"
#include "dicentrymapper.h"
#include "transactions/transactions.h"

dictionary::dictionary()
{
    list_entries=0;
    setMapper(dictionarymapper::getInstance());
}


list<dicentry*> *dictionary::getEntries()
{
    if(list_entries==0){
        list_entries = dictionarymapper::getInstance()->findEntries(getID());
        load();
    }
    return list_entries;
}

void dictionary::addToEntries(dicentry *de)
{
    getEntries()->push_back(de);
    germtojap[getGKey(de)]=de;
    japtogerm[getJKey(de)]=de;
}

void dictionary::deleteFromEntries(dicentry *de)
{
    getEntries()->remove(de);
    germtojap[getGKey(de)]=0;
    japtogerm[getJKey(de)]=0;
}

void dictionary::load()
{
    for(list<dicentry*>::iterator it=list_entries->begin(); it!=list_entries->end(); it++){
        dicentry *de=(*it);
        germtojap[getGKey(de)]=de;
        japtogerm[getJKey(de)]=de;
    }

}


void dictionary::addEntry(string vn, string nn, string jn)
{
    dicentry *de=0;
    if((de=find(vn,nn)) != 0){
        de->setJapanese(jn);
    } else if((de=find(jn)) != 0){
        de->setVorname(vn);
        de->setNachname(nn);
    } else {
        de = dicentrymapper::getInstance()->create();
        de->setVorname(vn);
        de->setNachname(nn);
        de->setJapanese(jn);
    }
    Transactions::getCurrentTransaction()->add(de);
    addToEntries(de);

}


dicentry* dictionary::find(string vn, string nn)
{
    map<string,dicentry*>::iterator it = germtojap.find(getGKey(vn,nn));
    if(it != germtojap.end()){
        dicentry* de = it->second;
        if(de){
            return de;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

dicentry* dictionary::find(string jn)
{
    map<string,dicentry*>::iterator it = japtogerm.find(jn);
    if(it != japtogerm.end()){
        dicentry* de = it->second;
        if(de){
            return de;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

string dictionary::getGKey(string vn,string nn)
{
        return vn+"-"+nn;
}

string dictionary::getGKey(dicentry *de)
{
        return getGKey(de->getVorname(),de->getNachname());
}

string dictionary::getJKey(dicentry *de)
{
    return de->getJapanese();
}


