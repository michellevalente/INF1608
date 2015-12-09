#include "simpson.h"

double Simpson (double a, double b, double (*f) (double x))
{
	double h = b - a;

	return h/6 * (f(a) + 4 * f((a + b) / 2) + f(b));
}

double DoubleSimpson(double a, double b, double (*f) (double x))
{
	double c = (a+b)/2;
	double sa_c = Simpson(a,c,f);
	double sc_b = Simpson(c,b,f);
	return sa_c + sc_b;

} 

double AdaptiveSimpson(double a, double b, double (*f) (double x), double tol)
{
	double s1 = Simpson(a,b,f);
	double s2 = DoubleSimpson(a,b,f);
	double c = (b - a) / 2;

	if( (s1 - s2) < (tol * 15) )
	{
		return s2;
	} 
	
	s1 = AdaptiveSimpson(a, a+c, f, tol/2);
	s2 = AdaptiveSimpson(a + c, b, f, tol/2);

	return s1 + s2;
}