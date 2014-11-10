#ifndef MONGODBSVC_H
#define MONGODBSVC_H

#include "SniperKernel/SvcBase.h"
#include <string>
#include"MongoJson/src/MongoDB.h>"
namespace mongo {
    class DBClientConnection;
}


class DatabaseSvc : public SvcBase {

    public:
        DatabaseSvc(const std::string& name);
        ~DatabaseSvc();
        MyMongoDB::QueryResult query();
        MyMongoDB::QueryResult query(const QueryString& qs);

        bool initialize();
        bool finalize();

     private:
        std::string m_hostname;
        std::string m_dbname;
        mongo::DBClientConnection* m_conn;
 };

#endif 


