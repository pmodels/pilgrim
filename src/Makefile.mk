##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

AM_CPPFLAGS += -I$(top_srcdir)/src

libpilgrim_la_SOURCES += \
	src/pilgrim_wrappers.c src/pilgrim_utils.c src/pilgrim_logger.c \
	src/pilgrim_init_finalize.c src/pilgrim_wrappers_special.c \
	src/pilgrim_sequitur.c  src/pilgrim_sequitur_digram.c \
	src/pilgrim_sequitur_symbol.c src/pilgrim_sequitur_logger.c \
	src/pilgrim_sequitur_utils.c src/pilgrim_pattern_recognition.c\
	src/pilgrim_mem_hooks.c src/dlmalloc.c	src/pilgrim_addr_avl.c \
	src/pilgrim_mpi_objects.c src/pilgrim_timings.c
	##src/pilgrim_interval_tree.c
