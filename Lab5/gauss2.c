#include <stdio.h>
#include <malloc.h>
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
	double** permutacao = mat_cria(n,n);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i != j)
				permutacao[i][j] = 0;
			else
				permutacao[i][j] = 1;
		}
	}

	// substituição
	for(j = 0; j < n-1; j++)
	{
		index = j;
		n1 = fmod(A[j][j]);
		for(i=j+1; i < n; i++)
		{
			n2 = fmod(A[i][j]); 
			if(n2 > n1)
			{
				index = i;
				p1 = p2;
			}
		}
		if(index != 0)
		{
			temp = A[j];
			A[j] = A[index];
			A[index] = temp;
		}
	
		permutacao = permutacao[index];

		for(i = j+1; i < n; i++)
		{
			fatores[j] = A[i][j]/A[j][j];
			for(w = j; w < n; w++)
				A[i][w] = A[i][w] - A[j][w]*fatores[j];
		}
	}

	// Substitui os termos que são 0 na matriz  triangular superior pelos fatores na eliminação de gauss
	// LU
	for(j = 0, k = 0; j < n-1; j++)
	{
		for(i = j; i < n; i++)
		{
			A[i][j] = fatores[k];
			k++;
		}
	}
	
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
