#!/usr/bin/bash
#SBATCH -N 43
#SBATCH -n 1024
#SBATCH -t 01:30:00
#SBATCH -p pbatch
#SBATCH --job-name="NPB"

source /g/g90/wang116/.bash_profile

export I_MPI_EXTRA_FILESYSTEM=on
export I_MPI_EXTRA_FILESYSTEM_LIST=lustre
export OMP_NUM_THREADS=1

cd /p/lscratchh/wang116/applications/NPB3.4.1/NPB3.4-MPI/bin-pilgrim

echo "CHEN test for duration and interval"

#bt and sp require square number of processes.
bins=(bt.C.x sp.C.x)
for bin in ${bins[@]}
do
    echo "CHEN" $bin "16 64 256 1024"
    for procs in 16 64 256 1024
    do
        time mpirun -np $procs ./$bin
        time mpirun -np $procs -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./$bin
    done
done

#dt.C.x BH: the number of processes should >= number of nodes in graph(85 for BH and WH)
#echo "CHEN dt 128"
#mpirun -np 128 -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./dt.C.x BH
#echo "CHEN dt 256"
#mpirun -np 256 -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./dt.C.x BH


bins=(is.C.x cg.C.x lu.C.x mg.C.x)
for bin in ${bins[@]}
do
    echo "CHEN" $bin "8 16 32 64 128 256 512 1024"
    for procs in 8 16 32 64 128 256 512 1024
    do
        time mpirun -np $procs ./$bin
        time mpirun -np $procs -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./$bin
    done
done
