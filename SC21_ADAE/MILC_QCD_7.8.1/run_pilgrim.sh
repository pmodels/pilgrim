#!/bin/bash
#COBALT -A MPICH_MCS
#COBALT -n 256
#COBALT -t 360
#COBALT -q default

#-q debug-cache-quad
# -q default


module unload darshan
module load cray-hdf5-parallel/1.10.6.1

cd /projects/MPICH_MCS/wangvsa/applications/milc_qcd/clover_dynamical/
libpilgrim=/home/wangvsa/sources/pilgrim/.libs/libpilgrim.so

export OMP_NUM_THREADS=1
export DARSHAN_DISABLE=1
export DARSHAN_PRELOAD=

procs=64
sed -i "s/nx.*/nx 64/g" ./su3_rmd.1.sample-in
sed -i "s/ny.*/ny 64/g" ./su3_rmd.1.sample-in
sed -i "s/nz.*/nz 64/g" ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e LD_PRELOAD=$libpilgrim -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in

procs=128
sed -i "s/nx.*/nx 128/g" ./su3_rmd.1.sample-in
sed -i "s/ny.*/ny 64/g" ./su3_rmd.1.sample-in
sed -i "s/nz.*/nz 64/g" ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e LD_PRELOAD=$libpilgrim -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in


procs=256
sed -i "s/nx.*/nx 128/g" ./su3_rmd.1.sample-in
sed -i "s/ny.*/ny 128/g" ./su3_rmd.1.sample-in
sed -i "s/nz.*/nz 64/g" ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e LD_PRELOAD=$libpilgrim -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in

procs=512
sed -i "s/nx.*/nx 128/g" ./su3_rmd.1.sample-in
sed -i "s/ny.*/ny 128/g" ./su3_rmd.1.sample-in
sed -i "s/nz.*/nz 128/g" ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e LD_PRELOAD=$libpilgrim -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in

procs=1024
sed -i "s/nx.*/nx 256/g" ./su3_rmd.1.sample-in
sed -i "s/ny.*/ny 128/g" ./su3_rmd.1.sample-in
sed -i "s/nz.*/nz 128/g" ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e LD_PRELOAD=$libpilgrim -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in

procs=2048
sed -i "s/nx.*/nx 256/g" ./su3_rmd.1.sample-in
sed -i "s/ny.*/ny 256/g" ./su3_rmd.1.sample-in
sed -i "s/nz.*/nz 128/g" ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e LD_PRELOAD=$libpilgrim -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in

procs=4096
sed -i "s/nx.*/nx 256/g" ./su3_rmd.1.sample-in
sed -i "s/ny.*/ny 256/g" ./su3_rmd.1.sample-in
sed -i "s/nz.*/nz 256/g" ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e LD_PRELOAD=$libpilgrim -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in

procs=8192
sed -i "s/nx.*/nx 512/g" ./su3_rmd.1.sample-in
sed -i "s/ny.*/ny 256/g" ./su3_rmd.1.sample-in
sed -i "s/nz.*/nz 256/g" ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e LD_PRELOAD=$libpilgrim -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in

procs=16384
sed -i "s/nx.*/nx 512/g" ./su3_rmd.1.sample-in
sed -i "s/ny.*/ny 512/g" ./su3_rmd.1.sample-in
sed -i "s/nz.*/nz 256/g" ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e LD_PRELOAD=$libpilgrim -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in
time aprun -n $procs -cc depth -d1 -j1 -e OMP_NUM_THREADS=1 -e DARSHAN_DISABLE=1 ./su3_rmd < ./su3_rmd.1.sample-in
