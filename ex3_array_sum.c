/* Experiment 3: Sum of array elements using the parallel clause (OpenMP)
   The reduction clause gives each thread a private copy of sum and safely
   adds them all together at the end. */

#include <stdio.h>
#include <omp.h>

#define N 100

int main() {
    int a[N];
    long sum = 0;

    for (int i = 0; i < N; i++)
        a[i] = i + 1;                 // fill array with 1, 2, 3, ... 100

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++)
        sum += a[i];

    printf("Sum of first %d numbers = %ld\n", N, sum);
    return 0;
}
