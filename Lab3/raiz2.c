#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raiz2.h"

double falsaposicao (double a, double b, int p, double (*f) (double x), double * r)
{
	double f_b, f_a, c, precisao, aux;
	int i = 1;
	precisao = 0.5 * pow(10, -p);
	if(a > b)
	{
		aux = a;
		a = b;
		b = aux;
	}
	f_a = f(a);
	f_b = f(b);
	c = (a*f_b - b *f_a) / (f_b - f_a);

	while (fabs(f(c)) >= precisao)
	{
		i++;
		if( f(c) == 0)
			break;
		if( (f(c) * f(a)) < 0 )
			b = c;
		else
			a = c;	
		f_a = f(a);
		f_b = f(b);
		c = (a*f_b - b *f_a) / (f_b - f_a);
	}

	*r = c; 
	return i;
}

int newtonraphson(double x0, int p, double (*f) (double x), double (*fl) (double x), double *r)
{
	double x1;
	double precisao = 0.5 * pow(10,-p);
	int i = 1;
	x1 = x0 - f(x0)/fl(x0);

	while(fabs(f(x1)) >= precisao)
	{
		x0 = x1;
		x1 = x0 - f(x0)/fl(x0);
		i++;
	}

	*r = x1;
	return i;
}
