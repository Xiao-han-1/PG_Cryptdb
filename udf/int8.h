/*-------------------------------------------------------------------------
 *
 * fhe_fhe_int8.h
 *	  Declarations for operations on 64-bit integers.
 *
 *
 * Portions Copyright (c) 1996-2017, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/utils/fhe_int8.h
 *
 * NOTES
 * These data types are supported on all 64-bit architectures, and may
 *	be supported through libraries on some 32-bit machines. If your machine
 *	is not currently supported, then please try to make it so, then post
 *	patches to the postgresql.org hackers mailing list.
 *
 *-------------------------------------------------------------------------
 */


#ifndef INT8_H
#define INT8_H

extern bool scanfhe_int8(const char *str, bool errorOK, int64 *result);
extern Datum fhe_int8in(PG_FUNCTION_ARGS);
extern Datum fhe_int8out(PG_FUNCTION_ARGS);
extern Datum fhe_int8um(PG_FUNCTION_ARGS);
extern Datum fhe_int8pl(PG_FUNCTION_ARGS);
extern Datum fhe_int8mi(PG_FUNCTION_ARGS);
extern Datum fhe_int8mul(PG_FUNCTION_ARGS);
extern Datum fhe_int8div(PG_FUNCTION_ARGS);
extern Datum fhe_int8eq(PG_FUNCTION_ARGS);
extern Datum fhe_int8ne(PG_FUNCTION_ARGS);
extern Datum fhe_int8lt(PG_FUNCTION_ARGS);
extern Datum fhe_int8gt(PG_FUNCTION_ARGS);
extern Datum fhe_int8le(PG_FUNCTION_ARGS);
extern Datum fhe_int8ge(PG_FUNCTION_ARGS);
extern Datum fhe_int84eq(PG_FUNCTION_ARGS);
extern Datum fhe_int84ne(PG_FUNCTION_ARGS);
extern Datum fhe_int84lt(PG_FUNCTION_ARGS);
extern Datum fhe_int84gt(PG_FUNCTION_ARGS);
extern Datum fhe_int84le(PG_FUNCTION_ARGS);
extern Datum fhe_int84ge(PG_FUNCTION_ARGS);
extern Datum fhe_int84(PG_FUNCTION_ARGS);
extern Datum fhe_int8inc(PG_FUNCTION_ARGS);
extern Datum fhe_int8abs(PG_FUNCTION_ARGS);
extern Datum fhe_int8larger(PG_FUNCTION_ARGS);
extern Datum fhe_int8smaller(PG_FUNCTION_ARGS);
extern Datum fhe_int8dec_any(PG_FUNCTION_ARGS);
extern Datum fhe_int8dec(PG_FUNCTION_ARGS)
#endif							/* fhe_int8_H */
