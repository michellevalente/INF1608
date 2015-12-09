#include <stdio.h>
#include <math.h>
#include "fcos.c"

int main(){
	double x, res;
	printf("Numero: ");
	scanf("%lf", &x);
		
	res = fcos(x);

	printf("\nCosseno encontrado: %lf\n", res);
	printf("Valor real do cosseno: %lf\n", cos(x));

	printf("Erro: %lf\n", (res - cos(x)));

	return 0;
}
