#!/bin/bash

attr_progs=($(ls -d /home/wangchen/Sources/mpich-3.4.2/test/mpi/attr/my-pilgrim-logs/*/))
errhan_progs=($(ls -d /home/wangchen/Sources/mpich-3.4.2/test/mpi/errhan/my-pilgrim-logs/*/))
datatype_progs=($(ls -d /home/wangchen/Sources/mpich-3.4.2/test/mpi/datatype/my-pilgrim-logs/*/))
group_progs=($(ls -d /home/wangchen/Sources/mpich-3.4.2/test/mpi/group/my-pilgrim-logs/*/))
info_progs=($(ls -d /home/wangchen/Sources/mpich-3.4.2/test/mpi/info/my-pilgrim-logs/*/))


pt2pt_progs=($(ls -d /home/wangchen/Sources/mpich-3.4.2/test/mpi/pt2pt/my-pilgrim-logs/*/))
coll_progs=($(ls -d /home/wangchen/Sources/mpich-3.4.2/test/mpi/coll/my-pilgrim-logs/*/))

generator=/home/wangchen/Sources/pilgrim/pilgrim_app_generator

for prog in ${pt2pt_progs[@]}
do
    echo $prog
    $generator $traces_dir/$prog
    mpicc $traces_dir/$prog/proxy_app.c -o /tmp/a.out
    echo "======================================="
done
