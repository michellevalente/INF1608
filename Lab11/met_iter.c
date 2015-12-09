#include <stdio.h>
#include <math.h>
#include "matriz.h"

double norma2(int n, double * v)
{
	int i;
	double soma = 0;
	for(i = 0; i < n; i++)
	{
		soma += v[i] * v[i];
	}
	return sqrt(soma);
}

void copia_matriz(int m, int n, double ** m1, double m2[m][n]){
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			m1[i][j] = m2[i][j];
		}
	}
}

int Jacobi (int n, double **A, double *b, double* x, double tol)
{
	int i,j;
	double soma = 0, soma2 = 0;
	double dif[n];
	double x2[n],norma = 10000;
	int it = 0;
	double ** D = mat_cria(n,n);
	double ** R = mat_cria(n,n);
	double temp[n];
	double temp2[n];

	// Matriz D-1
	for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	    {    
	    	if(i==j)
	        	D[i][j]=1/A[i][j];
	        else
	        	D[i][j]=0;
	    }

	// Matriz L+U
	for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	    {    
	    	if(i==j)
	        	R[i][j]=0;
	        else
	        if(i!=j)
	        	R[i][j]=A[i][j];
	    }

	while(norma > tol)
	{
		it++;
		mat_multv(n, n, R, x, temp);
		for(i = 0; i < n; i++)
		{
			temp2[i] = b[i] - temp[i];
		}
		mat_multv(n, n, D, temp2, x2);

		for(i = 0; i < n; i++)
		{
			dif[i] = fabs(x[i] - x2[i]);
		}

		norma = norma2(n, dif);
		if (norma > tol)
			for(i = 0; i < n;i++)
				x[i] = x2[i];
	}
	return it;
}

int GaussSeibel(int n, double** A, double*b, double*x , double tol)
{
	int i, j, it = 0;
	double norma = 10000;
	double x2[n], dif[n];
	double c;

	for(i = 0; i < n; i++)
	{
		x2[i] = 0;
	}

	while(norma > tol)
	{
		it++;
		for(i = 0; i < n;i++)
		{
			c = 0;
			for(j = 0; j < i; j++)
			{
				c += A[i][j] * x2[j];
			}
			for(j = i + 1; j < n; j++)
			{
				c += A[i][j] * x[j];
			}

			x2[i] = (b[i] - c) / A[i][i];
		}


		for(i = 0; i < n; i++)
		{
			dif[i] = fabs(x[i] - x2[i]);
		}

		norma = norma2(n, dif);

		if (norma > tol)
			for(i = 0; i < n;i++)
				x[i] = x2[i];
	}
	return it;
}

int SOR(int n, double**A , double*b , double * x, double tol, double w)
{
	int i, j, it = 0;
	double norma = 10000;
	double x2[n], dif[n];
	double c;

	for(i = 0; i < n; i++)
	{
		x2[i] = 0;
	}

	while(norma > tol)
	{
		it++;
		for(i = 0; i < n;i++)
		{
			c = 0;
			for(j = 0; j < i; j++)
			{
				c += A[i][j] * x2[j];
			}
			for(j = i + 1; j < n; j++)
			{
				c += A[i][j] * x[j];
			}

			x2[i] = (b[i] - c) / A[i][i];
		}

		for(i = 0; i < n ; i++)
		{
			x2[i] = (1 - w) * x[i] + w * x2[i];
		}

		for(i = 0; i < n; i++)
		{
			dif[i] = fabs(x[i] - x2[i]);
		}

		norma = norma2(n, dif);

		if (norma > tol)
			for(i = 0; i < n;i++)
				x[i] = x2[i];
	}
	return it;
}


int main()
{
	double A_temp[][2] = {{3,1}, {1,2}};
	double ** A = mat_cria(2,2);
	double A_temp2[][6]= {{3, -1, 0, 0, 0, 0.5}, 
						  {-1, 3, -1, 0, 0.5, 0},
						  {0, -1, 3, -1, 0, 0},
						  {0, 0, -1, 3, -1, 0},
						  {0, 0.5, 0, -1, 3, -1},
						  {0.5, 0, 0, 0, -1, 3}};
	double ** A2 = mat_cria(6,6);
	double b[2] = {5,5};
	double x[2] = {0,0};
	double b2[6] = {2.5, 1.5, 1, 1, 1.5, 2.5};
	double x2[6] = {0,0,0,0,0,0};
	int it;
	int i;
	double tol = pow(10,-7);

	copia_matriz(2,2,A, A_temp);
	copia_matriz(6,6,A2, A_temp2);

	for(i = 0; i < 2; i++)
	{
		x[i] = 0;
	}

	for(i = 0; i < 6; i++)
	{
		x2[i] = 0;
	}


	printf("Resultados para Jacobi: \n");

	printf("Resultado Exemplo1: \n");

	it  = Jacobi(2,A, b, x, tol);

	for(i = 0; i < 2;i++)
	{
		printf("%.2f ", x[i]);
	}

	printf("\n");

	printf("Iteracoes: %d\n", it);

	printf("Resultado Exemplo2: \n");

	it  = Jacobi(6,A2, b2, x2, tol);

	for(i = 0; i < 6;i++)
	{
		printf("%.2f ", x2[i]);
	}
	printf("\n");
	printf("Iteracoes: %d\n", it);

	printf("\n");
	for(i = 0; i < 2; i++)
	{
		x[i] = 0;
	}

	for(i = 0; i < 6; i++)
	{
		x2[i] = 0;
	}


	printf("Resultados para Gauss-Seibel: \n");

	printf("Resultado Exemplo1: \n");

	it  = GaussSeibel(2,A, b, x, tol);

	for(i = 0; i < 2;i++)
	{
		printf("%.2f ", x[i]);
	}

	printf("\n");

	printf("Iteracoes: %d\n", it);

	printf("Resultado Exemplo2: \n");

	it  = GaussSeibel(6,A2, b2, x2, tol);

	for(i = 0; i < 6;i++)
	{
		printf("%.2f ", x2[i]);
	}
	printf("\n");
	printf("Iteracoes: %d\n", it);

	printf("\n");

	printf("\n");
	for(i = 0; i < 2; i++)
	{
		x[i] = 0;
	}

	for(i = 0; i < 6; i++)
	{
		x2[i] = 0;
	}

	printf("Resultados para SOR: \n");

	printf("Resultado Exemplo1: \n");

	it  = SOR(2,A, b, x, tol, 1.1);

	for(i = 0; i < 2;i++)
	{
		printf("%.2f ", x[i]);
	}

	printf("\n");

	printf("Iteracoes: %d\n", it);

	printf("Resultado Exemplo2: \n");

	it  = SOR(6,A2, b2, x2, tol,1.1);

	for(i = 0; i < 6;i++)
	{
		printf("%.2f ", x2[i]);
	}
	printf("\n");
	printf("Iteracoes: %d\n", it);

	printf("\n");

	return 0;
}