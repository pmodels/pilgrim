##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
## 
ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = autogen.sh
EXTRA_PROGRAMS =

noinst_HEADERS =
include_HEADERS =
noinst_PROGRAMS =
nodist_noinst_SCRIPTS =
dist_noinst_SCRIPTS = autogen.sh

lib_LTLIBRARIES = libpilgrim.la
bin_PROGRAMS = pilgrim_app_generator pilgrim2text


libpilgrim_la_SOURCES =

pilgrim_app_generator_SOURCES = 
pilgrim_app_generator_CFLAGS = $(AM_CFLAGS)
pilgrim_app_generator_LDFLAGS = -lm

pilgrim2text_SOURCES = 
pilgrim2text_CFLAGS = $(AM_CFLAGS)
pilgrim2text_LDFLAGS = -lm


AM_CPPFLAGS = -g -rdynamic
AM_CFLAGS = -g -rdynamic

sz_LDFLAGS=

if WITH_SZ
sz_LDFLAGS+=-Wl,-rpath=$(SZ_DIR)/lib,-L$(SZ_DIR)/lib,-rpath=$(SZ_DIR)/lib64,-L$(SZ_DIR)/lib64,-lSZ
endif

zfp_LDFLAGS=
if WITH_ZFP
zfp_LDFLAGS+=-Wl,-rpath=$(ZFP_DIR)/lib,-L$(ZFP_DIR)/lib,-rpath=$(ZFP_DIR)/lib64,-L$(ZFP_DIR)/lib64,-lzfp
endif

libpilgrim_la_LDFLAGS = -lm -lzstd -pthread $(zfp_LDFLAGS) $(sz_LDFLAGS) -version-info @libpilgrim_so_version@

include $(top_srcdir)/src/Makefile.mk
include $(top_srcdir)/src/decoder/Makefile.mk
include $(top_srcdir)/include/Makefile.mk
