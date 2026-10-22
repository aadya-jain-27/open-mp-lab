

#include <stdio.h>
#include <omp.h>

#define THREADS 4
#define WORK 100000000    
#define PAD 8             

int main() {
    omp_set_num_threads(THREADS);

    /* WITH false sharing */
    long a[THREADS] = {0};               
    double t1 = omp_get_wtime();
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        for (long i = 0; i < WORK; i++)
            a[id]++;                     
    }
    double t2 = omp_get_wtime();

    /* WITHOUT false sharing */
    long b[THREADS][PAD] = {{0}};    
    double t3 = omp_get_wtime();
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        for (long i = 0; i < WORK; i++)
            b[id][0]++;                  // padded apart, no false sharing
    }
    double t4 = omp_get_wtime();

    printf("With false sharing    : %f seconds\n", t2 - t1);
    printf("Without false sharing : %f seconds\n", t4 - t3);
    printf("(Padding the data apart removes false sharing and runs faster)\n");
    return 0;
}
