#!/usr/bin/bash
#SBATCH -N 1
#SBATCH -n 2
#SBATCH -t 00:02:00
#SBATCH -p pdebug
#SBATCH --job-name="MILC"

export I_MPI_EXTRA_FILESYSTEM=on
export I_MPI_EXTRA_FILESYSTEM_LIST=lustre
export OMP_NUM_THREADS=1

cd /g/g90/wang116/sources/pilgrim/test
#lfs setstripe -c 8 -S 4M ./

#LD_PRELOAD=/g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so srun ./a.out
LD_PRELOAD=/g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so srun ./a.out
