OBJDIR	 := obj
TOP	 := $(shell echo $${PWD-`pwd`})
CXX	 := g++
AR	 := ar
## -g -O0 -> -O2
CXXFLAGS := -shared -g -O0 -fno-strict-aliasing -fno-rtti -fwrapv -fPIC \
	    -Wall  -Wpointer-arith -Wendif-labels -Wformat=2  \
	    -Wextra -Wmissing-noreturn -Wwrite-strings -Wno-unused-parameter \
	    -Wno-deprecated  -Wno-error=register\
	    -Wmissing-declarations -Woverloaded-virtual  \
	    -Wunreachable-code -D_GNU_SOURCE -std=c++17 -I$(TOP)
LDFLAGS  := -L$(TOP)/$(OBJDIR) -Wl,--no-undefined

## Copy conf/config.mk.sample to conf/config.mk and adjust accordingly.
include conf/config.mk

## Use RPATH only for debug builds; set RPATH=1 in config.mk.
ifeq ($(RPATH),1)
LDRPATH	 := -Wl,-rpath=$(TOP)/$(OBJDIR) -Wl,-rpath=$(TOP)
endif

PGHOME:=/opt/pgsql
PGINC:=/opt/pgsql/include
PGSRC:=/root/pakages/postgresql-10.0/src
SEALSRC:=/root/pakages/copy/cryptdb/SEAL/native/src
SEINCLUDE:=/usr/local/include/SEAL-4.0/seal
SQLINC:=/usr/include/mysql
SQLLOC:=/root/pakages/copy/cryptdb/mysql-src/include
CXXFLAGS += -I$(PGSRC)/include \
         -I$(PGINC)/server \
		 -I$(PGINC)/bin \
        -I$(MYBUILD)/include \
	    -I$(MYSRC)/include \
	    -I$(MYSRC)/sql \
	    -I$(MYSRC)/regex \
	    -I$(MYBUILD)/sql \
	    -DHAVE_CONFIG_H -DMYSQL_SERVER -DEMBEDDED_LIBRARY -DDBUG_OFF -fpermissive -Wno-error=terminate \
	    -DMYSQL_BUILD_DIR=\"$(MYBUILD)\"
LDFLAGS	 += -lpthread -lrt -ldl -lcrypt -lpq 	-lreadline -fpermissive -Wno-error=terminate 
## To be populated by Makefrag files
CPPFLAGS += -I /usr/include/postgresql 
LDFLAGS += -L /opt/pgsql/lib
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
	$(CXX) -MD $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(OBJDIR)/%.cc
	@mkdir -p $(@D)
	$(CXX) -MD $(CXXFLAGS) -c $< -o $@

include crypto/Makefrag
include parser/Makefrag
include main/Makefrag
# include test/Makefrag
include util/Makefrag
include udf/Makefrag
#= include mysqlproxy/Makefrag
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