// 
 // C++ Implementation: filmmapper
 //
 // Description: 
 //
 //
 // Author: Marcus Dirks <mopp@suse>, (C) 2005
 //
 // Copyright: See COPYING file that comes with this distribution
 //
 //
 #include "filmmapper.h"
 #include <utils/utils.h>
 #include "film.h"
#include <persistence/database.h>
 #include <repository/urlproperty.h>
 #include <mapping/mappingcontroler.h>

 filmmapper* filmmapper::instance=0;
 
 filmmapper* filmmapper::getInstance()
 {
 	if(!instance){
 		instance=new filmmapper();
 	}
 	return instance;
 }


 filmmapper::filmmapper()
  {
 	version = "0.5";
	columns = new string[3];
 	columnTypes = new string[3];
 	columns[0] = "title";
 	columnTypes[0] = "varchar(25)";
	mapProperties["title"] = new Property("title");
	columns[1] = "code";
 	columnTypes[1] = "varchar(10)";
	mapProperties["code"] = new Property("code");
	columns[2] = "movie";
 	columnTypes[2] = "varchar(60)";
	mapProperties["movie"] = new Property("movie");
mapReferences["Actress"] = new Reference("film","actress");
mapReferences["Cover"] = new Reference("film","cover");


MappingControler::getInstance()->registerPersistentClass(this);
Repository::getInstance()->addRepositoryEntry(getRepositoryEntry());
}


filmmapper::~filmmapper(){}


 PObject* filmmapper::createNewObject()
 {
     return new film();
 }


 film* filmmapper::create()
 {
     return  (film*) AbstractMapper::create( filmmapper::getInstance() );
 }


 string filmmapper::getTableName()
 {
     return string("film");
 }
 
 string filmmapper::getClassName()
 {
 	return string("film");
 }
 
 string* filmmapper::getColumnTypes()
 {
 	return columnTypes;
 }
 
 string* filmmapper::getColumns()
 {
 	return columns;
 }
 
 int filmmapper::getColumnCount()
 {
     return 3;
 }


 string* filmmapper::getValues(PObject *realSubject)
 {
 	string *values = new string[3];  
 	film *o = (film*) realSubject;
	values[0] = to_string(o->getTitle());
	values[1] = to_string(o->getCode());
	values[2] = to_string(o->getMovieFile());
return values;
 }


 void filmmapper::save(){
qWarning("film: save() not implemented");
}

void filmmapper::save(PObject *realSubject)
{
 	film *o = (film*) realSubject;

    Database *db = Database::getInstance();
    db->save(realSubject);
	mapReferences[ "Actress" ] -> save(realSubject, (PObject*) o->getActress());
	mapReferences[ "Cover" ] -> save(realSubject, (PObject*) o->getCover());
}


void filmmapper::init(PObject* inito, Variant *res)
 {
 	film *o = (film*) inito;
	o->setTitle( res[0].asstring());
 	o->setCode( res[1].asstring());
 	o->setMovieFile( res[2].asstring());
 	inito->init();
}


 list<film *>*filmmapper::find() 
 {
 	return (list <film*>*) Database::getInstance()->getAll(this); 
}


RepositoryEntry* filmmapper::getRepositoryEntry()
 	{
 	RepositoryEntry* entry = new RepositoryEntryImpl( "film" ); 
	entry->addProperty( new StringProperty<film>("Name", "string", &film::getName, &film::setName, false) );
	entry->addProperty( new StringProperty< film >( "Title" , "string", &film::getTitle, &film::setTitle, false ) );
	entry->addProperty( new StringProperty< film >( "Code" , "string", &film::getCode, &film::setCode, false ) );
	entry->addProperty( new StringProperty< film >( "MovieFile" , "string", &film::getMovieFile, &film::setMovieFile, false ) );
	entry->addProperty( new PObjectProperty<actress,film>( "Actress" , "actress", &film::getActress,&film::setActress ) ); 
	entry->addProperty( new PObjectProperty<cover,film>( "Cover" , "cover", &film::getCover,&film::setCover ) ); 
	return entry;
 }
