/* Experiment 5: Program to illustrate the critical section (OpenMP)
   Many threads increment a shared counter. The critical section lets only
   one thread update it at a time, so the final value is always correct. */

#include <stdio.h>
#include <omp.h>

int main() {
    int counter = 0;

    #pragma omp parallel for
    for (int i = 0; i < 1000; i++) {
        #pragma omp critical
        {
            counter++;             
        }
    }

    printf("Final counter value = %d\n", counter);
    printf("(Expected 1000 - the critical section prevents lost updates)\n");
    return 0;
}
