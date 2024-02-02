#include <stdio.h>
#include <mpi/mpi.h>
#define MCW MPI_COMM_WORLD
 
int main(int argc, char *argv[]){
    int rank, size, N, i;
    double sum = 0.0, x, y, area;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MCW, &rank);
    MPI_Comm_size(MCW, &size);
    MPI_Errhandler_set(MCW, MPI_ERRORS_RETURN);
    if(rank == 0){
        printf("Enter no of intervals: ");
        scanf("%d", &N);
    }
    MPI_Bcast(&N, 1, MPI_INT, 0, MCW);
    for(i = rank + 1; i <= N; i += size){
        x = (double) (i + 0.5) / N;
        sum += 4.0 / (1 + x * x);
    }
    y = sum / N;
    int error = MPI_Reduce(&y, &area, 1, MPI_DOUBLE, MPI_SUM, 0, MCW);
    if (error != MPI_SUCCESS) {
        char s[100];
        int len, class1;
        MPI_Error_string(error, s, &len);
        MPI_Error_class(error, &class1);
        printf("Error description is %s\n", s);
        printf("Error class is %d\n", class1);
        MPI_Finalize();
    }
    if(rank == 0)
        printf("Area: %f\n", area);
    MPI_Finalize();
    return 1;
}