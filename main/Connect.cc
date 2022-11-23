/*
 * Connect.cpp
 *
 *  Created on: Dec 1, 2010
 *      Author: raluca
 */

#include <stdexcept>
#include <assert.h>
#include <string>
#include <iostream>
#include <sstream>
#include <memory>
#include<iostream>
#include <main/Connect.hh>
#include <parser/sql_utils.hh>
#include <main/macro_util.hh>
#include <util/cryptdb_log.hh>
#include <main/schema.hh>
#include </usr/include/postgresql/libpq-fe.h>
using namespace std;

Connect::Connect(const std::string &server, const std::string &user,
                 const std::string &passwd, uint port)
    : conn(nullptr), close_on_destroy(true)
{
    do_connect(server, user, passwd, port);
}
static void
exit_nicely(PGconn *conn)
{
    PQfinish(conn);
    exit(1);
}
void
Connect::do_connect(const std::string &server, const std::string &user,
                    const std::string &passwd, uint port)
{
    // const char *dummy_argv[] = {
    //     "progname",
    //     "--skip-grant-tables",
    //     "--skip-innodb",
    //     "--default-storage-engine=MEMORY",
    //     "--character-set-server=utf8",
    //     "--language=" MYSQL_BUILD_DIR "/sql/share/"
    // };
    // assert(0 == mysql_library_init(sizeof(dummy_argv)/sizeof(*dummy_argv),
    //                                const_cast<char**>(dummy_argv), 0));
      const char *conninfo;
     conninfo = "host=127.0.0.1 port=5432 dbname=cryptdb user=postgres";
     conn = PQconnectdb(conninfo);
       if (PQstatus(conn) != CONNECTION_OK)
       {
        fprintf(stderr, "Connection to database failed: %s",
                PQerrorMessage(conn));
        exit_nicely(conn);//关闭连接并执行清理操作
       }
    /* Connect via TCP, and not via Unix domain sockets */
    // const uint proto = MYSQL_PROTOCOL_TCP;
    // mysql_options(conn, MYSQL_OPT_PROTOCOL, &proto);

    // /* Connect to real server even if linked against embedded libmysqld */
    // mysql_options(conn, MYSQL_OPT_USE_REMOTE_CONNECTION, 0);

    /* Connect to database */
    // if (!mysql_real_connect(conn, server.c_str(), user.c_str(),
    //                         passwd.c_str(), 0, port, 0,
    //                         CLIENT_MULTI_STATEMENTS)) {
    //     LOG(warn) << "connecting to server " << server
    //               << " user " << user
    //               << " pwd " << passwd
    //               << " port " << port;
    //     LOG(warn) << "mysql_real_connect: " << mysql_error(conn);
    //     throw std::runtime_error("cannot connect");
    // }
}

Connect *Connect::getEmbedded(const std::string &embed_db)
{
    // init_mysql(embed_db);
    PGconn  *m;
    // PGconn *const m=PQconnectdbParams(0,0,0);
    // assert(m);

    // PQsetdbLogin(m, MYSQL_OPT_USE_EMBEDDED_CONNECTION, 0);
    const char *pghost="127.0.0.1";
    const char *pgport="5432";
    const char *pgoptions=" ";
    const char *pgtty=NULL;
    const char *pgname="embedded_db";
    const char *login="postgres";
    const char *pwd="letmein";
    m=PQsetdbLogin(pghost,pgport,pgoptions,pgtty,pgname,login,pwd);
     if (PQstatus(m) != CONNECTION_OK)
       {
        fprintf(stderr, "Connection to database failed: %s",
                PQerrorMessage(m));
        exit_nicely(m);//关闭连接并执行清理操作
       }
    Connect *const conn = new Connect(m);
    conn->close_on_destroy = true;
    return conn;
}

// @multiple_resultsets causes us to ignore query results.
// > This is a hack that allows us to deal with the two sets which
// are returned when CALLing a stored procedure.
bool
Connect::execute(const std::string &query, std::unique_ptr<DBResult> *res,
                 bool multiple_resultsets)
{
   
    std::cout<<query.c_str()<<"\n";
    if (query.length() == 0) {
        LOG(warn) << "empty query";
        res = nullptr;
        return true;
    }
    // *res =  std::unique_ptr<DBResult>(DBResult::wrap(PQexec(conn, query.c_str())));
    bool success = true;
    // if (!res) {
    //     LOG(warn) << "mysql_query: " << PQresultErrorMessage(*res-);
    //     LOG(warn) << "on query: " << query;
    //     res = nullptr;
    //     success = false;
    // } else {
        if (false == multiple_resultsets) {
            *res =
                std::unique_ptr<DBResult>(DBResult::wrap(PQexec(conn, query.c_str())));
        } else {
            int status;
            do {
                DBResult_native *const res_native =
                   PQexec(conn, query.c_str());
                if (res_native) {
                    PQclear(res_native);
                } else {
                    assert(PQnfields(res_native) == 0);
                }
                PGresult* sta = PQexec(conn,query.c_str());
                 if (PQresultStatus(sta) != PGRES_TUPLES_OK)
                 status =-1;
                assert(status <= 0);
            } while (0 == status);

            res = nullptr;
        }
    
    PQexec(conn, "COMMIT;");
     std::cout<<PQdb(conn)<<"\n";
    return success;
  
}


bool
Connect::execute(const std::string &query, bool multiple_resultsets)
{
    std::unique_ptr<DBResult> aux;
    const bool r = execute(query, &aux, multiple_resultsets);
    return r;
}

std::string
Connect::getError()
{
    return PQerrorMessage(conn);
}

my_ulonglong
Connect::last_insert_id()
{
    char sql[]="return lastval();";
    const PGresult* res=PQexec(conn,sql);
    return PQoidValue(res);
}

unsigned long
Connect::real_escape_string(char *const to, const char *const from,
                            unsigned long length)
{
    int error[10];
    return PQescapeStringConn(conn, to, from, length,error);
}

// std::string
// Connect::get_mysql_errno()
// {
//     return PQerrorMessage(conn);
// }

Connect::~Connect()
{
    if (close_on_destroy) {
       exit_nicely(conn);
    }
}

DBResult::DBResult()
{}

DBResult *
DBResult::wrap(DBResult_native *const n)
{
    DBResult *const r = new DBResult();
    r->n = n;
    return r;
}

DBResult::~DBResult()
{
    PQclear(n);
}
static new_Item  
getItems(char *const context, enum_pg_types type, uint len)
{
    struct new_Item  itema={.context=context,.type=type,.len=len};
    return itema;
}
   
static Item *
getItem(char *const content, enum_pg_types type, uint len)
{
    if (content == NULL) {
        return new Item_null();
    }
    const std::string content_str = std::string(content, len);
    if (IsMySQLTypeNumerics(type)) {
        const ulonglong val = valFromStr(content_str);
        return new Item_int(val);
    } else {
        return new (current_thd->mem_root) Item_string(make_thd_string(content_str), len,
                               &my_charset_bin);
    }
}
ResType trans_re(new_ResType &dres)
{
    const unsigned int rows = dres.rows.size();
    LOG(cdb_v) << "rows in result " << rows << "\n";
    const unsigned int cols = dres.names.size();

    ResType dbres;
    for(int i=0;i<rows;i++)
    {
        dbres.names.push_back(dres.names[i]);
        dbres.types.push_back(dres.types[i]);
    }
    for(int i=0;i<rows;i++)
    { 
        std::vector<std::shared_ptr<Item>> resows;
        for(int j=0;j<cols;j++)
        {
            if(IsMySQLTypeNumerics(dres.types[i]))
            {
               const ulonglong p=valFromStr(dres.rows[i][j].context);
               Item* re=new (current_thd->mem_root)Item_int(static_cast<ulonglong>(p));
               resows.push_back(std::shared_ptr<Item>(re));
            }
            else 
            {
                std::string dec=dres.rows[i][j].context;
                 Item* re= new (current_thd->mem_root) Item_string(make_thd_string(dec),
                                                   dec.length(),
                                                   &my_charset_bin);
                 resows.push_back(std::shared_ptr<Item>(re));
            }
        }
      dbres.rows.push_back(resows);
    }
    return dbres;
}
// > returns the data in the last server response
// > TODO: to optimize return pointer to avoid overcopying large
//   result sets?
// > This function must not return pointers (internal or otherwise) to
//   objects that it owns.
//   > ie, We must be able to delete 'this' without mangling the 'ResType'
//     returned from this->unpack(...).

enum_pg_types DBResult::enum_type(int id)
{
    switch (id)
    {
    case 20:return BIGINT;
        /* code */
    case 25:return TEXT;
    
    default:
        return ERROR;
    }
}
ResType
DBResult::new_unpack()
{
    if (nullptr == n) {
        return ResType();
    }

    const size_t rows = static_cast<size_t>(PQntuples(n));
    if (0 == rows) {
        return ResType();
    }

    const int cols = PQnfields(n);

    new_ResType res;
    
    for (int j = 0;j<cols; j++) {
        // MYSQL_FIELD *const field = mysql_fetch_field(n);
        // if (!field) {
        //     break;
        // }
        res.names.push_back(PQfname(n,j));
        std::cout<<PQfname(n,j)<<"\n";
        std::cout<<PQftype(n,j)<<"\n";
        enum_pg_types ty=enum_type(PQftype(n,j));
        res.types.push_back(ty);
    }

    for (size_t index = 0;index<rows; index++) {
        // MYSQL_ROW row = mysql_fetch_row(n);
        // if (!row) {
        //     break;
        // }
        // unsigned long *const lengths = mysql_fetch_lengths(n);

        std::vector<new_Item> resrow;
       
        for (int j = 0; j < cols; j++) {
            std::cout<<PQgetvalue(n,index,j)<<"\n";
            new_Item  itema = getItems(PQgetvalue(n,index,j),res.types[j], PQgetlength(n,index,j));
            resrow.push_back(itema);
        }

        res.rows.push_back(resrow);
    }
    const ResType &dbres =ResType(trans_re(res));

    return dbres;
}
ResType
DBResult::unpack()
{
    if (nullptr == n) {
        return ResType();
    }

    const size_t rows = static_cast<size_t>(PQntuples(n));
    if (0 == rows) {
        return ResType();
    }

    const int cols = PQnfields(n);

    ResType res;

    for (int j = 0;; j++) {
        // MYSQL_FIELD *const field = mysql_fetch_field(n);
        // if (!field) {
        //     break;
        // }
        res.names.push_back(PQfname(n,j));
        res.types.push_back(enum_type(PQftype(n,j)));
    }

    for (int index = 0;; index++) {
        // MYSQL_ROW row = mysql_fetch_row(n);
        // if (!row) {
        //     break;
        // }
        // unsigned long *const lengths = mysql_fetch_lengths(n);

        std::vector<std::shared_ptr<Item> > resrow;
       
        for (int j = 0; j < cols; j++) {
            Item *const item = getItem(PQgetvalue(n,index,j),res.types[j], PQgetlength(n,index,j));
            resrow.push_back(std::shared_ptr<Item>(item));
        }

        res.rows.push_back(resrow);
    }

    return res;
}
