#include <stdlib.h>

double** mat_cria(int m, int n)
{
	double** A;
	int i;
	A = (double**)malloc(m*sizeof(double*));
	for(i=0; i < m; i++)
	{
		A[i] = (double*)malloc(n*sizeof(double));
	}
	return A;
}

void mat_libera(int m, double** A)
{
	int i;
	for(i=0; i < m; i++)
	{
		free(A[i]);
	}
	free(A);
}

void mat_transposta(int m, int n, double** A, double** T)
{
	int i, j;
	for(i=0; i < m; i++)
	{
		for(j=0;j < n; j++)
		{
			T[j][i] = A[i][j];
		}
	}
}
void mat_multv(int m, int n, double** A, double* v, double* w)
{
/* matriz MxN . vetor Nx1 -> vetor Mx1*/
	int i, j;
	for(i = 0; i < m; i++)
		w[i] = 0;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			w[i] += A[i][j] * v[j];
		}
	}
}
void mat_multm(int m, int n, int q, double** A, double** B, double** C)
{
	int i, j, k, soma = 0;
	for(i = 0; i < m; i ++)
	{
		for(j = 0; j < q; j++)
		{
			C[i][j] = 0;
		}
	}
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < q; j++)
		{
			for(k = 0; k < n; k++)
			{
				soma+= A[i][k] * B[k][j];
			}
			C[i][j] = soma;
			soma = 0;
		}
	}
}
