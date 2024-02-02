#include <stdio.h>
#include <mpi/mpi.h>
#include <stdlib.h>
#define MCW MPI_COMM_WORLD

int main(int argc, char* argv[]){
    int rank, size, error;
    int mat[4][4], fmat[4][4];
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MCW,MPI_ERRORS_RETURN);
    MPI_Comm_rank(MCW, &rank);
    MPI_Comm_size(MCW, &size);
    if(rank == 0){
        printf("Enter the elements in 4x4 matrix:\n");
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&mat[i][j]);
            }
        }
    }
    int mmat[4],smat[4];
    error = MPI_Scatter(mat, 4, MPI_INT, mmat, 4, MPI_INT, 0, MCW);
    if (error != MPI_SUCCESS) {
        char s[100];
        int len, class1;
        MPI_Error_string(error, s, &len);
        MPI_Error_class(error, &class1);
        printf("Error description is %s\n", s);
        printf("Error class is %d\n", class1);
        MPI_Finalize();
    }
    MPI_Scan(mmat, smat, 4, MPI_INT, MPI_SUM, MCW);
    MPI_Gather(smat, 4, MPI_INT, fmat, 4, MPI_INT, 0, MCW);
    if (rank == 0){
        printf("The final result is : \n");
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                printf("%d\t", fmat[i][j]);
            }
            printf("\n");
        }
    }
    MPI_Finalize();
    return 1;
}