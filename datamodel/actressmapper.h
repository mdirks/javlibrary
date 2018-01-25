 //  
 // C++ Interface: stundepersistence 
 //   
 // Description:  
 // 
 // 
 // Author: Marcus Dirks <mopp@suse>, (C) 2005 
 //  
 // Copyright: See COPYING file that comes with this distribution 
 // 
 // Written on Mi. Jan. 24 19:06:01 2018
// 
 #ifndef actressMAPPER_H 
 #define actressMAPPER_H 
 
 #include <persistence/pobject.h> 
 #include <mapping/mappedobject.h> 
#include <mapping/association.h> 
#include <mapping/murl.h> 
#include <persistence/persistenceclass.h> 
 #include "actress.h" 
#include "film.h" 
#include <mapping/abstractmapper.h>
 #include <persistence/variant.h>
 #include <repository/repositoryentryimpl.h>
 #include <repository/stringproperty.h>
 #include <repository/integerproperty.h>
 #include <repository/pobjectproperty.h>
 #include <repository/collectionpropertyimpl.h>
 #include <repository/numericproperty.h>
 #include <repository/dateproperty.h>
 #include <repository/booleanproperty.h>
 #include <repository/datetimeproperty.h>
 #include <repository/repositoryenabled.h>
 
 /** 
 @author Marcus Dirks 
 */ 
 class actressmapper : public AbstractMapper, public RepositoryEnabled
{
 public:
     static actressmapper* getInstance();
     ~actressmapper();
     static actress* create();

     string getTableName();
     string getClassName();
     string* getColumnTypes();
     string* getColumns();
     string* getValues(PObject* realSubject);
     int getColumnCount();
     void save();
     void save(PObject *realSubject);
     PObject* createNewObject();
     list<actress*>* find();
    void init(PObject* o, Variant* res);
    RepositoryEntry *getRepositoryEntry();

  list<film*> * findFilme(int pri_id);
  list<film*> * findFilme(int pri_id,string prop,string value);

protected:
     actressmapper();
 
 private:
    static actressmapper* instance;
 

   string *columnTypes;
    string *columns;
  Association<actress, film> *asc_Filme;
  
 
 };
 
 #endif
 