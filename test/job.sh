#!/usr/bin/bash
#SBATCH -N 1
#SBATCH -n 2
#SBATCH -t 00:01:00
#SBATCH -p pbatch
#SBATCH --job-name="2d stencil"

export I_MPI_EXTRA_FILESYSTEM=on
export I_MPI_EXTRA_FILESYSTEM_LIST=lustre
export OMP_NUM_THREADS=1

export PILGRIM_DEBUG=1

cd /g/g90/wang116/sources/pilgrim/test

#LD_PRELOAD=/g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so srun ./a.out
p=8
for iters in 100
do
    procs=$(( $p * $p ))

    export PILGRIM_TIMING_MODE=TEXT
    mpirun -np 2 -env LD_PRELOAD $libpilgrim ./pingpong.out $iters

    export PILGRIM_TIMING_MODE=CFG
    mpirun -np 2 -env LD_PRELOAD $libpilgrim ./pingpong.out $iters

    export PILGRIM_TIMING_MODE=SZ
    mpirun -np 2 -env LD_PRELOAD $libpilgrim ./pingpong.out $iters

    export PILGRIM_TIMING_MODE=ZFP
    mpirun -np 2 -env LD_PRELOAD $libpilgrim ./pingpong.out $iters

done
