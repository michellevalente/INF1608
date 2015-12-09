#include <stdio.h>
#include <math.h>
#define emaq 2.220446049250313e-16

double f(double x){
	return pow(1+x, -1);
}

int main(){
	double f_l;
	double h = 0.1;
	int i;
	double f_a = - 0.25;
	double erro;
	double f_terceira = (6/pow(2, 4));
	printf("h\taproximada\tanalitica\terro\t\t\tE(h)\n");
	for(i = 1; i < 13;i++)
	{
		f_l = (f(1 + h) - f(1 -h))/(2*h);
		erro = ((h * h) * f_terceira)/6 + (emaq / h);
		printf("10^-%d\t%0.10f\t%.2f\t\t%0.10f\t\t%0.10f\n", i, f_l, f_a, f_l - f_a,erro );
		h /= 10;
	}
	printf("h analitico que minimiza o erro: 10^-5\n");
	printf("h teorico que minimiza o erro: 10^-5\n");
	return 1;
}