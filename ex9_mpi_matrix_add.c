#include <mpi.h>
#include <stdio.h>

#define N 4

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int A[N][N], B[N][N], C[N][N];

    if (rank == 0) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                A[i][j] = i * N + j + 1;
                B[i][j] = i * N + j + 1;
            }
    }

    int rows = N / size;
    int subA[rows][N], subB[rows][N], subC[rows][N];

    MPI_Scatter(A, rows * N, MPI_INT, subA, rows * N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(B, rows * N, MPI_INT, subB, rows * N, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < N; j++)
            subC[i][j] = subA[i][j] + subB[i][j];

    MPI_Gather(subC, rows * N, MPI_INT, C, rows * N, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Resultant matrix (A + B):\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf("%4d", C[i][j]);
            printf("\n");
        }
    }

    MPI_Finalize();
    return 0;
}
