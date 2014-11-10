#ifndef MONGODBSVC_H
#define MONGODBSVC_H

#include "SniperKernel/SvcBase.h"
#include <string>

class DatabaseSvc : public SvcBase {

    public:
        DatabaseSvc(const std::string& name);
        ~DatabaseSvc();
        MyMongoQuery::QueryResult query();
        MyMongoQuery::QueryResult query(const QueryString& qs);

        bool initialize();
        bool finalize();

     private:
        std::string m_hostname;
        std::string m_dbname;
 };



