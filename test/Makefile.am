##                                             
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
## 

noinst_PROGRAMS = 
noinst_HEADERS = mpi/include/mpitest.h mpi/include/mpicolltest.h 		\
				 mpi/include/mpitestcxx.h mpi/include/mpithreadtest.h	\
				 mpi/include/dtypes.h mpi/rma/squelch.h
nodist_noinst_HEADERS = mpi/include/mpitestconf.h

SUBDIRS = tracing 		\
		  mpi/misc		\
		  mpi/pt2pt		\
		  mpi/coll


testing:
	cd mpi/pt2pt && $(MAKE) testing

#cd mpi/coll && $(MAKE) testing
