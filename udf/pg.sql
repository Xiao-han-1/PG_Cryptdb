CREATE TYPE fhe;
CREATE FUNCTION fhe_in(cstring)
    RETURNS fhe
    AS '/opt/pgsql/lib/pg_udf.so'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fhe_out(fhe)
    RETURNS cstring
    AS '/opt/pgsql/lib/pg_udf.so'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fhe_recv(internal)
   RETURNS fhe
   AS '/opt/pgsql/lib/pg_udf.so'
   LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fhe_send(fhe)
   RETURNS bytea
   AS '/opt/pgsql/lib/pg_udf.so'
   LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION fhe_mul(fhe,fhe)
   RETURNS fhe
   AS '/opt/pgsql/lib/pg_udf.so','fhe_mul'
   LANGUAGE C IMMUTABLE STRICT;
CREATE OPERATOR * (
    leftarg = fhe,
    rightarg = fhe,
    procedure = fhe_mul,
    commutator = *
);
CREATE FUNCTION fhe_pl(fhe,fhe)
   RETURNS fhe
   AS '/opt/pgsql/lib/pg_udf.so'
   LANGUAGE C IMMUTABLE STRICT;
   CREATE OPERATOR + (
    leftarg = fhe,
    rightarg = fhe,
    procedure = fhe_pl,
    commutator = +
);
CREATE FUNCTION fhe_mi(fhe,fhe)
   RETURNS fhe
   AS '/opt/pgsql/lib/pg_udf.so'
   LANGUAGE C IMMUTABLE STRICT;
   CREATE OPERATOR - (
    leftarg = fhe,
    rightarg = fhe,
    procedure = fhe_mi,
    commutator = -
);
CREATE FUNCTION fhe_eq(fhe,fhe)
   RETURNS bool
   AS '/opt/pgsql/lib/pg_udf.so'
   LANGUAGE C IMMUTABLE STRICT;
   CREATE OPERATOR == (
    leftarg = fhe,
    rightarg = fhe,
    procedure = fhe_eq,
    commutator = ==
);
CREATE FUNCTION fhe_ne(fhe,fhe)
   RETURNS bool
   AS '/opt/pgsql/lib/pg_udf.so'
   LANGUAGE C IMMUTABLE STRICT;
      CREATE OPERATOR != (
    leftarg = fhe,
    rightarg = fhe,
    procedure = fhe_ne,
    commutator = !=
);
CREATE FUNCTION fhe_lt(fhe,fhe)
   RETURNS bool
   AS '/opt/pgsql/lib/pg_udf.so'
   LANGUAGE C IMMUTABLE STRICT;
      CREATE OPERATOR < (
    leftarg = fhe,
    rightarg = fhe,
    procedure = fhe_lt,
    commutator = <
);
CREATE FUNCTION fhe_gt(fhe,fhe)
   RETURNS bool
   AS '/opt/pgsql/lib/pg_udf.so'
   LANGUAGE C IMMUTABLE STRICT;
         CREATE OPERATOR > (
    leftarg = fhe,
    rightarg = fhe,
    procedure = fhe_gt,
    commutator = >
);
CREATE FUNCTION fhe_le(fhe,fhe)
   RETURNS bool
   AS '/opt/pgsql/lib/pg_udf.so'
   LANGUAGE C IMMUTABLE STRICT;
         CREATE OPERATOR <= (
    leftarg = fhe,
    rightarg = fhe,
    procedure = fhe_le,
    commutator = <=
);
CREATE FUNCTION fhe_ge(fhe,fhe)
   RETURNS bool
   AS '/opt/pgsql/lib/pg_udf.so'
   LANGUAGE C IMMUTABLE STRICT;
         CREATE OPERATOR >= (
    leftarg = fhe,
    rightarg = fhe,
    procedure = fhe_ge,
    commutator = >=
);
   CREATE TYPE fhe (
   input = fhe_in,
   output = fhe_out,
   receive = fhe_recv,
   send = fhe_send,
   );
  CREATE FUNCTION text_add(text,bigint)
   RETURNS text
   AS '/opt/pgsql/lib/compute.so','text_add'
   LANGUAGE C IMMUTABLE STRICT;
   CREATE OPERATOR + (
    leftarg = text,
    rightarg = bigint,
    procedure = text_add,
    commutator = +
);
   CREATE FUNCTION text_pl(text,text)
   RETURNS text
   AS '/opt/pgsql/lib/compute.so','text_pl'
   LANGUAGE C IMMUTABLE STRICT;
   CREATE OPERATOR + (
    leftarg = text,
    rightarg = text,
    procedure = text_pl,
    commutator = +
);
CREATE FUNCTION text_mul(text,text)
   RETURNS text
   AS '/opt/pgsql/lib/compute.so','text_mul'
   LANGUAGE C IMMUTABLE STRICT;
   CREATE OPERATOR * (
    leftarg = text,
    rightarg = text,
    procedure = text_mul,
    commutator = *
);
CREATE FUNCTION text_mi(text,text)
   RETURNS text
   AS '/opt/pgsql/lib/compute.so'
   LANGUAGE C IMMUTABLE STRICT;
   CREATE OPERATOR - (
    leftarg = text,
    rightarg = text,
    procedure = text_mi,
    commutator = -
);
CREATE FUNCTION text_eq(text,text)
   RETURNS bool
   AS '/opt/pgsql/lib/compute.so'
   LANGUAGE C IMMUTABLE STRICT;
   CREATE OPERATOR == (
    leftarg = text,
    rightarg = text,
    procedure = text_eq,
    commutator = ==
);
CREATE FUNCTION text_ne(text,text)
   RETURNS bool
   AS '/opt/pgsql/lib/compute.so'
   LANGUAGE C IMMUTABLE STRICT;
      CREATE OPERATOR != (
    leftarg = text,
    rightarg = text,
    procedure = text_ne,
    commutator = !=
);
CREATE FUNCTION text_lt(text,text)
   RETURNS bool
   AS '/opt/pgsql/lib/compute.so'
   LANGUAGE C IMMUTABLE STRICT;
      CREATE OPERATOR < (
    leftarg = text,
    rightarg = text,
    procedure = text_lt,
    commutator = <
);
CREATE FUNCTION text_gt(text,text)
   RETURNS bool
   AS '/opt/pgsql/lib/compute.so'
   LANGUAGE C IMMUTABLE STRICT;
         CREATE OPERATOR > (
    leftarg = text,
    rightarg = text,
    procedure = text_gt,
    commutator = >
);
CREATE FUNCTION text_le(text,text)
   RETURNS bool
   AS '/opt/pgsql/lib/compute.so'
   LANGUAGE C IMMUTABLE STRICT;
         CREATE OPERATOR <= (
    leftarg = text,
    rightarg = text,
    procedure = text_le,
    commutator = <=
);
CREATE FUNCTION text_ge(text,text)
   RETURNS bool
   AS '/opt/pgsql/lib/compute.so'
   LANGUAGE C IMMUTABLE STRICT;
         CREATE OPERATOR >= (
    leftarg = text,
    rightarg = text,
    procedure = text_ge,
    commutator = >=
);
rm -rf /opt/pgsql/lib/compute.so
cp compute.so /opt/pgsql/lib
g++ -Wall -o compute.o -fPIC -c compute.cc -I/root/pakages/postgresql-10.10/src/include -I/root/pakages/copy/cryptdb
g++ -shared -o  compute.so  compute.o -L/opt/pgsql/lib -L/usr/lib -lpq -lckks
SELECT t1+t2 from test_num;