
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
 std::string Mul(std::string arg1,std::string arg2);
PG_FUNCTION_INFO_V1(text_mul);
PG_FUNCTION_INFO_V1(text_add);
PG_FUNCTION_INFO_V1(text_pl);
PG_FUNCTION_INFO_V1(text_mi);
PG_FUNCTION_INFO_V1(text_eq);
PG_FUNCTION_INFO_V1(text_ne);
PG_FUNCTION_INFO_V1(text_lt);
PG_FUNCTION_INFO_V1(text_gt);
PG_FUNCTION_INFO_V1(text_le);
PG_FUNCTION_INFO_V1(text_ge);
}

 std::string Mul(std::string arg1,std::string arg2)
 {
    FHE_CKKS CKKS;
    CKKS.Init();
     std::string re= CKKS.Mul(arg1,arg2);
     return re;
 }
Datum
text_mul(PG_FUNCTION_ARGS)
{
	text	   *t1 = PG_GETARG_TEXT_PP(0);
	text	   *t2 = PG_GETARG_TEXT_PP(1);
	std::string		result;
    std::string arg1=TextDatumGetCString(t1);
    std::string arg2=TextDatumGetCString(t2);
	result = Mul(arg1,arg2);
    
    const char *p=(char*)result.c_str();
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
	PG_RETURN_TEXT_P(cstring_to_text(p));
}

Datum
text_pl(PG_FUNCTION_ARGS)
{
	text	   *t1 = PG_GETARG_TEXT_PP(0);
	text	   *t2 = PG_GETARG_TEXT_PP(1);
	std::string		result;
	
    std::string arg1=TextDatumGetCString(t1);
    std::string arg2=TextDatumGetCString(t2);
    
     FHE_CKKS* sk =new FHE_CKKS();
	result = sk->Add(arg1,arg2);
    const char *p=(char*)result.c_str();
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
	PG_RETURN_TEXT_P(cstring_to_text(p));
}

Datum
text_mi(PG_FUNCTION_ARGS)
{
	text	   *t1 = PG_GETARG_TEXT_PP(0);
	text	   *t2 = PG_GETARG_TEXT_PP(1);
	std::string		result;
    std::string arg1=TextDatumGetCString(t1);
    std::string arg2=TextDatumGetCString(t2);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Sub(arg1,arg2);
    const char *p=(char*)result.c_str();
	
	PG_RETURN_TEXT_P(cstring_to_text(p));
}
Datum
text_add(PG_FUNCTION_ARGS)
{
	text	   *t1 = PG_GETARG_TEXT_PP(0);
	int64		t2 = PG_GETARG_INT64(0);
	std::string		result;
	FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
    std::string arg1=TextDatumGetCString(t1);
	double te2=(double)t2;
    std::string arg2=sk->Encrypt(te2);
	result = sk->Sub(arg1,arg2);
    const char *p=(char*)result.c_str();
	
	PG_RETURN_TEXT_P(cstring_to_text(p));
}
Datum
text_eq(PG_FUNCTION_ARGS)
{
	text	   *t1 = PG_GETARG_TEXT_PP(0);
	text	   *t2 = PG_GETARG_TEXT_PP(1);
	int	result;
    std::string arg1=TextDatumGetCString(t1);
    std::string arg2=TextDatumGetCString(t2);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);
    if(result==0.0)
	PG_RETURN_BOOL(true);
    else PG_RETURN_BOOL(false);
}

Datum
text_ne(PG_FUNCTION_ARGS)
{
	text	   *t1 = PG_GETARG_TEXT_PP(0);
	text	   *t2 = PG_GETARG_TEXT_PP(1);
	int	result;
    std::string arg1=TextDatumGetCString(t1);
    std::string arg2=TextDatumGetCString(t2);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);
	if(result!=0.0)
	PG_RETURN_BOOL(true);
    else PG_RETURN_BOOL(false);
}

Datum
text_lt(PG_FUNCTION_ARGS)
{
	text	   *t1 = PG_GETARG_TEXT_PP(0);
	text	   *t2 = PG_GETARG_TEXT_PP(1);
	int	result;
    std::string arg1=TextDatumGetCString(t1);
    std::string arg2=TextDatumGetCString(t2);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);
	if(result < 0)
	PG_RETURN_BOOL(true);
    else PG_RETURN_BOOL(false);
}

Datum
text_gt(PG_FUNCTION_ARGS)
{
    text	   *t1 = PG_GETARG_TEXT_PP(0);
	text	   *t2 = PG_GETARG_TEXT_PP(1);
	int	result;
    std::string arg1=TextDatumGetCString(t1);
    std::string arg2=TextDatumGetCString(t2);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);
   if(result>0)
	PG_RETURN_BOOL(true);
    else PG_RETURN_BOOL(false);
}

Datum
text_le(PG_FUNCTION_ARGS)
{
	text	   *t1 = PG_GETARG_TEXT_PP(0);
	text	   *t2 = PG_GETARG_TEXT_PP(1);
	int	result;
    std::string arg1=TextDatumGetCString(t1);
    std::string arg2=TextDatumGetCString(t2);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);
	if(result <= 0)
	PG_RETURN_BOOL(true);
    else PG_RETURN_BOOL(false);
}

Datum
text_ge(PG_FUNCTION_ARGS)
{
	text	   *t1 = PG_GETARG_TEXT_PP(0);
	text	   *t2 = PG_GETARG_TEXT_PP(1);
	int	result;
    std::string arg1=TextDatumGetCString(t1);
    std::string arg2=TextDatumGetCString(t2);
    FHE_CKKS* sk =new FHE_CKKS();
    sk->Init();
	result = sk->Compare(arg1,arg2);
    if(result>=0.0)
	PG_RETURN_BOOL(true);
    else PG_RETURN_BOOL(false);
}