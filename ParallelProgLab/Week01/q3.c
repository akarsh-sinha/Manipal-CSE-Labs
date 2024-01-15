#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    int x=6,y=2,rank,s;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    switch(rank){
        case 0:
            printf("Addition: x+y = %d\n",x+y);
            break;
        case 1:
            printf("Subtraction: x-y = %d\n",x-y);
            break;
        case 2:
            printf("Multiplication: x*y = %d\n",x*y);
            break;
        case 3:
            printf("Division: x/y = %d\n",x/y);
            break;
        default:
            printf("Error!");
    }
    MPI_Finalize();
    return 0;
}