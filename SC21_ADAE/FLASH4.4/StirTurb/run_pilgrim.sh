#!/usr/bin/bash
#SBATCH -N 171
#SBATCH -n 4096
#SBATCH -t 01:00:00
#SBATCH -p pbatch
#SBATCH --job-name="StirTurb"


export I_MPI_EXTRA_FILESYSTEM=on
export I_MPI_EXTRA_FILESYSTEM_LIST=lustre
export OMP_NUM_THREADS=1
#export ROMIO_PRINT_HINTS=1

cd /p/lscratchh/wang116/applications/FLASH4.4/StirTurb_3d_noio_nb32
sed -i "s/nend = .*/nend = 500/g" ./flash.par


# 64-1024
for p in 4 8 16 32 64
do
    sed -i "s/iProcs = .*/iProcs = 4/g" ./flash.par
    sed -i "s/jProcs = .*/jProcs = 4/g" ./flash.par
    sed -i "s/kProcs = .*/kProcs = ${p}/g" ./flash.par
    procs=$(( 16 * $p))
    echo "CHEN" $procs

    time mpirun -np $procs ./flash4_32

    time mpirun -np $procs -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./flash4_32

    time mpirun -np $procs ./flash4_32_st
    mv trace_$procs ./sttraces/
done

# 2048-4096
for p in 32 64
do
    sed -i "s/iProcs = .*/iProcs = 8/g" ./flash.par
    sed -i "s/jProcs = .*/jProcs = 8/g" ./flash.par
    sed -i "s/kProcs = .*/kProcs = ${p}/g" ./flash.par
    procs=$(( 64 * $p))
    echo "CHEN" $procs

    time mpirun -np $procs ./flash4_32

    time mpirun -np $procs -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./flash4_32

    time mpirun -np $procs ./flash4_32_st
    mv trace_$procs ./sttraces/
done


procs=4096
for iters in {700..1000..100}
do
    sed -i "s/nend = .*/nend = ${iters}/g" ./flash.par
    echo "CHEN" $iters

    time mpirun -np $procs ./flash4_32
    time mpirun -np $procs -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./flash4_32

    time mpirun -np $procs ./flash4_32_st
    mv trace_$procs ./sttraces/iter_$iters
done

sed -i "/says/d" ./slurm*.out
