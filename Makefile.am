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


AM_CPPFLAGS = -g -rdynamic
AM_CFLAGS = -g -rdynamic

libpilgrim_la_LDFLAGS = -lm -version-info @libpilgrim_so_version@

include $(top_srcdir)/src/Makefile.mk
include $(top_srcdir)/src/decoder/Makefile.mk
include $(top_srcdir)/include/Makefile.mk
