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
 #ifndef dictionaryMAPPER_H 
 #define dictionaryMAPPER_H 
 
 #include <persistence/pobject.h> 
 #include <mapping/mappedobject.h> 
#include <mapping/association.h> 
#include <mapping/murl.h> 
#include <persistence/persistenceclass.h> 
 #include "dictionary.h" 
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
 class dictionarymapper : public AbstractMapper, public RepositoryEnabled
{
 public:
     static dictionarymapper* getInstance();
     ~dictionarymapper();
     static dictionary* create();

     string getTableName();
     string getClassName();
     string* getColumnTypes();
     string* getColumns();
     string* getValues(PObject* realSubject);
     int getColumnCount();
     void save();
     void save(PObject *realSubject);
     PObject* createNewObject();
     list<dictionary*>* find();
    void init(PObject* o, Variant* res);
    RepositoryEntry *getRepositoryEntry();

  list<dicentry*> * findEntries(int pri_id);
  list<dicentry*> * findEntries(int pri_id,string prop,string value);

protected:
     dictionarymapper();
 
 private:
    static dictionarymapper* instance;
 

   string *columnTypes;
    string *columns;
  Association<dictionary, dicentry> *asc_Entries;
  
 
 };
 
 #endif
 