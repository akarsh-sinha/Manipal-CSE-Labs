#include "mpi.h"
#include <stdio.h>

int power(int x, unsigned int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}

int main(int argc, char *argv[]){
    int rank,x=3;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("Rank: %d 3^rank: %d\n",rank,power(x,rank));
    MPI_Finalize();
    return 0;
}