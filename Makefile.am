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
bin_PROGRAMS = pilgrim_decoder pilgrim_decompressor


libpilgrim_la_SOURCES =

pilgrim_decoder_SOURCES = 
pilgrim_decoder_CFLAGS = $(AM_CFLAGS)

pilgrim_decompressor_SOURCES = 
pilgrim_decompressor_CFLAGS = $(AM_CFLAGS)


AM_CPPFLAGS = -g -rdynamic
AM_CFLAGS = -g -rdynamic

libpilgrim_la_LDFLAGS = -lcuda -lcudart -lm -version-info @libpilgrim_so_version@

include $(top_srcdir)/src/Makefile.mk
include $(top_srcdir)/src/decoder/Makefile.mk
include $(top_srcdir)/src/test/Makefile.mk
include $(top_srcdir)/include/Makefile.mk
