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
 #ifndef filmMAPPER_H 
 #define filmMAPPER_H 
 
 #include <persistence/pobject.h> 
 #include <mapping/mappedobject.h> 
#include <mapping/association.h> 
#include <mapping/murl.h> 
#include <persistence/persistenceclass.h> 
 #include "film.h" 
#include "actress.h" 
#include "cover.h" 
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
 class filmmapper : public AbstractMapper, public RepositoryEnabled
{
 public:
     static filmmapper* getInstance();
     ~filmmapper();
     static film* create();

     string getTableName();
     string getClassName();
     string* getColumnTypes();
     string* getColumns();
     string* getValues(PObject* realSubject);
     int getColumnCount();
     void save();
     void save(PObject *realSubject);
     PObject* createNewObject();
     list<film*>* find();
    void init(PObject* o, Variant* res);
    RepositoryEntry *getRepositoryEntry();

actress * findActress(int pri_id);
cover * findCover(int pri_id);

protected:
     filmmapper();
 
 private:
    static filmmapper* instance;
 

   string *columnTypes;
    string *columns;
   
 
 };
 
 #endif
 