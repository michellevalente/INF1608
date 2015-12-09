#include "mmq.h"

double* mmq ( int m, int n, double** A, double* b){

	double ** C, ** P, *res;
	double D[n];
	double ** T = mat_cria(n,m);

	mat_transposta(m, n, A, T);

	C = mat_cria(n,n);
	mat_multm(n,m,n,T,A,C);
	mat_multv(n, m, T, b, D); 
	
	P = fatoracao(n,C);
	res = substituicao(n,C,P,D);
	

	mat_libera(n,T);
	mat_libera(n,C);

	return res;
}

double norma2(int m, int n, double ** A, double* b, double* x)
{
	int i;
	double r;
	double temp[m];
	mat_multv(m, n, A, x, temp);
	double res = 0;

	for (i = 0; i < m; i++)
	{
		r = b[i] - temp[i];
		res += r * r;
	}

	res = sqrt(res);

	return res;

}
