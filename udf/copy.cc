
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
#include "postgres.h"

#include <ctype.h>
#include <limits.h>

#include "access/hash.h"
#include "access/tuptoaster.h"
#include "catalog/pg_collation.h"
#include "catalog/pg_type.h"
#include "common/md5.h"
#include "lib/hyperloglog.h"
#include "libpq/pqformat.h"
#include "miscadmin.h"
#include "parser/scansup.h"
#include "port/pg_bswap.h"
#include "regex/regex.h"
#include "utils/builtins.h"
#include "utils/bytea.h"
#include "utils/lsyscache.h"
#include "utils/memutils.h"
#include "utils/pg_locale.h"
#include "utils/sortsupport.h"
#include "utils/varlena.h"


#ifdef PG_MODULE_MAGIC

PG_MODULE_MAGIC;

#endif

/*-------------------------------------------------------------------------
 *
 * varlena.c
 *	  Functions for the variable-length built-in types.
 *
 * Portions Copyright (c) 1996-2017, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *	  src/backend/utils/adt/varlena.c
 *
 *-------------------------------------------------------------------------
 */

/* GUC variable */
int			bytea_output = BYTEA_OUTPUT_HEX;

typedef struct varlena unknown;
typedef struct varlena VarString;
typedef struct fhe
{
	text* t;
}fhe;


// /*****************************************************************************
//  *	 CONVERSION ROUTINES EXPORTED FOR USE BY C CODE							 *
//  *****************************************************************************/

// /*
//  * cstring_to_text
//  *
//  * Create a text value from a null-terminated C string.
//  *
//  * The new text value is freshly palloc'd with a full-size VARHDR.
//  */

// // PG_FUNCTION_INFO_V1(fhe_in);
// // PG_FUNCTION_INFO_V1(fhe_out);
// // PG_FUNCTION_INFO_V1(fhe_recv);
// // PG_FUNCTION_INFO_V1(fhe_send);
// // PG_FUNCTION_INFO_V1(fhe_mul);
// // PG_FUNCTION_INFO_V1(fhe_pl);
// // // PG_FUNCTION_INFO_V1(fhe_mi);
// void
// initStringInfo(StringInfo str)
// {
// 	int			size = 1024;	/* initial default buffer size */

// 	str->data = (char *) malloc(size);
// 	str->maxlen = size;
// 	str->data[0] = '\0';
// 	str->len = 0;
// 	str->cursor = 0;
// }
// void
// appendStringInfoChar(StringInfo str, char ch)
// {
// 	/* Make more room if needed */
// 	/* OK, append the character */
// 	str->data[str->len] = ch;
// 	str->len++;
// 	str->data[str->len] = '\0';
// }
// text *
// cstring_to_text(const char *s)
// {
// 	return cstring_to_text_with_len(s, strlen(s));
// }

// /*
//  * cstring_to_text_with_len
//  *
//  * Same as cstring_to_text except the caller specifies the string length;
//  * the string need not be null_terminated.
//  */
// text *
// cstring_to_text_with_len(const char *s, int len)
// {
// 	text	   *result = (text *) malloc(len + VARHDRSZ);

// 	SET_VARSIZE(result, len + VARHDRSZ);
// 	memcpy(VARDATA(result), s, len);

// 	return result;
// }
// struct varlena *
// pg_detoast_datum_packed(struct varlena *datum)
// {
// 		return datum;
// }

// char *
// text_to_cstring(const text *t)
// {
// 	/* must cast away the const, unfortunately */
// 	text	   *tunpacked = pg_detoast_datum_packed((struct varlena *) t);
// 	int			len = VARSIZE_ANY_EXHDR(tunpacked);
// 	char	   *result;

// 	result = (char *) malloc(len + 1);
// 	memcpy(result, VARDATA_ANY(tunpacked), len);
// 	result[len] = '\0';

// 	if (tunpacked != t)
// 		free(tunpacked);

// 	return result;
// }
// void
// pq_begintypsend(StringInfo buf)
// {
// 	initStringInfo(buf);
// 	/* Reserve four bytes for the bytea length word */
// 	appendStringInfoCharMacro(buf, '\0');
// 	appendStringInfoCharMacro(buf, '\0');
// 	appendStringInfoCharMacro(buf, '\0');
// 	appendStringInfoCharMacro(buf, '\0');
// }
// void
// pq_sendtext(StringInfo buf, const char *str, int slen)
// {
// 		appendBinaryStringInfo(buf, str, slen);
// }
// void
// appendBinaryStringInfo(StringInfo str, const char *data, int datalen)
// {
// 	Assert(str != NULL);


// 	/* OK, append the data */
// 	memcpy(str->data + str->len, data, datalen);
// 	str->len += datalen;

// 	/*
// 	 * Keep a trailing null in place, even though it's probably useless for
// 	 * binary data.  (Some callers are dealing with text but call this because
// 	 * their input isn't null-terminated.)
// 	 */
// 	str->data[str->len] = '\0';
// }
// bytea *
// pq_endtypsend(StringInfo buf)
// {
// 	bytea	   *result = (bytea *) buf->data;

// 	/* Insert correct length into bytea length word */
// 	Assert(buf->len >= VARHDRSZ);
// 	SET_VARSIZE(result, buf->len);

// 	return result;
// }

PG_FUNCTION_INFO_V1(fhe_in);
PG_FUNCTION_INFO_V1(fhe_out);
PG_FUNCTION_INFO_V1(fhe_recv);
PG_FUNCTION_INFO_V1(fhe_send);
// PG_FUNCTION_INFO_V1(fhe_mul);
// PG_FUNCTION_INFO_V1(fhe_pl);
// PG_FUNCTION_INFO_V1(fhe_mi);


// CREATE FUNCTION fhe_in(cstring) 
// RETURNS text AS '/opt/pgsql/lib/pg_udf.so', 'fhe_in'  LANGUAGE C STRICT;
//  CREATE FUNCTION fhe_out(fhe) 
//  RETURNS cstring AS '/opt/pgsql/lib/pg_udf.so', 'fhe_out'  LANGUAGE C STRICT;
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
Datum
fhe_in(PG_FUNCTION_ARGS)
{
	char	   *inputText = PG_GETARG_CSTRING(0);
	fhe* result = (fhe *) palloc(sizeof(fhe));
	text* t=cstring_to_text(inputText);
	result->t=t;
	PG_RETURN_POINTER(result);
}

/*
 *		textout			- converts internal representation to "..."
 */
Datum
fhe_out(PG_FUNCTION_ARGS)
{
	fhe		*txt = (fhe *) PG_GETARG_POINTER(0);
    char       *result;
    result=TextDatumGetCString(txt->t);
	PG_RETURN_CSTRING(result);
}

/*
 *		textrecv			- converts external binary format to text
 */
Datum
fhe_recv(PG_FUNCTION_ARGS)
{
	StringInfo	buf = (StringInfo) PG_GETARG_POINTER(0);
	fhe	   *result;
	char	   *str;
	int			nbytes;

    str = pq_getmsgtext(buf, buf->len - buf->cursor, &nbytes);
	result->t = cstring_to_text_with_len(str, nbytes);
	pfree(str);
	 PG_RETURN_POINTER(result);
}

/*
 *		textsend			- converts text to binary format
 */
Datum
fhe_send(PG_FUNCTION_ARGS)
{
	fhe	   *f = (fhe *) PG_GETARG_POINTER(0);
	StringInfoData buf;

	pq_begintypsend(&buf);
	pq_sendtext(&buf, VARDATA_ANY(f->t), VARSIZE_ANY_EXHDR(f->t));
	PG_RETURN_BYTEA_P(pq_endtypsend(&buf));
}
}
// static void __attribute__((unused))
// log(const std::string &s)
// {
//     /* Writes to the server's error log */
//     fprintf(stderr, "%s\n", s.c_str());
// }
// static std::string
// decrypt_SEM(const unsigned char *const eValueBytes, uint64_t eValueLen,
//             AES_KEY *const aesKey, uint64_t salt)
// {
//     std::string c(reinterpret_cast<const char *>(eValueBytes),
//                   static_cast<unsigned int>(eValueLen));
//     return decrypt_AES_CBC(c, aesKey, BytesFromInt(salt, SALT_LEN_BYTES),
//                            false);
// }


// static std::unique_ptr<std::list<std::string>>
// split(const std::string &s, unsigned int plen)
// {
//     const unsigned int len = s.length();
//     if (len % plen != 0) {
//         thrower() << "split receives invalid input";
//     }

//     const unsigned int num = len / plen;
//     std::unique_ptr<std::list<std::string>>
//         res(new std::list<std::string>());

//     for (unsigned int i = 0; i < num; i++) {
//         res.get()->push_back(s.substr(i*plen, plen));
//     }

//     return res;
// }


// static bool
// searchExists(const Token &token, const std::string &overall_ciph)
// {
//     const std::unique_ptr<std::list<std::string>>
//         l(split(overall_ciph, SWPCiphSize));
//     return SWP::searchExists(token, *l.get());
// }


// static bool
// search(const Token &token, const std::string &overall_ciph)
// {
//    return searchExists(token, overall_ciph);
// }

// Datum
// cryptdb_func_add_set(PG_FUNCTION_ARGS)
// {
//     char *args0=PG_GETARG_CSTRING(0);
//     char *args1=PG_GETARG_CSTRING(1);
//     char *args2=PG_GETARG_CSTRING(2);
//     AssignOnce<uint64_t> out_len;;
//     ZZ res;
//         out_len = strlen(args2);

//         ZZ field, val, n2;
//         ZZFromBytes(field,
//                     reinterpret_cast<const uint8_t *>(args0),
//                     strlen(args0));
//         ZZFromBytes(val,
//          reinterpret_cast<const uint8_t *>(args1),
//                     strlen(args1));
//         ZZFromBytes(n2, 
//          reinterpret_cast<const uint8_t *>(args2),
//                    strlen(args2));

//         MulMod(res, field, val, n2);
    
//      void *const  rbuf = malloc(static_cast<size_t>(out_len.get()));
//      char* ptr=static_cast<char *>(rbuf);
//     BytesFromZZ(static_cast<uint8_t *>(rbuf), res,out_len.get());


//     PG_RETURN_CSTRING(ptr);
// }

// Datum
// cryptdb_decrypt_int_sem(PG_FUNCTION_ARGS)
// {
//     AssignFirst<uint64_t> value;
//         try {
//             const uint64_t eValue = PG_GETARG_INT64(0);
//             char *const keyBytes = PG_GETARG_CSTRING(1);
//             const std::string key = std::string(keyBytes, strlen(keyBytes));

//             const uint64_t salt = PG_GETARG_INT64(2);

//             blowfish bf(key);
//             value = bf.decrypt(eValue) ^ salt;
//         } catch (const CryptoError &e) {
//             std::cerr << e.msg << std::endl;
//             value = 0;
//         }
    

//     //cerr << "udf: encVal " << eValue << " key " << (int)key[0] << " " << (int)key[1] << " " << (int) key[3]  << " salt " << salt  << " obtains: " << value << " and cast to ulonglong " << (ulonglong) value << "\n";

//      PG_RETURN_INT64(static_cast<int64>(value.get()));
// }
// Datum
// cryptdb_decrypt_int_det(PG_FUNCTION_ARGS)
// {
//     AssignFirst<uint64_t> value;
    
//         try {
//             const uint64_t eValue = PG_GETARG_INT64(0);
//             char *const keyBytes = PG_GETARG_CSTRING(1);
//             const std::string key = std::string(keyBytes, strlen(keyBytes));

//             const uint64_t shift = PG_GETARG_INT64(2);

//             blowfish bf(key);
//             value = bf.decrypt(eValue) - shift;
//         } catch (const CryptoError &e) {
//             std::cerr << e.msg << std::endl;
//             value = 0;
//         }
    


//     PG_RETURN_INT64(static_cast<int64>(value.get()));
// }
// Datum
// cryptdb_decrypt_text_sem(PG_FUNCTION_ARGS)
// {
//     AssignFirst<std::string> value;
    
//         try {
//             char *const eValueBytes =PG_GETARG_CSTRING(0);
//             uint64_t eValueLen=strlen(eValueBytes);
//             char *const keyBytes = PG_GETARG_CSTRING(1);

//             const std::string key = std::string(keyBytes, strlen(keyBytes));

//             uint64_t salt = PG_GETARG_INT64(2);

//             const std::unique_ptr<AES_KEY> aesKey(get_AES_dec_key(key));
//             value =
//                 decrypt_SEM(reinterpret_cast<unsigned char *>(eValueBytes),
//                             eValueLen, aesKey.get(), salt);
//         } catch (const CryptoError &e) {
//             std::cerr << e.msg << std::endl;
//             value = "";
//         }
    

//     // NOTE: This is not creating a proper C string, no guarentee of NUL
//     // termination.
//     char *const res = new char[value.get().length()];
//     memcpy(res, value.get().data(), value.get().length());
//     PG_RETURN_CSTRING(res);
// }
// Datum
// cryptdb_decrypt_text_det(PG_FUNCTION_ARGS)
// {
//     AssignFirst<std::string> value;
//         try {
//             char *const eValueBytes = PG_GETARG_CSTRING(0);
//             char *const keyBytes = PG_GETARG_CSTRING(1);
//             const std::string key = std::string(keyBytes, strlen(keyBytes));

//             const std::unique_ptr<AES_KEY> aesKey(get_AES_dec_key(key));
//             value =
//                 decrypt_AES_CMC(std::string(eValueBytes,
//                                     static_cast<unsigned int>(strlen(eValueBytes))),
//                                 aesKey.get(), true);
//         } catch (const CryptoError &e) {
//             std::cerr << e.msg << std::endl;
//             value = "";
//         }
    

//     char *const res = new char[value.get().length()];
//     memcpy(res, value.get().data(), value.get().length());

//     PG_RETURN_CSTRING(res);
// }
// Datum
// cryptdb_searchSWP(PG_FUNCTION_ARGS)
// {
//     char *const allciph = PG_GETARG_CSTRING(0);
//     const std::string overallciph = std::string(allciph, strlen(allciph));
//     Token *const t = new Token();

   
//     char *const ciph = PG_GETARG_CSTRING(1);
//     uint64_t ciphLen=strlen(ciph);
    
//     char *const wordKey = PG_GETARG_CSTRING(2);
//     uint64_t wordKeyLen=strlen(wordKey);
//     t->ciph = std::string(ciph, ciphLen);
//     t->wordKey = std::string(wordKey, wordKeyLen);

//     char* ptr = reinterpret_cast<char *>(t);
//     Token *const t1 = reinterpret_cast<Token *>(ptr);

//     PG_RETURN_INT64(search(*t1, overallciph));
// }
// struct agg_state {
//     ZZ sum;
//     ZZ n2;
//     bool n2_set;
//     void *rbuf;
// };

// //args will be element to add, constant N2
// Datum
// cryptdb_agg(PG_FUNCTION_ARGS)
// {
//     agg_state *const ase = new agg_state();
//     ase->rbuf = malloc(Paillier_len_bytes);
//     char* ptr = reinterpret_cast<char *>(ase);
//     agg_state *const as = reinterpret_cast<agg_state *>(ptr);
//     char *const args0=PG_GETARG_CSTRING(0);
//     char *const args1=PG_GETARG_CSTRING(1);
//     if (!as->n2_set) {
//         //cerr << "n2 length is " << args->lengths[1] << "\n";
//         //cerr << "n2 first byte is " << (int)args->args[1][0] << "\n";
//         ZZFromBytes(as->n2,
//                     reinterpret_cast<const uint8_t *>(args1),
//                     strlen(args1));
//         //cerr << "n2 is " << as->n2 << "\n";
//         as->n2_set = 1;
//     }

//     ZZ e;
//     if (NULL == args0) {
//         e = to_ZZ(1);
//     } else {
//         ZZFromBytes(e, reinterpret_cast<const uint8_t *>(args0),
//                     strlen(args0));
//     }

//     //cerr << "element to add " << e << "\n";
//     MulMod(as->sum, as->sum, e, as->n2);
//     BytesFromZZ(static_cast<uint8_t *>(as->rbuf), as->sum,
//                 Paillier_len_bytes);
//     PG_RETURN_CSTRING(static_cast<char *>(as->rbuf));
// }

// Datum
// cryptdb_version(PG_FUNCTION_ARGS)
// {
//     const std::string value(cryptdb_version_string);
//     char *const res = new char[value.length()];
//     char* ptr = res;
//     memcpy(res, value.data(), value.length());
//     PG_RETURN_CSTRING(static_cast<char*>(ptr));
// }
