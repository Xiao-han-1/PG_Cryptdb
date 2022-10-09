assert(package.loadlib(os.getenv("EDBDIR").."/obj/libexecute.so",
                       "lua_cryptdb_init"))()

-- Interception points provided by mysqlproxy
--
local pg_proxy={
    src_name="MySQLProxy",
    address="127.0.0.1",
    port="5432" ,
    dbname="postgres",
    user="postgres",
    password="letmein",
    query="select * from postgres;"
}
local pgsql = require 'pgsql'
local conn = pgsql.connectdb('hostaddr=127.0.0.1 port=5432 dbname=postgres user=postgres password=letmein')
-- CryptDB.connect(pg_proxy.srcname,
--                 pg_proxy.address,
--                 pg_proxy.port,
--                     os.getenv("CRYPTDB_USER") or "postgres",
--                     os.getenv("CRYPTDB_PASS") or "letmein",
--                     os.getenv("CRYPTDB_SHADOW") or os.getenv("EDBDIR").."/shadow")

        status, error_msg, new_queries =
            CryptDB.rewrite(proxy.connection.client.src.name, query,
                            proxy.connection.server.thread_id)

    -- end
-- if false == status then
-- proxy.response.type = proxy.MYSQLD_PACKET_ERR
-- proxy.response.errmsg = error_msg
-- return proxy.PROXY_SEND_RESULT
-- end

-- if table.maxn(new_queries) == 0 then
-- proxy.response.type = proxy.MYSQLD_PACKET_OK
-- return proxy.PROXY_SEND_RESULT
-- end
