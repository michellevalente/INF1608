#include <stdio.h>
#include <math.h>
#include "matriz.h"

void Cholesky (int n, double** A);
void ConjugateGradient (int n, double** A, double* b, double* x); 

void print_matriz(int n, double ** A)
{
    int i,k;
    for(i = 0; i < n; i++)
    {
        for(k =0; k< n; k++)
        {
            printf("%.1f ", A[i][k]);
        }

        printf("\n");
    }
}
void print_vetor(int n, double *A)
{
    int i,k;
    for(i = 0; i < n; i++)
    {
        printf("%.1f ", A[i]);
    }
    printf("\n");
}

int main(void) 
{

	double** mat1 = mat_cria(3,3);
	double** mat2 = mat_cria(3,3);

	double b1[3] = {0,2,3};
	double b2[3] = {3,-3,4};

	double x1[3] = {0,0,0};
	double x2[3] = {0,0,0};

	mat1[0][0] = 1;
	mat1[0][1] = -1;
	mat1[0][2] = 0;
	mat1[1][0] = -1;
	mat1[1][1] = 2;
	mat1[1][2] = 1;
	mat1[2][0] = 0;
	mat1[2][1] = 1;
	mat1[2][2] = 2;

	mat2[0][0] = 1;
	mat2[0][1] = -1;
	mat2[0][2] = 0;
	mat2[1][0] = -1;
	mat2[1][1] = 2;
	mat2[1][2] = 1;
	mat2[2][0] = 0;
	mat2[2][1] = 1;
	mat2[2][2] = 5;

	//print_matriz(3,mat1);
	Cholesky(3,mat1);
	Cholesky(3,mat2);

	ConjugateGradient(3,mat1,b1,x1);

	print_vetor(3,x1);

	//print_matriz(3,mat2);

	ConjugateGradient(3,mat2,b2,x2);

	print_vetor(3,x2);
}

void Cholesky (int n, double** A)
{

	int i,k,j;
	double** ut;
	double** u;
	double** mul;
	double sum, Rkk;

	mul = mat_cria(n,n);

	for (k = 0; k < n; ++k)
	{
		ut = mat_cria(n,n);
		u = mat_cria(n,n);

		A[k][k] = sqrt(A[k][k]);

		for(i = k + 1; i < n; ++i) 
		{

			ut[k][i] = (1/A[k][k])*A[k][i]; 
		}

		mat_transposta(n,n,ut,u);
		mat_multm(n,n,n,u,ut,mul);

		for(i = k + 1; i < n; ++i) 
		{
			for (j = k + 1; j < n; ++j)
			{
				A[i][j] = A[i][j] - mul[i][j];
			}
		}
	}

	for (i = 1; i < n; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			A[i][j] = 0;
		}
	}
}

void ConjugateGradient (int n, double** A, double* b, double* x)
{

	double xk[n];
	double dk[n];
	double rk[n]; 

	double xk1[n];
	double dk1[n];
	double rk1[n]; 

	double dn[n];

	double alpha,beta,n1,n2;
	int i,j,k,stop;

	mat_multv(n,n,A,x,dk);

	for (i = 0; i < n; ++i)
	{
		rk[i] = b[i] - dk[i];
		dk[i] = rk[i];
	}

	for (k = 0; k < n; ++k)
	{
		stop = 1;

		for (i = 0; i < n; ++i)
		{
			if(rk[i] != 0) 
			{
				stop = 0;
			}
		}

		if(stop == 1) 
		{
			for (i = 0; i < n; ++i)
			{
				x[i] = x[i];
			}
			return;
		}

		n1 = 0;

		for (i = 0; i < n; ++i)
		{
			n1 += rk[i] * rk[i];
		}

		mat_multv(n,n,A,dk,dn);

		n2 = 0;

		for (i = 0; i < n; ++i)
		{
			n2 += dk[i] * dn[i];
		}

		alpha = n1/n2;

		for (i = 0; i < n; ++i)
		{
			xk1[i] = x[i] + alpha * dk[i];
			rk1[i] = rk[i] - alpha * dn[i];
		}

		n2 = 0;

		for (i = 0; i < n; ++i)
		{
			n2 += rk1[i] * rk1[i];
		}

		beta = n2/n1;

		for (i = 0; i < n; ++i)
		{
			dk1[i] = rk1[i] + (beta * dk[i]);
		}

		for (i = 0; i < n; ++i)
		{
			dk[i] = dk1[i];
			x[i] = xk1[i];
			rk[i] = rk1[i];
		}
	}

	for (i = 0; i < n; ++i)
	{
		x[i] = x[i];
	}
} 