#include <stdio.h>
#include <math.h>

double fcos (double x){
	double res;
	res = pow(x - M_PI/2, 3)/6 - ( x - M_PI/2);
	return res;
}
