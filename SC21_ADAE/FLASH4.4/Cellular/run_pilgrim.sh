#!/usr/bin/bash
#SBATCH -N 171
#SBATCH -n 4096
#SBATCH -t 05:00:00
#SBATCH -p pbatch
#SBATCH --job-name="Celluar"

export I_MPI_EXTRA_FILESYSTEM=on
export I_MPI_EXTRA_FILESYSTEM_LIST=lustre
export OMP_NUM_THREADS=1
#export ROMIO_PRINT_HINTS=1

cd /p/lscratchh/wang116/applications/FLASH4.4/Cellular_noio
sed -i "s/nend = .*/nend = 100/g" ./flash.par
#rm -rf ./sttraces/*

for procs in 64 128 256 512 1024 2048 4096
do
    echo "CHEN" $procs
    time mpirun -np $procs ./flash4

    time mpirun -np $procs -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./flash4

    time mpirun -np $procs ./flash4_st
    mv trace_$procs ./sttraces/
done


procs=4096
#for iters in {100..1000..100}
for iters in {800..1000..100}
do
    echo "CHEN [pilgrim] nend = ${iters}"
    sed -i "s/nend = .*/nend = ${iters}/g" ./flash.par

    time mpirun -np $procs ./flash4

    time mpirun -np $procs -env LD_PRELOAD /g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so ./flash4

    time mpirun -np $procs ./flash4_st
    mv trace_$procs ./sttraces/iter_$iters
done

sed -i "/says/d" ./slurm*.out
