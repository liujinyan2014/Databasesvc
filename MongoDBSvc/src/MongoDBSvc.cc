#include "MongoBDSvc/MongoDBSvc.h"
#include "SniperKernel/SvcFactory.h"
#include "SniperKernel/SniperLog.h"

#include "mongo/client/dbclient.h" // for the driver
#include "DatabaseSvc/MongoJson/MongoDB.h"

#include <iostream>
#include <cstdlib>

#include <algorithm>
using namespace std;

DECLARE_SERVICE(MongoDBSvc);

DatabaseSvc::DatabaseSvc(const std::string& name)
: SvcBase(name)
{
    declProp("querystr", qs);
    declProp("host",m_hostname)
    declProp("name",m_dbname)

}

MongoDBSvc::~MongoDBSvc()
{
if  (MongoDB)
  delete MongoDB;
}


bool
MongoDBSvc::initialize()
{
    LogDebug << "Initialize the DATABASE="
        << m_conn(0)
        << std::endl;
if(m_conn(0))
 {
    c = new MongoDBQuery;

    c->connect(m_hostname);

    m_dbname = "mydb.testData";
}
catch ( std::exception &e ) {
 
     LogDebug << "Exception in DataSvc initialization:" <<std::endl;
     LogDebug << "***  error message: " << e.what()<<std::endl;
    return 1;
 
   } catch (char* mess) {
    LogDebug << "Exception DataSvc initialization caught: " << mess << std::endl;
    return 1;
   }
    catch (...) {
     LogDebug << "UNKNOWN exception in DataSvc session initialization caught" <<std::endl;
     return 1;
  }
    LogDebug << "DatabaseSvc initialized successfully" << std::endl;
     return 0;
      }
 }


    return true;
}



bool
MongoDBSvc::finalize()
{
if(m_conn()){
  m_conn->connect();}
    LogDebug << "MongoDBSvc finalized successfully"
             << std::endl;
    return true;
}

 DatabaseSvc::~DatabaseSvc()
{
   this->finalize();
 }
 
QueryResult MongoDBSvc::query(const QueryString& qs)
{
return MyMongoDB::QueryResult result;
}



