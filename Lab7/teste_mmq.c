#include "mmq.h"

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

int main(){

	double A_temp[][3] = {{1,1,0},{0,1,1},{1,2,1},{1,0,1}};
	double ** A = mat_cria(4,3);
	double B[] = {2,2,3,4};
	double * x, residuo;
	int i;
	double t =0.0;
	double b[8];
	double c[]= {8.0,12.3,15.5,16.8,17.1,15.8,15.2,14.0};


	// Primeiro exercicio
	copia_matriz(4,3,A, A_temp);
	x = mmq ( 4, 3, A, B);

	printf("Resultado questao 3: ");
	for(i = 0; i < 3 ; i++)
		printf("%f ", x[i]);
	printf("\n");

	residuo = norma2 (4, 3, A, B, x);

	printf("Resultado norma2 para questao 3: %f\n", residuo);

	mat_libera(4,A);


	// Segundo Exercicio
	for(i = 0 ; i < 8 ; i++)
		b[i] = log(c[i]) - log(i + 1);

	A = mat_cria(8,2);

	for(i = 0; i < 8; i++)
	{
		A[i][0] = 1;
		A[i][1] = i + 1;
	}

	x = mmq(8, 2, A, b);
	residuo = norma2(8,2,A,b,x);

	x[0] = exp(x[0]);
	printf("Resultado questao 4 a: %f b : %f\n", x[0],x[1]);
	printf("Resultado norma2 para questao 4: %f\n", residuo);

	while(t <= 16.0)
	{
		printf("(%f,%f)\n", t,(x[0]*t*exp(x[1]*t)));
		t +=0.1;
	}

	return 0;
}