#include <stdio.h>
    #include <stdlib.h>
    #include <omp.h>
    #include <time.h>
    #define M 50 // Number of rows in the first matrix
    #define N 50 // Number of columns in the first matrix and rows in the second matrix
    #define P 50     // Number of columns in the second matrix
    
    int main() {
        clock_t endtime, starttime;
         starttime = clock();
        
    
    int A[M][N], B[N][P], C[M][P];
    
        // Initialize matrices A and B with some values
        // For simplicity, using sequential numbers
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = i + j;
            }
        }
    
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {
                B[i][j] = i * j;
            }
        }
    
        // Initialize matrix C to all zeros
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < P; j++) {
                C[i][j] = 0;
            }
        }
    
        // Perform matrix multiplication using OpenMP
        #pragma omp parallel for shared(A, B, C)
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < P; j++) {
                for (int k = 0; k < N; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        endtime = clock();
    
        // Print the result matrix
        printf("Result Matrix C:\n");
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < P; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
        
        
        printf("Time: %f",(float)(endtime-starttime)/CLOCKS_PER_SEC);
    
        return 0;
    }
    //time=0.000783