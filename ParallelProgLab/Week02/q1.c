#include "mpi.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    int rank, size, length;
    char str[20];
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank == 0){
        printf("Enter a string: ");
        scanf("%s", &str);
        length = strlen(str);
        MPI_Ssend(&length, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        MPI_Ssend(str, length, MPI_CHAR, 1, 2, MPI_COMM_WORLD);
        MPI_Recv(str, length, MPI_CHAR, 1, 3, MPI_COMM_WORLD, &status);
        printf("After toggle: %s\n", str);
    }
    else{
        MPI_Recv(&length, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        MPI_Recv(str, length, MPI_CHAR, 0, 2, MPI_COMM_WORLD, &status);
        for(int i = 0; i < length; i++){
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            else if(str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
        }
        MPI_Ssend(str, length, MPI_CHAR, 0, 3, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}