##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

AM_CPPFLAGS += -I$(top_srcdir)/src

pilgrim2text_SOURCES += \
	src/pilgrim_to_text/pilgrim2text.c \
	src/pilgrim_to_text/pilgrim_cfg_decoder.c src/pilgrim_to_text/pilgrim_cst_decoder.c \
	src/decoder/pilgrim_read_args.c src/decoder/pilgrim_read_args_special.c \
	src/dlmalloc.c

##pilgrim2text_LDFLAGS = -lm
