#include <stdio.h>
#include <math.h>
#include "brent.h"

double f1(double x)
{
    return 4*cos(x) - exp(2*x);
}

double f2(double x)
{
    return x/2 - tan(x);
}

double f3(double x)
{
    return 1 - x * log(x + 20);
}

double f4(double x)
{
    return pow(2,x) - 3 *x ;
}

double f5(double x)
{
    return x*x*x + x -1;
}

int main()
{
    printf(" Resultado f1: %lf \n" , brent(-1, 1, 6, f1));
    printf(" Resultado f2: %lf \n" , brent(-1, 1, 6, f2));
    printf(" Resultado f3: %lf \n" , brent(-1, 1, 6, f3));
    printf(" Resultado f4: %lf \n" , brent(-1, 1, 6, f4));
    printf(" Resultado f5: %lf \n" , brent(-1, 1, 6, f5));
}
