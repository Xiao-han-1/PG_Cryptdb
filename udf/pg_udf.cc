
#define DEBUG 1

#include <memory>
#include <string.h>
#include <NTL/ZZ.h>
#include <ctype.h>
#include <Crypto-ckks/ckks.hh>
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
typedef struct fhe
{
	text* t;
}fhe;
PG_FUNCTION_INFO_V1(fhe_in);
PG_FUNCTION_INFO_V1(fhe_out);
PG_FUNCTION_INFO_V1(fhe_recv);
PG_FUNCTION_INFO_V1(fhe_send);
PG_FUNCTION_INFO_V1(fhe_mul);
PG_FUNCTION_INFO_V1(fhe_pl);
PG_FUNCTION_INFO_V1(fhe_mi);
PG_FUNCTION_INFO_V1(fhe_eq);
PG_FUNCTION_INFO_V1(fhe_ne);
PG_FUNCTION_INFO_V1(fhe_lt);
PG_FUNCTION_INFO_V1(fhe_gt);
PG_FUNCTION_INFO_V1(fhe_le);
PG_FUNCTION_INFO_V1(fhe_ge);
}
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
	char	   *str;
	int			nbytes;

    str = pq_getmsgtext(buf, buf->len - buf->cursor, &nbytes);
	fhe* result = (fhe *) palloc(sizeof(fhe));
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
Datum
fhe_mul(PG_FUNCTION_ARGS)
{
	fhe	   *f1 = (fhe *) PG_GETARG_POINTER(0);
	fhe	   *f2 = (fhe *) PG_GETARG_POINTER(1);
	std::string		result;
    std::string arg1=TextDatumGetCString(f1->t);
    std::string arg2=TextDatumGetCString(f2->t);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Mul(arg1,arg2);
    const char *p=(char*)result.c_str();
	fhe* res = (fhe *) palloc(sizeof(fhe));
	res->t=cstring_to_text(p);
	/*
	 * Overflow check.  We basically check to see if result / arg2 gives arg1
	 * again.  There are two cases where this fails: arg2 = 0 (which cannot
	 * overflow) and arg1 = INT64_MIN, arg2 = -1 (where the division itself
	 * will overflow and thus incorrectly match).
	 *
	 * Since the division is likely much more expensive than the actual
	 * multiplication, we'd like to skip it where possible.  The best bang for
	 * the buck seems to be to check whether both inputs are in the int32
	 * range; if so, no overflow is possible.
	 */
	PG_RETURN_POINTER(res);
}

Datum
fhe_pl(PG_FUNCTION_ARGS)
{
	fhe	   *f1 = (fhe *) PG_GETARG_POINTER(0);
	fhe	   *f2 = (fhe *) PG_GETARG_POINTER(1);
	std::string		result;
	
    std::string arg1=TextDatumGetCString(f1->t);
    std::string arg2=TextDatumGetCString(f2->t);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Add(arg1,arg2);
    const char *p=(char*)result.c_str();
	fhe* res = (fhe *) palloc(sizeof(fhe));
	res->t=cstring_to_text(p);
	PG_RETURN_POINTER(res);
}

Datum
fhe_mi(PG_FUNCTION_ARGS)
{
	fhe	   *f1 = (fhe *) PG_GETARG_POINTER(0);
	fhe	   *f2 = (fhe *) PG_GETARG_POINTER(1);
	std::string		result;
	
    std::string arg1=TextDatumGetCString(f1->t);
    std::string arg2=TextDatumGetCString(f2->t);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Sub(arg1,arg2);
    const char *p=(char*)result.c_str();
	fhe* res = (fhe *) palloc(sizeof(fhe));
	res->t=cstring_to_text(p);
	PG_RETURN_POINTER(res);
}

Datum
fhe_eq(PG_FUNCTION_ARGS)
{
	fhe	   *f1 = (fhe *) PG_GETARG_POINTER(0);
	fhe	   *f2 = (fhe *) PG_GETARG_POINTER(1);
	int		result;
	
    std::string arg1=TextDatumGetCString(f1->t);
    std::string arg2=TextDatumGetCString(f2->t);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);
	PG_RETURN_BOOL(result==0);
}

Datum
fhe_ne(PG_FUNCTION_ARGS)
{
	fhe	   *f1 = (fhe *) PG_GETARG_POINTER(0);
	fhe	   *f2 = (fhe *) PG_GETARG_POINTER(1);
	int		result;
	
    std::string arg1=TextDatumGetCString(f1->t);
    std::string arg2=TextDatumGetCString(f2->t);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);
	PG_RETURN_BOOL(result != 0);
}

Datum
fhe_lt(PG_FUNCTION_ARGS)
{
	fhe	   *f1 = (fhe *) PG_GETARG_POINTER(0);
	fhe	   *f2 = (fhe *) PG_GETARG_POINTER(1);
	int		result;
	
    std::string arg1=TextDatumGetCString(f1->t);
    std::string arg2=TextDatumGetCString(f2->t);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);
	PG_RETURN_BOOL(result < 0);
}

Datum
fhe_gt(PG_FUNCTION_ARGS)
{
    fhe	   *f1 = (fhe *) PG_GETARG_POINTER(0);
	fhe	   *f2 = (fhe *) PG_GETARG_POINTER(1);
	int		result;
	
    std::string arg1=TextDatumGetCString(f1->t);
    std::string arg2=TextDatumGetCString(f2->t);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);

	PG_RETURN_BOOL(result > 0);
}

Datum
fhe_le(PG_FUNCTION_ARGS)
{
	fhe	   *f1 = (fhe *) PG_GETARG_POINTER(0);
	fhe	   *f2 = (fhe *) PG_GETARG_POINTER(1);
	int		result;
	
    std::string arg1=TextDatumGetCString(f1->t);
    std::string arg2=TextDatumGetCString(f2->t);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);
	PG_RETURN_BOOL(result <= 0);
}

Datum
fhe_ge(PG_FUNCTION_ARGS)
{
	fhe	   *f1 = (fhe *) PG_GETARG_POINTER(0);
	fhe	   *f2 = (fhe *) PG_GETARG_POINTER(1);
	int		result;
	
    std::string arg1=TextDatumGetCString(f1->t);
    std::string arg2=TextDatumGetCString(f2->t);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);
	PG_RETURN_BOOL(result >= 0);
}