/* Experiment 1: Program to compute rank and size of processes (OpenMP)
   Each thread prints its own rank (id) and the total number of threads. */

#include <stdio.h>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int rank = omp_get_thread_num();    // rank (id) of this thread
        int size = omp_get_num_threads();   // total number of threads

        printf("Hello from thread %d of %d\n", rank, size);
    }
    return 0;
}
