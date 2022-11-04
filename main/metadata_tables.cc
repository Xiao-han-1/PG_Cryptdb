#include <string>
#include <memory>

#include <main/metadata_tables.hh>
#include <main/Connect.hh>
#include <main/macro_util.hh>

std::string
MetaData::Table::metaObject()
{
    return  Internal::getPrefix() + "metaObject";
}

std::string
MetaData::Table::bleedingMetaObject()
{
    return Internal::getPrefix() +
           "bleedingmetaobject";
}

std::string
MetaData::Table::embeddedQueryCompletion()
{
    return  Internal::getPrefix() +
           "embeddedQueryCompletion";
}

std::string
MetaData::Table::staleness()
{
    return  Internal::getPrefix() +
           "staleness";
}

std::string
MetaData::Table::remoteQueryCompletion()
{
    return  Internal::getPrefix() +
           "remotequerycompletion";
}

std::string
MetaData::Proc::currentTransactionID()
{
    return  Internal::getPrefix() +
           "currenttransactionID";
}

std::string
MetaData::Proc::homAdditionTransaction()
{
    return  Internal::getPrefix() +
           "homAdditiontransaction";
}

std::string
MetaData::Proc::adjustOnion()
{
    return  Internal::getPrefix() + "adjustOnion";
}

std::string
MetaData::DB::embeddedDB()
{
    static const std::string name = "embedded_db";
    return name;
}

std::string
MetaData::DB::remoteDB()
{
    static const std::string name = "remote_db";
    return name;
}

bool static
hasWhitespace(const std::string &s)
{
    for (auto it : s) {
        if (isspace(it)) {
            return true;
        }
    }

    return false;
}

bool
MetaData::initialize(const std::unique_ptr<Connect> &conn,
                     const std::unique_ptr<Connect> &e_conn,
                     const std::string &prefix)
{
    // HACK: prevents multiple initialization
    static bool initialized = false;
    if (initialized) {
        return false;
    }

    // Prefix handling must be done first.
    if (hasWhitespace(prefix)) {
        return false;
    }
    MetaData::Internal::initPrefix(prefix);
    //  std::string drop_db;
    //      drop_db =
    //     " DROP DATABASE  " + DB::embeddedDB() + ";";
    // RETURN_FALSE_IF_FALSE(e_conn->execute(drop_db));
    // Embedded database.
    const std::string create_db =
        " CREATE DATABASE  " + DB::embeddedDB() + ";";
    RETURN_FALSE_IF_FALSE(e_conn->execute(create_db));
    const std::string use_db =
        "\\c " + DB::embeddedDB() + ";";
    RETURN_FALSE_IF_FALSE(e_conn->execute(use_db));
    const std::string create_meta_table =
        " CREATE TABLE IF NOT EXISTS " + Table::metaObject() +
        "   (serial_object varchar NOT NULL,"
        "    serial_key varchar NOT NULL,"
        "    parent_id BIGINT NOT NULL,"
        "    id SERIAL PRIMARY KEY);";
    RETURN_FALSE_IF_FALSE(e_conn->execute(create_meta_table));

    const std::string create_bleeding_table =
        " CREATE TABLE IF NOT EXISTS " + Table::bleedingMetaObject() +
        "   (serial_object varchar NOT NULL,"
        "    serial_key varchar NOT NULL,"
        "    parent_id BIGINT NOT NULL,"
        "    id SERIAL PRIMARY KEY);";
    RETURN_FALSE_IF_FALSE(e_conn->execute(create_bleeding_table));

    const std::string create_embedded_completion =
        " CREATE TABLE IF NOT EXISTS " + Table::embeddedQueryCompletion() +
        "   (begin BOOLEAN NOT NULL,"
        "    complete BOOLEAN NOT NULL,"
        "    original_query VARCHAR(500) NOT NULL,"
        "    default_db VARCHAR(500),"      // default database is NULLable
        "    aborted BOOLEAN NOT NULL,"
        "    type VARCHAR(100) NOT NULL,"
        "    id SERIAL PRIMARY KEY);";
    RETURN_FALSE_IF_FALSE(e_conn->execute(create_embedded_completion));

    const std::string create_staleness =
        " CREATE TABLE IF NOT EXISTS " + Table::staleness() +
        "   (cache_id BIGINT UNIQUE NOT NULL,"
        "    stale BOOLEAN NOT NULL,"
        "    id SERIAL PRIMARY KEY);";
    RETURN_FALSE_IF_FALSE(e_conn->execute(create_staleness));

    // Remote database.
    // const std::string create_remote_db =
    //     " CREATE DATABASE  " + DB::remoteDB() + ";";
    // RETURN_FALSE_IF_FALSE(conn->execute(create_remote_db));
    //     const std::string use_re_db =
    //     "USE " + DB::remoteDB() + ";";
    // RETURN_FALSE_IF_FALSE(e_conn->execute(use_re_db));
    const std::string create_remote_completion =
        " CREATE TABLE IF NOT EXISTS " + Table::remoteQueryCompletion() +
        "   (begin BOOLEAN NOT NULL,"
        "    complete BOOLEAN NOT NULL,"
        "    embedded_completion_id INTEGER NOT NULL,"
        "    reissue BOOLEAN NOT NULL,"
        "    id SERIAL PRIMARY KEY);";
    RETURN_FALSE_IF_FALSE(e_conn->execute(create_remote_completion));

    initialized = true;
    return true;
}

void
MetaData::Internal::initPrefix(const std::string &s)
{
    lowLevelPrefix(s.c_str());
}

const std::string &
MetaData::Internal::getPrefix()
{
    return lowLevelPrefix(NULL);
}

const std::string &
MetaData::Internal::lowLevelPrefix(const char *const p)
{
    static const std::string prefix = (assert(p), p);
    return prefix;
}

