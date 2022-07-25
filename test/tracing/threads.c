#include <pthread.h>
#include <stdio.h>
#include <mpi.h>


void* func(void* arg) {
    pthread_t tid = pthread_self();
    printf("[child] show my tid:%ld\n", tid);
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("[child] mpi size: %d, mpi rank: %d\n", size, rank);

    /*
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
    */

    return NULL;
}

int main(int argc, char* argv[]) {
    int provided;
    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);

    /*
    void* res;
    pthread_t tid;

    pthread_create(&tid, NULL, func, NULL);
    printf("[parent] show child tid:%ld\n", tid);
    pthread_join(tid, &res);

    pthread_create(&tid, NULL, func, NULL);
    printf("[parent] show child tid:%ld\n", tid);
    pthread_join(tid, &res);

    pthread_create(&tid, NULL, func, NULL);
    printf("[parent] show child tid:%ld\n", tid);
    pthread_join(tid, &res);
    */

    MPI_Finalize();
    return 0;
}
