#include <stdio.h>
#include <math.h>
#include "poly.h"

int factorial (int n) 
{ 
	int r = 1; 
	for (int i=2; i<=n; i++) 
	r *= i; 
	return r; 
} 
int main(){
	int i;
	int a = 0;
	int b = M_PI/2;
	int n = 6;
	Sample * s =  Chebyshev (n,  a, b,cos);
	double *den;
	double *coef;
	double res1, res2;
	double erro;
	double x;
	printf("Amostras por chebyshev: \n");
	for(i = 0; i < 6; i++)
	{
		printf("X[%d]: %g Y[%d]: %g\n", i, s->x[i], i, s->y[i]);
	}

	x = 0;

	while(x <= M_PI/2)
	{
		den = LagrangeCompute(s);

		res1 = LagrangeEval(s, den, x);

		coef = NewtonCompute(s);

		res2 = NewtonEval(s, coef, x);

		erro = (pow((b - a) / 2, n) / pow(2,n-1 )) * (pow(cos(x), n) / factorial(n));
		if((res1 - cos(x)) <= erro)
		{
			printf("Resultado Lagrange atende a precisao necessaria para x = %f\n", x);
		}else
		{
			printf("Resultado Lagrange nao atende a precisao necessaria para x = %f\n", x);
		}
		if((res2 - cos(x)) <= erro)
		{
			printf("Resultado Newtown atende a precisao necessaria para x = %f\n", x);
		}else
		{
			printf("Resultado Newtown nao atende a precisao necessaria para x = %f\n", x);
		}

		x+= 0.3;
	}
	

	

}