##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

include $(top_srcdir)/test/Makefile_common.mtest

#EXTRA_DIST = testlist

## for all programs that are just built from the single corresponding source
## file, we don't need per-target _SOURCES rules, automake will infer them
## correctly
noinst_PROGRAMS =  \
    anyall         \
    bottom         \
    bsend1         \
    bsend2         \
    bsend3         \
    bsend4         \
    bsend5         \
    bsendalign     \
    cancelrecv     \
    cancelanysrc   \
    isendself      \
	issendselfcancel \
	isendirecv     \
    eagerdt        \
    isendselfprobe \
    bsendfrag      \
    bsendpending   \
    icsend         \
    icprobe        \
    rqstatus       \
    rqfreeb        \
    greq1          \
    scancel        \
    scancel2       \
    rcancel        \
    pscancel       \
    scancel_unmatch\
    sendflood      \
    sendrecv2      \
    sendrecv3      \
    waitany_null   \
    probe_unexp    \
    probenull      \
    inactivereq    \
    waittestnull   \
    sendall        \
    large_message  \
    mprobe         \
    big_count_status	\
    many_isend     \
    manylmt        \
    huge_underflow \
    huge_anysrc    \
    huge_dupcomm   \
    huge_ssend     \
    multi_psend_derived  \
    dtype_send		 \
    recv_any		\
    irecv_any   \
    large_tag \
    precv_anysrc \
    precv_anysrc_exp

irecv_any_CPPFLAGS = -DTEST_NB $(AM_CPPFLAGS)
irecv_any_SOURCES  = recv_any.c
