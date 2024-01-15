#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    int rank,size;
    char str[]="HeLLO\0";
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(str[rank]>=65 && str[rank]<=90)
        str[rank]+=32;
    else if(str[rank]>=97 && str[rank]<=122)
        str[rank]-=32;
    printf("Rank: %d String: %s\n",rank,str);
    MPI_Finalize();
    return 0;
}