##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

AM_CPPFLAGS = -I$(srcdir)/../include -I../include -I$(srcdir)/../dtpools/include

EXTRA_PROGRAMS = mtestcheck dtypes
mtestcheck_SOURCES = mtestcheck.c mtest.c mtest_common.c

EXTRA_LIBRARIES =
all_objs = mtest.$(OBJEXT) dtypes.$(OBJEXT)

#---- single ---------------------------------------------------------------------
all_objs += mtest_single.$(OBJEXT)

## another dummy library
EXTRA_LIBRARIES += libmtest_single.a
libmtest_single_a_SOURCES = mtest_single.c

#---- thread ---------------------------------------------------------------------
all_objs += mtest_thread.$(OBJEXT)

## another dummy library
EXTRA_LIBRARIES += libmtest_thread.a
libmtest_thread_a_SOURCES = mtest_thread.c

#---- all-local target -----------------------------------------------------------

all-local: $(all_objs)
