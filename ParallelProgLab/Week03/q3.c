#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int rank, N, len, c = 0, *count;
    char str[50], *str2;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &N);

    if(rank == 0){
        printf("Enter a string: ");
        scanf("%s", str);
        len = strlen(str) / N;
    }

    MPI_Bcast(&len, 1, MPI_INT, 0, MPI_COMM_WORLD);

    str2 = (char *)malloc(len * sizeof(char));
    MPI_Scatter(str, len, MPI_CHAR, str2, len, MPI_CHAR, 0, MPI_COMM_WORLD);

    for(int i = 0; i < len; i++){
        if(str2[i] != 'a' && str2[i] != 'e' && str2[i] != 'i' && str2[i] != 'o' && str2[i] != 'u')
            c++;
    }

    count = (int *)malloc(N * sizeof(int));
    MPI_Gather(&c, 1, MPI_INT, count, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(rank == 0){
        c = 0;
        for(int i = 0; i < N; i++){
            c += count[i];
            printf("Rank: %d Recieved: %d\n", i, count[i]);
        }
        printf("Number of non-vowels: %d\n", c);
    }
    MPI_Finalize();
    return 0;
}