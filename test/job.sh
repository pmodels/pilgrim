#!/usr/bin/bash
#SBATCH -N 8
#SBATCH -n 128
#SBATCH -t 00:10:00
#SBATCH -p pdebug
#SBATCH --job-name="3d stencil"

export I_MPI_EXTRA_FILESYSTEM=on
export I_MPI_EXTRA_FILESYSTEM_LIST=lustre
export OMP_NUM_THREADS=1

cd /g/g90/wang116/sources/pilgrim/test
#lfs setstripe -c 8 -S 4M ./

#LD_PRELOAD=/g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so srun ./a.out
for procs in 8 16 64 128
do
    echo "[pilgrim CHEN]" $procs
    mpirun -np $procs -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./a.out 10
done
