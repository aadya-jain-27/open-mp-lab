/* Experiment 6: Program to illustrate race conditions (OpenMP) */

#include <stdio.h>
#include <omp.h>

int main() {
    int counter = 0;

    #pragma omp parallel for
    for (int i = 0; i < 1000000; i++) {
        counter++;              // unprotected: threads overwrite each other
    }

    printf("Final counter value = %d\n", counter);
    printf("(Expected 1000000 - but it is usually less, that is the race condition)\n");
    return 0;
}
