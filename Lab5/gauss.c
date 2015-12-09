#include <stdio.h>

#include <stdlib.h>
#include "matriz.h"
#include "gauss.h"

/* Funções usadas pelo gauss.c */

double** gauss_elimination(double** A, int n, double fator[], int troca[]);
double modulo(double a);
 /**********************************/

/* Fatoração */

double** fatoracao( int n, double** A)
{
	int i, j, k, troca[3];
	double  fator[100];
	double** P = mat_cria(n,n);
	/* inicializa a atriz permutação */
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i != j)
				P[i][j] = 0;
			else
				P[i][j] = 1;
		}
	}

	// substituição
	A = gauss_elimination(A, n, fator, troca);

	// Substitui os termos que são 0 na matriz  triangular superior pelos fatores na eliminação de gauss
	// LU
	for(j = 0, k = 0; j < n-1; j++)
	{
		for(i = j; i < n; i++)
		{
			A[i][j] = fator[k];
			k++;
		}
	}
	
	// faz a troca na matriz permutação
	for(i = 0; i < n; i++)
		P[i] = P[troca[i]];
	return P;
}


double* substituicao (int n, double** A, double** P, double* b)
{
	double** L = mat_cria(n,n);
	double** U = mat_cria(n,n);
	double *x = (double*)malloc(sizeof(double));
	int i, j, k;

	// Constroi a matriz L (diagonal Inferior)
	for(j = 0; j < n; j++)
	{
		for(i = 0; i < n; i++)
		{
			if(i == j)
			{
				L[i][j] = 1;
			}
			else
			{
				if(i > j)
				{
					L[i][j] = 0;
				}
				else
				{
					L[i][j] = A[i][j];
				}
			}		
		}
	}

	// Constroi a matriz U (diagonal superior)
	for(j = 0; j < n; j++)
	{
		for(i = 0; i < n; i++)
		{
			if(i >= j)
			{
				U[i][j] = A[i][j];
			}
			else
			{
				U[i][j] = 0;
			}
		}
	}

	// BAsta fazer a retro substituição para achar a soluçao x
}

double modulo(double a)
{
	if(a<0)
		a*=-1;
	return a;
}

double** gauss_elimination(double** A, int n, double fator[], int troca[])
{
	int i, j, k, ixpivot ;
	double f, p1, p2, *temp;

	// eliminação
	for(j = 0; j < n-1; j++)
	{
		// pivotamento antes da substituição
		p1 = A[j][j]; p1 = modulo(p1);
		ixpivot = j;
		for(i=j+1; i < n; i++)
		{
			p2 = A[i][j]; p2 = modulo(p2);
			if(p2 > p1)
			{
				ixpivot = i;
				p1 = p2;
			}
		}
		// se pivot == 0 então o maior numero esta na primeira linha
		if(ixpivot != 0)
		{
			// faz a troca na matriz A
			temp = A[ixpivot];
			A[ixpivot] = A[j];
			A[j] = temp;
		}
		// armazena a troca no vetor de trocas
		troca[j] = ixpivot;

		for(i = j+1; i < n; i++)
		{
			f = A[i][j]/A[j][j];
			fator[j] = f;
			for(k = j; k < n; k++)
				A[i][k] = A[i][k] - A[j][k]*f;
		}
	}
	return A;
}