#include <stdio.h>
#include <math.h>
#include "simpson.h"

double f1(double x)
{
	return (x / (sqrt(pow(x, 2) + 9)));
}

double f2(double x)
{
	return x*x*log(x);
}

double f3(double x)
{
	return x*x*sin(x);
}

int main()
{
	double tol = 0.5 * pow(10,-5);
	double s1 = AdaptiveSimpson(0, 4, f1, tol);
	double s2 = AdaptiveSimpson(1, 3, f2,tol);
	double s3 = AdaptiveSimpson(0, M_PI, f3, tol);
	printf("Resultado para primeira funcao: %0.10f\n", s1);
	printf("Resultado para segunda funcao: %0.10f\n", s2);
	printf("Resultado para terceira funcao: %0.10f\n", s3);
}