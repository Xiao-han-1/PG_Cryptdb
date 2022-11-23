#pragma once

#include <util/util.hh>
#include <vector>
#include <string>
#include <memory>
#include <sql_select.h>
#include <sql_delete.h>
#include <sql_insert.h>
#include <sql_update.h>


typedef enum enum_pg_types {
  BIGINT=20, TEXT=25,ERROR=999
} enum_pg_types;
// must be called before we can use any MySQL AP
typedef struct new_Item {
  char *const context;
  enum_pg_types type;
   uint len;
} new_Item;
void
init_mysql(const std::string & embed_db);

class ResType {
public:
    bool ok;  // query executed successfully
    std::vector<std::string> names;
    std::vector<enum_pg_types> types;
    std::vector<std::vector<std::shared_ptr<Item> > > rows;

    explicit ResType(bool okflag = true) : ok(okflag) {}
    bool success() const {return this->ok;}
};
class new_ResType {
public:
    bool ok;  // query executed successfully
    std::vector<std::string> names;
    std::vector<enum_pg_types> types;
    std::vector<std::vector<new_Item > > rows;

    explicit new_ResType(bool okflag = true) : ok(okflag) {}
    bool success() const {return this->ok;}
};
bool isTableField(std::string token);
std::string fullName(std::string field, std::string name);

char * make_thd_string(const std::string &s, size_t *lenp = 0);

std::string ItemToString(const Item &i);
std::string ItemToStringWithQuotes(const Item &i);
