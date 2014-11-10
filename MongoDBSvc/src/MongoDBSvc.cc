#include "DatabaseSvc/DatabaseSvc.h"
#include "SniperKernel/SvcFactory.h"
#include "SniperKernel/SniperLog.h"

#include "mongo/client/dbclient.h" // for the driver
#include "DatabaseSvc/MongoDB.h"

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
    m_conn = new mongo::DBClientConnection;

    m_conn->connect(m_hostname);

    m_dbname = "mydb.testData";
}
catch ( std::exception &e ) {
 
     log << MSG::FATAL << "Exception in DataSvc initialization:" << endreq;
     log << MSG::FATAL << "***  error message: " << e.what()<< endreq;
    return StatusCode::FAILURE;
 
   } catch (char* mess) {
    log << MSG::FATAL << "Exception DataSvc initialization caught: " << mess << endreq;
    return 1;
   }
    catch (...) {
     log << MSG::FATAL << "UNKNOWN exception in DataSvc session initialization caught" << endreq;
     return 1;
  }
   log << MSG::INFO << "DatabaseSvc initialized successfully" << endreq;
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



