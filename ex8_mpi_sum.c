#include <mpi.h>
#include <stdio.h>

#define N 100

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int a[N];
    for (int i = 0; i < N; i++)
        a[i] = i + 1;

    int chunk = N / size;
    int start = rank * chunk;
    int end = (rank == size - 1) ? N : start + chunk;

    long local_sum = 0;
    for (int i = start; i < end; i++)
        local_sum += a[i];

    long total_sum = 0;
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
        printf("Sum of first %d numbers = %ld\n", N, total_sum);

    MPI_Finalize();
    return 0;
}
