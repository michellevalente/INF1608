#include "matriz.h"
#include <stdio.h>
// Função auxiliar que imprime uma matriz MxN
void printm(int m, int n, double** A)
{
	int i, j;
	for(i = 0; i < m; i++)
	{
		printf("\n");
		for(j = 0; j < n; j++)
		{
			printf("%g ", A[i][j]);
		}
	}
}
int main (void)
{
	double** A = mat_cria(3,3);
	double** B = mat_cria(3,2);
	double** C = mat_cria(3,3);
	double** D = mat_cria(3,2);
	double** E = mat_cria(2,5);
	double x[5];
	double v[3];
	double w[3];
	double XE[2];
	// Vetor v
	v[0] = 0;
	v[1] = 1;
	v[2] = 2;
	// vetor x
	x[0] = 1;
	x[1] = 2;
	x[2] = 3;
	x[3] = 4;
	x[4] = 5;
	// Matriz A
	A[0][0] = 1;
	A[0][1] = 2;
	A[0][2] = 3;
	A[1][0] = 4;
	A[1][1] = 5;
	A[1][2] = 6;
	A[2][0] = 7;
	A[2][1] = 8;
	A[2][2] = 9;
	// Matriz B
	B[0][0] = 0;
	B[0][1] = 1;
	B[1][0] = 0;
	B[1][1] = 1;
	B[2][0] = 0;
	B[2][1] = 1;
	//Matriz E
	E[0][0] = 1;
	E[0][1] = 2;
	E[0][2] = 3;
	E[0][3] = 4;
	E[0][4] = 5;
	E[1][0] = 1;
	E[1][1] = 2;
	E[1][2] = 3;
	E[1][3] = 4;
	E[1][4] = 5;
	// Imprime a matriz
	printf(" Matriz A \n");
	printm(3,3,A);
	mat_transposta(3,3, A, C);
	printf("\n\n Matriz Transposta C \n");
	printm(3,3,C);
	printf("\n\n Vetor resultante da multiplicacao Matriz A x Vetor V \n");
	mat_multv(3,3, A, v, w);
	printf("%g\n%g\n%g\n", w[0], w[1], w[2]);
	mat_multm(3,3,2, A, B, D);
	printf(" Matriz resultante da multiplicacao Matriz A x Matriz B \n");
	printm(3,2,D);
	printf("\n\n Vetor resultante da multiplicacao vetor x * matriz E \n");
	mat_multv(2,5, E, x, XE);
	printf("%g\n%g\n\n", XE[0], XE[1]);
	mat_libera(3, A);
	mat_libera(3, B);
	mat_libera(3, C);
	mat_libera(3, D);
	return 0;
}