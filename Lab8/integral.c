#include <stdio.h>
#include "math.h"

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

double simpson(double a, double b, double m, double (*f) (double))
{
	double h = (b - a) / (2 * m);
	double soma = f(a) + f(b);
	int i;
	double x = a;

	for(i = 1 ; i < 2*m; i++)
	{
		x += h;

		if(i%2 == 0)
			soma += f(x) *2;
		else
			soma += f(x) *4;
	}


	return (h/3) * soma; 
}

double ponto_medio(double a, double b, double m, double (*f) (double))
{
	double h = (b - a) / m;
	int i;
	double x = a;
	double soma = 0;

	for( i = 1; i < m; i++)
	{
		soma += f(x - h/2);
		x+=h;
	}

	return h*soma;
}

int main()
{
	printf("\tSimpson 16\tSimpson 32\tPonto Medio 16\tPonto Medio 32\n");
	printf("F1\t%10f\t%10f\t%10f\t%10f\n", simpson(0,4, 16,f1), simpson(0,4, 32,f1),ponto_medio(0,4,16,f1), ponto_medio(0,4,32,f1) );
	printf("F2\t%10f\t%10f\t%10f\t%10f\n", simpson(1,3, 16,f2), simpson(1,3, 32,f2),ponto_medio(1,3,16,f2), ponto_medio(1,3,32,f2) );
	printf("F3\t%10f\t%10f\t%10f\t%10f\n", simpson(0,M_PI, 16,f3), simpson(0,M_PI, 32,f3),ponto_medio(0,M_PI,16,f3), ponto_medio(0,M_PI,32,f3) );
}	