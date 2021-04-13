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

mpirun can be replaced with your job scheduler, e.g., srun.
