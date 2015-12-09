#include <stdio.h>
#include <math.h>
#include "brent.h"

double brent (double x0, double x1, int p, double (*f) (double x))
{
	double f_0, f_1, f_m;
	double x2 = x0, xm;
	int t;
	double precisao = 0.5 * pow(10, -p);
	f_0 = f(x0);
	f_1 = f(x1);

	if( f_0*f_1 >= 0)
		return 0;
	
	while(fabs(f(x2)) >= precisao)
	{

		f_0 = f(x0);
		f_1 = f(x1);
		xm = (x1 + x0) /2.0;

		f_m = f(xm);

		x2 = (( x0 * f_1 * f_m ) / ( ( f_0 - f_1 ) * (f_0 - f_m ))) +
			 (( x1 * f_0 * f_m ) / ( ( f_1 - f_0 ) * (f_1 - f_m ))) +
			 (( xm * f_1 * f_0 ) / ( ( f_m - f_0 ) * (f_m - f_1 )));


		
		if( fabs(f(x2)) < fabs(f(xm)) && x2 != x1 && x2 != x0)
		{

			if(f_0 * f(x2) < 0) 
				x1 = x2;
			else
				x0 = x2;

			continue;
			
		}
		else
		{
			
			x2 = x1 - f_1 * ( (x1 - x0) / (f_1 - f_0 ) );

			if( fabs(f(x2)) <= fabs(f(xm)))
			{

				if(f_0 * f(x2) < 0) 
					x1 = x2;
				else
					x0 = x2;

				continue;
			
			}
			else
			{

				x2 = xm;
				if(f_0 * f(x2) < 0) 
					x1 = x2;
				else
					x0 = x2;
			}
		}
		
	}

	return x2;
	
}
