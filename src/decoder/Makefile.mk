##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

AM_CPPFLAGS += -I$(top_srcdir)/src

pilgrim_decoder_SOURCES += \
	src/decoder/pilgrim_reader.c src/decoder/pilgrim_read_args.c \
	src/decoder/pilgrim_read_args_special.c src/dlmalloc.c
