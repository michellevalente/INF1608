#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


//assert: m * n will not be as greater to an overflow
double** mat_cria(int m, int n) 
{
    
	double** mat = calloc(sizeof(double*), m);
	for (m -= 1; m+1; m--) {
	    mat[m] = calloc(sizeof(double), n);
	}
	
	return mat;
}

//assert: A is a valid pointer to a double**
//assert: let i:=0...m,  A[i] is a valid pointer to a double*
void mat_libera(int m, double** A)
{
    for (m-=1;m+1;m--) {
        free(A[m]);
    }
    free(A);
}

//assert: A and T are allocated and same size;
void mat_transposta(int m, int n, double** A, double** T)
{
    int i,j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            T[j][i] = A[i][j];
        }
    }
}


//assert: A is a valid pointer to (double**)
//assert: A is a allocated m x n matrix (double**)
//assert: v is a allocated vector of size n
//assert: w is a allocated vector of size m
void mat_multv(int m, int n, double** A, double* v, double* w) 
{
    int i,j;
    
    for (i = 0; i < m; i++) {
        w[i] = 0.0;
        for (j = 0; j < n; j++) {
            w[i] += A[i][j] * v[j];
        }
    }
    
     
}

//assert: A and B are valid pointers to some double**
//assert: let i:=0...m,  A[i] is a valid pointer to a double*
//assert: let i:=0...n,  B[i] is a valid pointer to a double*
void mat_multm(int m, int n,int q, double** A, double** B, double** C) 
{
    int i,j,k;
    
    for (i = 0; i < m; i++) {
        
        //erasing C[i];
        for (k = 0; k < q; k++) {
            C[i][k] = 0.0;
        }
        
        for (j = 0; j < n; j++) {
            for (k = 0; k < q; k++) {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }
        
}

void teste_imprimi (int m, int n, double** A)
{
	int i,j;

	printf ("\nMATRIZ\n\n");

	for (i=0; i<3;i++)
	{
		for (j=0; j<1;j++)
		{
			printf("%g %g %g\n",A[i][j],A[i][j+1],A[i][j+2]);

		}

	}

		printf ("\n\n\n\n\n");

}