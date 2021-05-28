# Pilgrim

A scalable and (near) lossless MPI Tracing library

## Install
```bash
cd /PATH/TO/pilgrim
./autogen.sh
./configure

# Pilgrim can track memory buffer allocations
# and store memory pointer (void*) type parameters.
# To enable it, use ./configure --enable-pointers

# Pilgrim can also intercepts CUDA memory operations to track
# memory buffer locations, e.g., GPU device number.
# To enable this feature, use ./configure --enable-cuda

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

0: Store aggregated timing infomration, i.e., average duration for each call signature

1: Store non-aggregated timing infomration, i.e., lossy duration and interval for each call. We use context-free-grammars to compress them.

2: Store lossless timing information. In this mode, we write to a single file a list of durations or intervals per call signature in a lossless manner.




