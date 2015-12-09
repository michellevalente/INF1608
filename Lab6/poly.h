#include <math.h>
#include <stdlib.h>

typedef struct sample Sample;
struct sample {
	int n;
	double *x;
	double *y;
};

Sample * Chebyshev (int n, double a, double b, double (*f) (double x));

double * LagrangeCompute(Sample * s);

double LagrangeEval(Sample * s, double * den , double x);

double * NewtonCompute(Sample * s);

double NewtonEval(Sample *s, double *coef, double x);