/*
 * Handling NULL value
 * - Encryption routines should never get a NULL value due to the way
 *   rewriting is handled for NULL.
 * - Decryption routines should forgo the decryption of NULL values.
 */

#define DEBUG 1

#include <memory>

#include </root/pakages/copy/cryptdb/crypto/BasicCrypto.hh>
#include </root/pakages/copy/cryptdb/crypto/blowfish.hh>
#include </root/pakages/copy/cryptdb/crypto/SWPSearch.hh>
#include </root/pakages/copy/cryptdb/crypto/paillier.hh>
#include </root/pakages/copy/cryptdb/util/params.hh>
#include </root/pakages/copy/cryptdb/util/util.hh>
#include </root/pakages/copy/cryptdb/util/version.hh>
#include <string.h>
#include <NTL/ZZ.h>
#include <ctype.h>
using namespace NTL;
extern "C"{
#include "/root/pakages/postgresql-10.0/src/include/postgres.h"
#include "/root/pakages/postgresql-10.0/src/include/fmgr.h"
#ifdef PG_MODULE_MAGIC

PG_MODULE_MAGIC;

#endif

PG_FUNCTION_INFO_V1(cryptdb_func_add_set);
PG_FUNCTION_INFO_V1(cryptdb_decrypt_int_det);
PG_FUNCTION_INFO_V1(cryptdb_decrypt_int_sem);
PG_FUNCTION_INFO_V1(cryptdb_decrypt_text_sem);
PG_FUNCTION_INFO_V1(cryptdb_decrypt_text_det);
PG_FUNCTION_INFO_V1(cryptdb_searchSWP);
PG_FUNCTION_INFO_V1(cryptdb_agg);
PG_FUNCTION_INFO_V1(cryptdb_version);

// CREATE FUNCTION cryptdb_decrypt_int_sem(bigint,cstring,bigint) 
// RETURNS bigint AS '/opt/pgsql/lib/pg_udf.so', 'cryptdb_decrypt_int_sem'  LANGUAGE C STRICT;
// CREATE FUNCTION cryptdb_func_add_set(cstring,cstring,cstring) 
// RETURNS cstring AS '/opt/pgsql/lib/pg_udf.so', 'cryptdb_func_add_set'  LANGUAGE C STRICT;
// CREATE FUNCTION cryptdb_decrypt_int_det(bigint,cstring,bigint) 
// RETURNS bigint AS '/opt/pgsql/lib/pg_udf.so', 'cryptdb_decrypt_int_det'  LANGUAGE C STRICT;
// CREATE FUNCTION cryptdb_decrypt_text_sem(cstring,cstring,bigint) 
// RETURNS bigint AS '/opt/pgsql/lib/pg_udf.so', 'cryptdb_decrypt_text_sem'  LANGUAGE C STRICT;
// CREATE FUNCTION cryptdb_decrypt_text_det(cstring,cstring) 
// RETURNS cstring AS '/opt/pgsql/lib/pg_udf.so', 'cryptdb_decrypt_text_det'  LANGUAGE C STRICT;
// CREATE FUNCTION cryptdb_searchSWP(cstring,cstring,cstring,cstring) 
// RETURNS bigint AS '/opt/pgsql/lib/pg_udf.so', 'cryptdb_searchSWP'  LANGUAGE C STRICT;
// CREATE FUNCTION cryptdb_agg(cstring,cstring) 
// RETURNS cstring AS '/opt/pgsql/lib/pg_udf.so', 'cryptdb_agg'  LANGUAGE C STRICT;
// CREATE FUNCTION cryptdb_version(void) 
// RETURNS cstring AS '/opt/pgsql/lib/pg_udf.so', 'cryptdb_version'  LANGUAGE C STRICT
}

static void __attribute__((unused))
log(const std::string &s)
{
    /* Writes to the server's error log */
    fprintf(stderr, "%s\n", s.c_str());
}
static std::string
decrypt_SEM(const unsigned char *const eValueBytes, uint64_t eValueLen,
            AES_KEY *const aesKey, uint64_t salt)
{
    std::string c(reinterpret_cast<const char *>(eValueBytes),
                  static_cast<unsigned int>(eValueLen));
    return decrypt_AES_CBC(c, aesKey, BytesFromInt(salt, SALT_LEN_BYTES),
                           false);
}


static std::unique_ptr<std::list<std::string>>
split(const std::string &s, unsigned int plen)
{
    const unsigned int len = s.length();
    if (len % plen != 0) {
        thrower() << "split receives invalid input";
    }

    const unsigned int num = len / plen;
    std::unique_ptr<std::list<std::string>>
        res(new std::list<std::string>());

    for (unsigned int i = 0; i < num; i++) {
        res.get()->push_back(s.substr(i*plen, plen));
    }

    return res;
}


static bool
searchExists(const Token &token, const std::string &overall_ciph)
{
    const std::unique_ptr<std::list<std::string>>
        l(split(overall_ciph, SWPCiphSize));
    return SWP::searchExists(token, *l.get());
}


static bool
search(const Token &token, const std::string &overall_ciph)
{
   return searchExists(token, overall_ciph);
}

Datum
cryptdb_func_add_set(PG_FUNCTION_ARGS)
{
    char *args0=PG_GETARG_CSTRING(0);
    char *args1=PG_GETARG_CSTRING(1);
    char *args2=PG_GETARG_CSTRING(2);
    AssignOnce<uint64_t> out_len;;
    ZZ res;
        out_len = strlen(args2);

        ZZ field, val, n2;
        ZZFromBytes(field,
                    reinterpret_cast<const uint8_t *>(args0),
                    strlen(args0));
        ZZFromBytes(val,
         reinterpret_cast<const uint8_t *>(args1),
                    strlen(args1));
        ZZFromBytes(n2, 
         reinterpret_cast<const uint8_t *>(args2),
                   strlen(args2));

        MulMod(res, field, val, n2);
    
     void *const  rbuf = malloc(static_cast<size_t>(out_len.get()));
     char* ptr=static_cast<char *>(rbuf);
    BytesFromZZ(static_cast<uint8_t *>(rbuf), res,out_len.get());


    PG_RETURN_CSTRING(ptr);
}

Datum
cryptdb_decrypt_int_sem(PG_FUNCTION_ARGS)
{
    AssignFirst<uint64_t> value;
        try {
            const uint64_t eValue = PG_GETARG_INT64(0);
            char *const keyBytes = PG_GETARG_CSTRING(1);
            const std::string key = std::string(keyBytes, strlen(keyBytes));

            const uint64_t salt = PG_GETARG_INT64(2);

            blowfish bf(key);
            value = bf.decrypt(eValue) ^ salt;
        } catch (const CryptoError &e) {
            std::cerr << e.msg << std::endl;
            value = 0;
        }
    

    //cerr << "udf: encVal " << eValue << " key " << (int)key[0] << " " << (int)key[1] << " " << (int) key[3]  << " salt " << salt  << " obtains: " << value << " and cast to ulonglong " << (ulonglong) value << "\n";

     PG_RETURN_INT64(static_cast<int64>(value.get()));
}
Datum
cryptdb_decrypt_int_det(PG_FUNCTION_ARGS)
{
    AssignFirst<uint64_t> value;
    
        try {
            const uint64_t eValue = PG_GETARG_INT64(0);
            char *const keyBytes = PG_GETARG_CSTRING(1);
            const std::string key = std::string(keyBytes, strlen(keyBytes));

            const uint64_t shift = PG_GETARG_INT64(2);

            blowfish bf(key);
            value = bf.decrypt(eValue) - shift;
        } catch (const CryptoError &e) {
            std::cerr << e.msg << std::endl;
            value = 0;
        }
    


    PG_RETURN_INT64(static_cast<int64>(value.get()));
}
Datum
cryptdb_decrypt_text_sem(PG_FUNCTION_ARGS)
{
    AssignFirst<std::string> value;
    
        try {
            char *const eValueBytes =PG_GETARG_CSTRING(0);
            uint64_t eValueLen=strlen(eValueBytes);
            char *const keyBytes = PG_GETARG_CSTRING(1);

            const std::string key = std::string(keyBytes, strlen(keyBytes));

            uint64_t salt = PG_GETARG_INT64(2);

            const std::unique_ptr<AES_KEY> aesKey(get_AES_dec_key(key));
            value =
                decrypt_SEM(reinterpret_cast<unsigned char *>(eValueBytes),
                            eValueLen, aesKey.get(), salt);
        } catch (const CryptoError &e) {
            std::cerr << e.msg << std::endl;
            value = "";
        }
    

    // NOTE: This is not creating a proper C string, no guarentee of NUL
    // termination.
    char *const res = new char[value.get().length()];
    memcpy(res, value.get().data(), value.get().length());
    PG_RETURN_CSTRING(res);
}
Datum
cryptdb_decrypt_text_det(PG_FUNCTION_ARGS)
{
    AssignFirst<std::string> value;
        try {
            char *const eValueBytes = PG_GETARG_CSTRING(0);
            char *const keyBytes = PG_GETARG_CSTRING(1);
            const std::string key = std::string(keyBytes, strlen(keyBytes));

            const std::unique_ptr<AES_KEY> aesKey(get_AES_dec_key(key));
            value =
                decrypt_AES_CMC(std::string(eValueBytes,
                                    static_cast<unsigned int>(strlen(eValueBytes))),
                                aesKey.get(), true);
        } catch (const CryptoError &e) {
            std::cerr << e.msg << std::endl;
            value = "";
        }
    

    char *const res = new char[value.get().length()];
    memcpy(res, value.get().data(), value.get().length());

    PG_RETURN_CSTRING(res);
}
Datum
cryptdb_searchSWP(PG_FUNCTION_ARGS)
{
    char *const allciph = PG_GETARG_CSTRING(0);
    const std::string overallciph = std::string(allciph, strlen(allciph));
    Token *const t = new Token();

   
    char *const ciph = PG_GETARG_CSTRING(1);
    uint64_t ciphLen=strlen(ciph);
    
    char *const wordKey = PG_GETARG_CSTRING(2);
    uint64_t wordKeyLen=strlen(wordKey);
    t->ciph = std::string(ciph, ciphLen);
    t->wordKey = std::string(wordKey, wordKeyLen);

    char* ptr = reinterpret_cast<char *>(t);
    Token *const t1 = reinterpret_cast<Token *>(ptr);

    PG_RETURN_INT64(search(*t1, overallciph));
}
struct agg_state {
    ZZ sum;
    ZZ n2;
    bool n2_set;
    void *rbuf;
};

//args will be element to add, constant N2
Datum
cryptdb_agg(PG_FUNCTION_ARGS)
{
    agg_state *const ase = new agg_state();
    ase->rbuf = malloc(Paillier_len_bytes);
    char* ptr = reinterpret_cast<char *>(ase);
    agg_state *const as = reinterpret_cast<agg_state *>(ptr);
    char *const args0=PG_GETARG_CSTRING(0);
    char *const args1=PG_GETARG_CSTRING(1);
    if (!as->n2_set) {
        //cerr << "n2 length is " << args->lengths[1] << "\n";
        //cerr << "n2 first byte is " << (int)args->args[1][0] << "\n";
        ZZFromBytes(as->n2,
                    reinterpret_cast<const uint8_t *>(args1),
                    strlen(args1));
        //cerr << "n2 is " << as->n2 << "\n";
        as->n2_set = 1;
    }

    ZZ e;
    if (NULL == args0) {
        e = to_ZZ(1);
    } else {
        ZZFromBytes(e, reinterpret_cast<const uint8_t *>(args0),
                    strlen(args0));
    }

    //cerr << "element to add " << e << "\n";
    MulMod(as->sum, as->sum, e, as->n2);
    BytesFromZZ(static_cast<uint8_t *>(as->rbuf), as->sum,
                Paillier_len_bytes);
    PG_RETURN_CSTRING(static_cast<char *>(as->rbuf));
}

Datum
cryptdb_version(PG_FUNCTION_ARGS)
{
    const std::string value(cryptdb_version_string);
    char *const res = new char[value.length()];
    char* ptr = res;
    memcpy(res, value.data(), value.length());
    PG_RETURN_CSTRING(static_cast<char*>(ptr));
}
