#!/usr/bin/bash
#SBATCH -N 1
#SBATCH -n 16
#SBATCH -t 00:30:00
#SBATCH -p pbatch
#SBATCH --job-name="OSU-MPI"

export I_MPI_EXTRA_FILESYSTEM=on
export I_MPI_EXTRA_FILESYSTEM_LIST=lustre
export OMP_NUM_THREADS=1

cd /g/g90/wang116/softwares/osu-micro-benchmarks-5.7/install/libexec/osu-micro-benchmarks/mpi


onesided=(osu_acc_latency osu_cas_latency  osu_fop_latency  osu_get_acc_latency osu_get_bw osu_get_latency osu_put_bibw osu_put_bw osu_put_latency)
pt2pt=(osu_bibw  osu_bw  osu_latency  osu_latency_mp osu_mbw_mr  osu_multi_lat)
collective=(osu_allgather osu_alltoall osu_bcast osu_iallgather osu_ialltoall osu_ibarrier osu_igatherv osu_iscatterv osu_scatter \
osu_allgatherv osu_alltoallv osu_gather osu_iallgatherv osu_ialltoallv osu_ibcast osu_ireduce osu_reduce osu_scatterv \
osu_allreduce osu_barrier osu_gatherv osu_iallreduce osu_ialltoallw osu_igather osu_iscatter osu_reduce_scatter)

for app in ${onesided[@]}
do
    echo $app
    for procs in 2 4 8 16
    do
        LD_PRELOAD=/g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so srun -n $procs ./one-sided/$app
    done
done


procs=2
for app in ${pt2pt[@]}
do
    echo $app
    LD_PRELOAD=/g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so srun -n 2 ./pt2pt/$app
done


for app in ${collective[@]}
do
    echo $app
    for procs in 2 4 8 16
    do
        LD_PRELOAD=/g/g90/wang116/sources/pilgrim/.libs/libpilgrim.so srun -n $procs ./collective/$app
    done
done
