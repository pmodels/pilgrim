# pilgrim

MPI Tracing Library

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
LD_PRELOAD=/PATH/TO/pilgrim/lib/libpilgrim.so mpirun -np N ./your_app
```

mpirun can be replaced with your job scheduler, e.g., srun.
