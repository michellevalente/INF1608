#include <stdio.h>
#include <math.h>
#include "raiz2.h"
double f(double x)
{
	return sin(x) - x*x*x;
}

double fl(double x)
{
	return cos(x) - 3*(x*x);
}

int main(){

	double r1, r2, r3;
	int i = falsaposicao(0.5, 1.5, 6, f, &r1);
	int w = newtonraphson(1.5,6, f, fl , &r3);

	printf("Falsa posicao\nRaiz: %lf \nInteracoes: %d\n", r1, i);
	printf("Bissecao\nRaiz: %lf \nInteracoes: %d\n", r3, w);

	return 0;

}