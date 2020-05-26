##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

AM_CPPFLAGS += -I$(top_srcdir)/src

libpilgrim_la_SOURCES += \
	src/pilgrim_wrappers.c src/pilgrim_utils.c src/pilgrim_logger.c src/pilgrim_init_finalize.c
