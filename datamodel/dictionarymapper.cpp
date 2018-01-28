// 
 // C++ Implementation: dictionarymapper
 //
 // Description: 
 //
 //
 // Author: Marcus Dirks <mopp@suse>, (C) 2005
 //
 // Copyright: See COPYING file that comes with this distribution
 //
 //
 #include "dictionarymapper.h"
 #include <utils/utils.h>
 #include "dictionary.h"
#include <persistence/database.h>
 #include <repository/urlproperty.h>
 #include <mapping/mappingcontroler.h>

 dictionarymapper* dictionarymapper::instance=0;
 
 dictionarymapper* dictionarymapper::getInstance()
 {
 	if(!instance){
 		instance=new dictionarymapper();
 	}
 	return instance;
 }


 dictionarymapper::dictionarymapper()
  {
 	version = "0.1";
	columns = new string[0];
 	columnTypes = new string[0];
 asc_Entries = new Association<dictionary, dicentry>("dic_entries","dic_id","entry_id","dicentry", &dictionary::addToEntries, &dictionary::deleteFromEntries);
mapAssociations["Entries"] = asc_Entries;
registerAssociation( asc_Entries);


MappingControler::getInstance()->registerPersistentClass(this);
Repository::getInstance()->addRepositoryEntry(getRepositoryEntry());
}


dictionarymapper::~dictionarymapper(){}


 PObject* dictionarymapper::createNewObject()
 {
     return new dictionary();
 }


 dictionary* dictionarymapper::create()
 {
     return  (dictionary*) AbstractMapper::create( dictionarymapper::getInstance() );
 }


 string dictionarymapper::getTableName()
 {
     return string("dictionary");
 }
 
 string dictionarymapper::getClassName()
 {
 	return string("dictionary");
 }
 
 string* dictionarymapper::getColumnTypes()
 {
 	return columnTypes;
 }
 
 string* dictionarymapper::getColumns()
 {
 	return columns;
 }
 
 int dictionarymapper::getColumnCount()
 {
     return 0;
 }


 string* dictionarymapper::getValues(PObject *realSubject)
 {
 	string *values = new string[0];  
 	dictionary *o = (dictionary*) realSubject;
return values;
 }


 void dictionarymapper::save(){
qWarning("dictionary: save() not implemented");
}

void dictionarymapper::save(PObject *realSubject)
{
 	dictionary *o = (dictionary*) realSubject;

    Database *db = Database::getInstance();
    db->save(realSubject);
	asc_Entries -> save(realSubject, o->getEntries() );

}


void dictionarymapper::init(PObject* inito, Variant *res)
 {
 	dictionary *o = (dictionary*) inito;
	inito->init();
}


 list<dictionary *>*dictionarymapper::find() 
 {
 	return (list <dictionary*>*) Database::getInstance()->getAll(this); 
}


list<dicentry*> * dictionarymapper::findEntries(int pri_id) 
 { 
 	return asc_Entries ->  findAssociates( pri_id );
     }


list<dicentry*> * dictionarymapper::findEntries(int pri_id,string prop,string value) 
         { 
             return asc_Entries ->  findAssociates( pri_id,prop,value);
             }


RepositoryEntry* dictionarymapper::getRepositoryEntry()
 	{
 	RepositoryEntry* entry = new RepositoryEntryImpl( "dictionary" ); 
	entry->addProperty( new StringProperty<dictionary>("Name", "string", &dictionary::getName, &dictionary::setName, false) );
	entry->addProperty( new CollectionPropertyImpl<dicentry,dictionary>( "Entries" , "dicentry", &dictionary::getEntries, &dictionary::addToEntries, &dictionary::deleteFromEntries  ) ); 
	return entry;
 }
