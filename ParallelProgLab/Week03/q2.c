#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rank, n, m, *arr, *new_arr;
    float avg = 0.0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &n);
    
    if (rank == 0) {
        printf("Enter value of m: ");
        scanf("%d", &m);
        arr = (int *) malloc(n * m * sizeof(int));
        printf("Enter %d numbers: ", m * n);
        for (int i = 0; i < m * n; i++) 
            scanf("%d", &arr[i]);
    }
    
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    new_arr = (int *)malloc(m * n * sizeof(int));
    
    MPI_Scatter(arr, m, MPI_INT, new_arr, m, MPI_INT, 0, MPI_COMM_WORLD);
    
    for (int i = 0; i < m; i++)
        avg += (float) new_arr[i] / m;
    printf("Rank: %d Average: %f\n", rank, avg);

    float * avg_arr = (float *)malloc(n * sizeof(float));
    MPI_Gather(&avg, 1, MPI_FLOAT, avg_arr, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        avg = 0.0;
        for (int i = 0; i < n; i++)
            avg += avg_arr[i] / n;
        printf("Final average: %f\n", avg);
    }
    
    MPI_Finalize();
    return 0;
}