##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

AM_CPPFLAGS += -I$(top_srcdir)/src

libpilgrim_la_SOURCES += \
	src/pilgrim_wrappers.c src/pilgrim_utils.c src/pilgrim_logger.c src/pilgrim_init_finalize.c src/pilgrim_wrappers_special.c \
	src/pilgrim_sequitur.c  src/pilgrim_sequitur_digram.c  src/pilgrim_sequitur_symbol.c src/pilgrim_sequitur_logger.c


pilgrim_reader_SOURCES += \
	src/pilgrim_reader.c src/pilgrim_read_args.c src/pilgrim_read_args_special.c
