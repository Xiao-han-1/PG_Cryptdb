OBJDIR	 := obj
TOP	 := $(shell echo $${PWD-`pwd`})
CXX	 := g++
AR	 := ar
## -g -O0 -> -O2
CXXFLAGS :=-g -O0 -fno-strict-aliasing -fno-rtti -fwrapv -fPIC \
	    -Wall  -Wpointer-arith -Wendif-labels -Wformat=2  \
	    -Wextra -Wmissing-noreturn -Wwrite-strings -Wno-unused-parameter \
	    -Wno-deprecated  \
	    -Wmissing-declarations -Woverloaded-virtual  \
	    -Wunreachable-code -D_GNU_SOURCE -std=c++17 -I$(TOP)
LDFLAGS  := -L$(TOP)/$(OBJDIR)  -L/opt/pgsql/lib -L/usr/lib -Wl,--no-undefined

## Copy conf/config.mk.sample to conf/config.mk and adjust accordingly.
include conf/config.mk

## Use RPATH only for debug builds; set RPATH=1 in config.mk.
ifeq ($(RPATH),1)
LDRPATH	 := -Wl,-rpath=$(TOP)/$(OBJDIR)  -Wl,-rpath=$(TOP)
endif

PGHOME:=/usr/include/postgresql 
PGINC:=/opt/pgsql/include
PGSRC:=/root/pakages/postgresql-10.10/src/include
SEALSRC:=/root/pakages/copy/cryptdb/SEAL/native/src
OpenFHE_INCLUDE:=/usr/local/include/openfhe
SQLINC:=/usr/include/mysql
SQLLOC:=/root/pakages/copy/mysql-src/include
NTLIN:=/root/pakages/copy/cryptdb/ntl-6.2.1
CXXFLAGS += -I$(PGHOME) \
        -I$(OpenFHE_INCLUDE) \
		-I$(OpenFHE_INCLUDE)/core \
		-I$(OpenFHE_INCLUDE)/pke \
        -I$(PGSRC)\
        -I$(PGINC)/server \
		-I$(PGINC)/bin \
        -I$(NTLIN)/include \
        -I$(MYBUILD)/include \
	    -I$(MYSRC)/include \
	    -I$(MYSRC)/sql \
	    -I$(MYSRC)/regex \
	    -I$(MYBUILD)/sql \
	    -DHAVE_CONFIG_H -DMYSQL_SERVER -DEMBEDDED_LIBRARY -DDBUG_OFF -fpermissive \
	    -DMYSQL_BUILD_DIR=\"$(MYBUILD)\"
LDFLAGS	 += -lpthread -lrt -ldl -lcrypt -lpq -lreadline -lckks
## To be populated by Makefrag files
CPPFLAGS += -I /usr/include/postgresql 
OBJDIRS	:=

.PHONY: all
all:

.PHONY: install
install:

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

.PHONY: doc
doc:
	doxygen CryptDBdoxgen

.PHONY: whitespace
whitespace:
	find . -name '*.cc' -o -name '*.hh' -type f -exec sed -i 's/ *$//' '{}' ';'

.PHONY: always
always:

# Eliminate default suffix rules
.SUFFIXES:

# Delete target files if there is an error (or make is interrupted)
.DELETE_ON_ERROR:

# make it so that no intermediate .o files are ever deleted
.PRECIOUS: %.o

$(OBJDIR)/%.o: %.cc
	@mkdir -p $(@D)
	$(CXX) -MD $(CXXFLAGS)  -c $< -o $@

$(OBJDIR)/%.o: $(OBJDIR)/%.cc
	@mkdir -p $(@D)
	$(CXX) -MD $(CXXFLAGS)  -c $< -o $@

include crypto/Makefrag
# include Crypto-ckks/Makefile
#include Crypto-ckks/build/Makefile
include parser/Makefrag
include main/Makefrag
# include test/Makefrag
include util/Makefrag
# include udf/Makefrag
include tools/import/Makefrag
include tools/learn/Makefrag
include scripts/Makefrag

$(OBJDIR)/.deps: $(foreach dir, $(OBJDIRS), $(wildcard $(OBJDIR)/$(dir)/*.d))
	@mkdir -p $(@D)
	perl mergedep.pl $@ $^
-include $(OBJDIR)/.deps

# .PHONY: indent
# indent:
#	uncrustify --no-backup -c conf/uncrustify.cfg $(wildcard *.cc)

# vim: set noexpandtab:
