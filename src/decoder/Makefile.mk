##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

AM_CPPFLAGS += -I$(top_srcdir)/src

pilgrim_app_generator_SOURCES += \
	src/decoder/pilgrim_app_generator.c \
	src/decoder/pilgrim_metadata_decoder.c \
	src/decoder/pilgrim_cfg_decoder.c src/decoder/pilgrim_cst_decoder.c \
	src/decoder/pilgrim_read_args.c src/decoder/pilgrim_read_args_special.c \
	src/dlmalloc.c

pilgrim2text_SOURCES += \
	src/decoder/pilgrim2text.c \
	src/decoder/pilgrim_metadata_decoder.c \
	src/decoder/pilgrim_cfg_decoder.c src/decoder/pilgrim_cst_decoder.c \
	src/decoder/pilgrim_read_args.c src/decoder/pilgrim_read_args_special.c \
	src/dlmalloc.c
