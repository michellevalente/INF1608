#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matriz.h"
#include "gauss.h"

double* mmq(int m, int n, double** A, double* b);

double norma2(int m, int n, double** A, double* b, double* x);