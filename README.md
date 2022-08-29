# Pilgrim

Pilgrim is a scalable and near lossless MPI Tracing library.
It is lossless for MPI functionality but lossy for non-MPI metadata.
Pilgrim captures the complete set of MPI calls and all their parameters.
To ensure completeness, the interception codes are generated automatically from the MPI standard.


## Building Pilgrim
```bash
cd /PATH/TO/pilgrim
./autogen.sh
./configure
make
make install prefix=`pwd`   // install to the current directory
```

### Configure Options:

(1) Storing parameters of CPU memory pointers

Pilgrim tracks memory management operations such as malloc, calloc, free, etc. 
The memory pointers are encoded in symbolic representations, which allows post-processings such as memory reuse analysis.
To store parameters of memory pointers, i.e., void*, use
```bash
./configure --enable-pointers
```

(2) Storing parameters of CUDA memory pointers

Pilgrim can also track CUDA memory operations such as cudaMalloc, cudaMallocPitch, cudaFree, etc.
In addition, the CUDA device where the memory was allocated is also preserved.
To enable this feature and store parameters of CUDA memory pointers, use
```bash
./configure --enable-cuda
```


(3) Storing thread id of each call

For multithreaded MPI programs, where MPI calls can be made from different threads, Pilgrim can preseve the thread id of each MPI call.
To enable this feature, use
```bash
./configure --enable-tid
```
Pilgrim supports all thread levels defined by the MPI standard.

(4) Specifying lossy timing compression library

Pilgrim provides three modes to store the timing information.
- Aggregated: Only store statistics of MPI functions, i.e., average duration and interval of each function.
- Lossless: Store each call's duration and interval in a lossless mode. Lossless compression algorithm [ZSTD](https://facebook.github.io/zstd/) can be used in this mode.
- Lossy: Store each call's duration and interval in a lossy mode. Several lossy algorithms are provided.
  The last two algorithms require external libraries [SZ](https://github.com/szcompressor/SZ) and [ZFP](https://github.com/szcompressor/SZ) to be installed.
  - CFG: Use the same context-free-grammar to store the timestamps.
  - HIST: Use the histogram-based compression algorithm.
  - SZ: Use the lossy compressor SZ. Require `./configure --with-sz=/path/to/sz`.
  - ZFP: Use the lossy compressor ZFP. Require `./configure --with-zfp=/path/to/zfp`.


## Usage
```bash
mpirun -np N -env LD_PRELOAD /PATH/TO/pilgrim/lib/libpilgrim.so ./your_app
```
mpirun can be replaced with your job scheduler, e.g., srun.

## Environment Variables

**PILGRIM_TIMING_MODE** can be set to one of the options below:
 - AGGREGATED: Store only statistics of each MPI function.
 - LOSSLESS: Store lossless timestamps without any compression.
 - ZSTD: Store lossless timestamps but with ZSTD compression.
 - CFG: Store lossy timestamps using the CFG compression algorithm.
 - HIST: Store lossy timestamps using the HIST compression algorithm.
 - SZ: Store lossy timestamps using the SZ lossy compressor.
 - ZFP: Store lossy timestamps using the ZFP lossy compressor.

**PILGRIM_TRACING_MODE**:
- DEFAULT:  Tracing is enabled by default. Call `MPI_Info_set(info, "PILGRIM_TRACING", "OFF")` to disable tracing and `MPI_Info_set(info, "PILGRIM_TRACING", "ON")` to enable tracing.
- DYNAMIC: Tracing is disabled by default. Call `MPI_Info_set(info, "PILGRIM_TRACING", "ON")` to enable tracing and `MPI_Info_set(info, "PILGRIM_TRACING", "OFF")` to disable tracing.

**PILGRIM_DEBUG**: set to 1 to allow debug output.

