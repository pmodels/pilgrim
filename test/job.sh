#!/usr/bin/bash
#SBATCH -N 22
#SBATCH -n 512
#SBATCH -t 00:10:00
#SBATCH -p pbatch
#SBATCH --job-name="3d stencil"

export I_MPI_EXTRA_FILESYSTEM=on
export I_MPI_EXTRA_FILESYSTEM_LIST=lustre
export OMP_NUM_THREADS=1

cd /g/g90/wang116/sources/pilgrim/test
#lfs setstripe -c 8 -S 4M ./

#LD_PRELOAD=/g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so srun ./a.out
for p in 2 4 8
do
    procs=$(( $p * $p * $p ))
    echo "[pilgrim CHEN]" $procs
    mpirun -np $procs -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./3d.out $p 10
done


for p in 2 4 8 16
do
    procs=$(( $p * $p ))
    echo "[pilgrim CHEN]" $procs
    mpirun -np $procs -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./2d.out $p $p 10
done

