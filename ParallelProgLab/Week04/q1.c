#include <stdio.h>
#include "mpi/mpi.h"
#define MCW MPI_COMM_WORLD

int main(int argc, char *argv[]){
    int rank, N, fact = 1, factsum, i;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MCW, &rank);
    MPI_Comm_size(MCW, &N);
    MPI_Errhandler_set(MCW, MPI_ERRORS_RETURN);
    int error;
    error = MPI_Bcast(&fact, 1, MPI_INT,4, MPI_COMM_WORLD);
    if (error != MPI_SUCCESS) {
        char s[100];
        int len, class1;
        MPI_Error_string(error, s, &len);
        MPI_Error_class(error, &class1);
        printf("Error description is %s\n", s);
        printf("Error class is %d\n", class1);
        MPI_Finalize();
    }
    for(i = 1; i <= rank + 1; i++)
        fact *= i;
    MPI_Scan(&fact, &factsum, 1, MPI_INT, MPI_SUM, MCW);
    if(rank == N - 1)
        printf("Sum of factorials: %d\n", factsum);
    MPI_Finalize();
    return 0; 
}