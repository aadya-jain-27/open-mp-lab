/* Experiment 4: Matrix addition using OpenMP
   Each row of the result matrix is computed by the parallel for loop. */

#include <stdio.h>
#include <omp.h>

#define N 3

int main() {
    int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[N][N];

    #pragma omp parallel for
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];

    printf("Resultant matrix (A + B):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%4d", C[i][j]);
        printf("\n");
    }
    return 0;
}
