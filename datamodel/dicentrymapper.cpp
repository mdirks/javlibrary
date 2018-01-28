// 
 // C++ Implementation: dicentrymapper
 //
 // Description: 
 //
 //
 // Author: Marcus Dirks <mopp@suse>, (C) 2005
 //
 // Copyright: See COPYING file that comes with this distribution
 //
 //
 #include "dicentrymapper.h"
 #include <utils/utils.h>
 #include "dicentry.h"
#include <persistence/database.h>
 #include <repository/urlproperty.h>
 #include <mapping/mappingcontroler.h>

 dicentrymapper* dicentrymapper::instance=0;
 
 dicentrymapper* dicentrymapper::getInstance()
 {
 	if(!instance){
 		instance=new dicentrymapper();
 	}
 	return instance;
 }


 dicentrymapper::dicentrymapper()
  {
 	version = "0.1";
	columns = new string[3];
 	columnTypes = new string[3];
 	columns[0] = "vname";
 	columnTypes[0] = "varchar(15)";
	mapProperties["vname"] = new Property("vname");
	columns[1] = "nname";
 	columnTypes[1] = "varchar(15)";
	mapProperties["nname"] = new Property("nname");
	columns[2] = "jname";
 	columnTypes[2] = "varchar(30)";
	mapProperties["jname"] = new Property("jname");


MappingControler::getInstance()->registerPersistentClass(this);
Repository::getInstance()->addRepositoryEntry(getRepositoryEntry());
}


dicentrymapper::~dicentrymapper(){}


 PObject* dicentrymapper::createNewObject()
 {
     return new dicentry();
 }


 dicentry* dicentrymapper::create()
 {
     return  (dicentry*) AbstractMapper::create( dicentrymapper::getInstance() );
 }


 string dicentrymapper::getTableName()
 {
     return string("dicentry");
 }
 
 string dicentrymapper::getClassName()
 {
 	return string("dicentry");
 }
 
 string* dicentrymapper::getColumnTypes()
 {
 	return columnTypes;
 }
 
 string* dicentrymapper::getColumns()
 {
 	return columns;
 }
 
 int dicentrymapper::getColumnCount()
 {
     return 3;
 }


 string* dicentrymapper::getValues(PObject *realSubject)
 {
 	string *values = new string[3];  
 	dicentry *o = (dicentry*) realSubject;
	values[0] = to_string(o->getVorname());
	values[1] = to_string(o->getNachname());
	values[2] = to_string(o->getJapanese());
return values;
 }


 void dicentrymapper::save(){
qWarning("dicentry: save() not implemented");
}

void dicentrymapper::save(PObject *realSubject)
{
 	dicentry *o = (dicentry*) realSubject;

    Database *db = Database::getInstance();
    db->save(realSubject);
}


void dicentrymapper::init(PObject* inito, Variant *res)
 {
 	dicentry *o = (dicentry*) inito;
	o->setVorname( res[0].asstring());
 	o->setNachname( res[1].asstring());
 	o->setJapanese( res[2].asstring());
 	inito->init();
}


 list<dicentry *>*dicentrymapper::find() 
 {
 	return (list <dicentry*>*) Database::getInstance()->getAll(this); 
}


RepositoryEntry* dicentrymapper::getRepositoryEntry()
 	{
 	RepositoryEntry* entry = new RepositoryEntryImpl( "dicentry" ); 
	entry->addProperty( new StringProperty<dicentry>("Name", "string", &dicentry::getName, &dicentry::setName, false) );
	entry->addProperty( new StringProperty< dicentry >( "Vorname" , "string", &dicentry::getVorname, &dicentry::setVorname, false ) );
	entry->addProperty( new StringProperty< dicentry >( "Nachname" , "string", &dicentry::getNachname, &dicentry::setNachname, false ) );
	entry->addProperty( new StringProperty< dicentry >( "Japanese" , "string", &dicentry::getJapanese, &dicentry::setJapanese, false ) );
	return entry;
 }
