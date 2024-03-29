#ifndef src_MongoDB_h
#define src_MongoDB_h

#include <DB/IQuery.h>

namespace mongo {
    class DBClientConnection;
}

class MyMongoDBQuery: public IQuery {
public:
    MyMongoDBQuery();
    ~MyMongoDBQuery();

    QueryResult query(const QueryString& qs);

private:

    std::string m_hostname;
    std::string m_dbname;
    mongo::DBClientConnection* m_conn;

};

#endif
