// 
 // C++ Implementation: actressmapper
 //
 // Description: 
 //
 //
 // Author: Marcus Dirks <mopp@suse>, (C) 2005
 //
 // Copyright: See COPYING file that comes with this distribution
 //
 //
 #include "actressmapper.h"
 #include <utils/utils.h>
 #include "actress.h"
#include <persistence/database.h>
 #include <repository/urlproperty.h>
 #include <mapping/mappingcontroler.h>

 actressmapper* actressmapper::instance=0;
 
 actressmapper* actressmapper::getInstance()
 {
 	if(!instance){
 		instance=new actressmapper();
 	}
 	return instance;
 }


 actressmapper::actressmapper()
  {
 	version = "0.1";
	columns = new string[2];
 	columnTypes = new string[2];
 	columns[0] = "vname";
 	columnTypes[0] = "varchar(15)";
	mapProperties["vname"] = new Property("vname");
	columns[1] = "nname";
 	columnTypes[1] = "varchar(15)";
	mapProperties["nname"] = new Property("nname");
asc_Filme = new Association<actress, film>("actress_filme","actress_id","film_id","film", &actress::addToFilme, &actress::deleteFromFilme);
mapAssociations["Filme"] = asc_Filme;
registerAssociation( asc_Filme);


MappingControler::getInstance()->registerPersistentClass(this);
Repository::getInstance()->addRepositoryEntry(getRepositoryEntry());
}


actressmapper::~actressmapper(){}


 PObject* actressmapper::createNewObject()
 {
     return new actress();
 }


 actress* actressmapper::create()
 {
     return  (actress*) AbstractMapper::create( actressmapper::getInstance() );
 }


 string actressmapper::getTableName()
 {
     return string("actress");
 }
 
 string actressmapper::getClassName()
 {
 	return string("actress");
 }
 
 string* actressmapper::getColumnTypes()
 {
 	return columnTypes;
 }
 
 string* actressmapper::getColumns()
 {
 	return columns;
 }
 
 int actressmapper::getColumnCount()
 {
     return 2;
 }


 string* actressmapper::getValues(PObject *realSubject)
 {
 	string *values = new string[2];  
 	actress *o = (actress*) realSubject;
	values[0] = to_string(o->getVorname());
	values[1] = to_string(o->getNachname());
return values;
 }


 void actressmapper::save(){
qWarning("actress: save() not implemented");
}

void actressmapper::save(PObject *realSubject)
{
 	actress *o = (actress*) realSubject;

    Database *db = Database::getInstance();
    db->save(realSubject);
	asc_Filme -> save(realSubject, o->getFilme() );

}


void actressmapper::init(PObject* inito, Variant *res)
 {
 	actress *o = (actress*) inito;
	o->setVorname( res[0].asstring());
 	o->setNachname( res[1].asstring());
 	inito->init();
}


 list<actress *>*actressmapper::find() 
 {
 	return (list <actress*>*) Database::getInstance()->getAll(this); 
}


list<film*> * actressmapper::findFilme(int pri_id) 
 { 
 	return asc_Filme ->  findAssociates( pri_id );
     }


list<film*> * actressmapper::findFilme(int pri_id,string prop,string value) 
         { 
             return asc_Filme ->  findAssociates( pri_id,prop,value);
             }


RepositoryEntry* actressmapper::getRepositoryEntry()
 	{
 	RepositoryEntry* entry = new RepositoryEntryImpl( "actress" ); 
	entry->addProperty( new StringProperty<actress>("Name", "string", &actress::getName, &actress::setName, false) );
	entry->addProperty( new StringProperty< actress >( "Vorname" , "string", &actress::getVorname, &actress::setVorname, false ) );
	entry->addProperty( new StringProperty< actress >( "Nachname" , "string", &actress::getNachname, &actress::setNachname, false ) );
	entry->addProperty( new CollectionPropertyImpl<film,actress>( "Filme" , "film", &actress::getFilme, &actress::addToFilme, &actress::deleteFromFilme  ) ); 
	return entry;
 }
