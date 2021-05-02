# Pilgrim

A scalable and (near) lossless MPI Tracing library

## Install
```bash
cd /PATH/TO/pilgrim
./autogen.sh
./configure
# Memory pointer (void*) type parameters are not stored by default.
# To enable it, use ./configure --enable-pointers 
make
make install prefix=`pwd`   // install to the current directory
```




## Usage
```bash
mpirun -np N -env LD_PRELOAD /PATH/TO/pilgrim/lib/libpilgrim.so ./your_app
```
mpirun can be replaced with your job scheduler, e.g., srun.


## Environment Variables

**PILGRIM_TIMING_MODE**: 0, 1, 2

0: store aggregated timing infomration, i.e., average duration for each call signature

1: store non-aggregated timing infomration, i.e., lossy duration and interval for each call. We use context-free-grammars to compress them.

2: Store lossless timing information. In this mode, we write to a single file a list of durations or intervals per call signature in a lossless manner.




