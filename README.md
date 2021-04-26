# Pilgrim

A scalable and (near) lossless MPI Tracing library

## Install
```bash
cd /PATH/TO/pilgrim
./autogen.sh
./configure
make
make install prefix=`pwd`   // install to the current directory
```

## Usage
```bash
mpirun -np N -env LD_PRELOAD /PATH/TO/pilgrim/lib/libpilgrim.so ./your_app
```

## Environment Variables

**PILGRIM_AGGREGATED_TIMINGS**: 1 or 0.

1: store aggregated timing infomration, i.e., average duration for each call signature

0: store non-aggregated timing infomration, i.e., lossy duration and interval for each call.



mpirun can be replaced with your job scheduler, e.g., srun.
