// 
 // C++ Implementation: covermapper
 //
 // Description: 
 //
 //
 // Author: Marcus Dirks <mopp@suse>, (C) 2005
 //
 // Copyright: See COPYING file that comes with this distribution
 //
 //
 #include "covermapper.h"
 #include <utils/utils.h>
 #include "cover.h"
#include <persistence/database.h>
 #include <repository/urlproperty.h>
 #include <mapping/mappingcontroler.h>

 covermapper* covermapper::instance=0;
 
 covermapper* covermapper::getInstance()
 {
 	if(!instance){
 		instance=new covermapper();
 	}
 	return instance;
 }


 covermapper::covermapper()
  {
 	version = "0.1";
	columns = new string[1];
 	columnTypes = new string[1];
 	columns[0] = "fname";
 	columnTypes[0] = "varchar(60)";
	mapProperties["fname"] = new Property("fname");


MappingControler::getInstance()->registerPersistentClass(this);
Repository::getInstance()->addRepositoryEntry(getRepositoryEntry());
}


covermapper::~covermapper(){}


 PObject* covermapper::createNewObject()
 {
     return new cover();
 }


 cover* covermapper::create()
 {
     return  (cover*) AbstractMapper::create( covermapper::getInstance() );
 }


 string covermapper::getTableName()
 {
     return string("cover");
 }
 
 string covermapper::getClassName()
 {
 	return string("cover");
 }
 
 string* covermapper::getColumnTypes()
 {
 	return columnTypes;
 }
 
 string* covermapper::getColumns()
 {
 	return columns;
 }
 
 int covermapper::getColumnCount()
 {
     return 1;
 }


 string* covermapper::getValues(PObject *realSubject)
 {
 	string *values = new string[1];  
 	cover *o = (cover*) realSubject;
	values[0] = to_string(o->getFileName());
return values;
 }


 void covermapper::save(){
qWarning("cover: save() not implemented");
}

void covermapper::save(PObject *realSubject)
{
 	cover *o = (cover*) realSubject;

    Database *db = Database::getInstance();
    db->save(realSubject);
}


void covermapper::init(PObject* inito, Variant *res)
 {
 	cover *o = (cover*) inito;
	o->setFileName( res[0].asstring());
 	inito->init();
}


 list<cover *>*covermapper::find() 
 {
 	return (list <cover*>*) Database::getInstance()->getAll(this); 
}


RepositoryEntry* covermapper::getRepositoryEntry()
 	{
 	RepositoryEntry* entry = new RepositoryEntryImpl( "cover" ); 
	entry->addProperty( new StringProperty<cover>("Name", "string", &cover::getName, &cover::setName, false) );
	entry->addProperty( new StringProperty< cover >( "FileName" , "string", &cover::getFileName, &cover::setFileName, false ) );
	return entry;
 }
