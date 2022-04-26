#include <stdio.h>
#include <mpi.h>
#include <omp.h>

void comp(float* x, int npoints) {
    int me, nt, ipoints, istart, i;

    #pragma omp parallel default(shared) private(me, nt, ipoints, istart, i)
    {
        me = omp_get_thread_num();
        nt = omp_get_num_threads();
        printf("me: %d, nt: %d\n", me, nt);
        ipoints = npoints / nt;
        istart = me * ipoints;
        if (me == nt-1)     // last thread may do more
            ipoints = npoints - istart;

        // real work
        for (i = istart; i < ipoints; i++)
            x[i] = 123.456;
    }
}

int main(int argc, char* argv[]) {
    int provided;
    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);

    /*
    omp_set_num_threads(2);
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("section 1\n");
        }

        #pragma omp section
        {
            printf("section 2\n");
        }
    }   // There is an implied barrier at the end
    */



    omp_set_num_threads(4);
    int a[101];
    int b[100];

    printf("start of omp for loop\n");
    #pragma omp parallel for
    for(int i = 0; i < 100; i++) {
        b[i] = (a[i] + a[i+1]) / 2;
    }
    printf("end of omp for loop\n");


    #pragma omp parallel default(none)
    {
        #pragma omp single
        {
            #pragma omp task
            {
                printf("task 1\n");
            }
            #pragma omp taskwait

            #pragma omp task
            {
                printf("task 2\n");
            }
            #pragma omp taskwait
        }
    }


    #pragma omp barrier
    const int N = 10000;
    float x[N];
    comp(x, N);
    printf("end of omp parallel construct\n");


    MPI_Finalize();
    return 0;
}
