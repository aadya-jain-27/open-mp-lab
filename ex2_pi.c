/* Experiment 2: OpenMP program to compute the value of Pi
   Uses numerical integration of 4/(1+x*x) from 0 to 1, which equals Pi. */

#include <stdio.h>
#include <omp.h>

#define NUM_STEPS 100000000

int main() {
    long i;
    double step = 1.0 / (double) NUM_STEPS;
    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < NUM_STEPS; i++) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    double pi = step * sum;
    printf("Value of Pi = %.15f\n", pi);
    return 0;
}
