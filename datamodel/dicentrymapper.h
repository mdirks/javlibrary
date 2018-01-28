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
 // Written on So. Jan. 28 14:33:14 2018
// 
 #ifndef dicentryMAPPER_H 
 #define dicentryMAPPER_H 
 
 #include <persistence/pobject.h> 
 #include <mapping/mappedobject.h> 
#include <mapping/association.h> 
#include <mapping/murl.h> 
#include <persistence/persistenceclass.h> 
 #include "dicentry.h" 
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
 class dicentrymapper : public AbstractMapper, public RepositoryEnabled
{
 public:
     static dicentrymapper* getInstance();
     ~dicentrymapper();
     static dicentry* create();

     string getTableName();
     string getClassName();
     string* getColumnTypes();
     string* getColumns();
     string* getValues(PObject* realSubject);
     int getColumnCount();
     void save();
     void save(PObject *realSubject);
     PObject* createNewObject();
     list<dicentry*>* find();
    void init(PObject* o, Variant* res);
    RepositoryEntry *getRepositoryEntry();


protected:
     dicentrymapper();
 
 private:
    static dicentrymapper* instance;
 

   string *columnTypes;
    string *columns;
   
 
 };
 
 #endif
 