##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

AM_CPPFLAGS += -I$(top_srcdir)/src

pilgrim_decompressor_SOURCES += \
	src/test/pilgrim_decompressor.c src/dlmalloc.c
pilgrim_decompressor_LDFLAGS = -lm
