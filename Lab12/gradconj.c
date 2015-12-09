#include <stdio.h>
#include <math.h>
#include "matriz.h"
#define EPSILON 0.0000000000001

double modulo(int n, double * A)
{
    int i;
    double m = 0;
    for(i = 0; i < n; i++)
    {
        m+= A[i] * A[i];
    }
    return sqrt(m);
}
void copia_matriz(int m, int n, double ** m1, double m2[m][n]){
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            m1[i][j] = m2[i][j];
        }
    }
}

void print_matriz(int n, double ** A)
{
    int i,k;
    for(i = 0; i < n; i++)
    {
        for(k =0; k< n; k++)
        {
            printf("%.1f ", A[i][k]);
        }

        printf("\n");
    }
}
void print_vetor(int n, double *A)
{
    int i,k;
    for(i = 0; i < n; i++)
    {
        printf("%.1f ", A[i]);
    }
    printf("\n");
}

void Cholesky(int n, double** A)
{
    int k, i,j;
    double ** R = mat_cria(n,n);
    double ** ut, ** u;
    double** temp = mat_cria(n,n);

    for(k = 0; k < n; k++)
    {
        ut = mat_cria(n,n);
        u = mat_cria(n,n);

        A[k][k] = sqrt(A[k][k]);

        for(j = k + 1; j < n ;j++ )
           ut[k][j] = (1/A[k][k])*A[k][j]; 

        mat_transposta(n,n,ut,u);
        mat_multm(n,n,n,u,ut,temp);

        for(i = k + 1; i< n; i++)
        {
            for(j = k + 1; j < n ; j++)
                A[i][j] = A[i][j] - temp[i][j];
        }
    }

    for (i = 1; i < n; ++i)
    {
        for (j = 0; j < i; ++j)
        {
            A[i][j] = 0;
        }
    }
}

void ConjugateGradient(int n, double** A, double* b, double * x)
{
    int k,i,j;  
    double r[n], r1[n];
    double temp, temp2, alfa, beta;
    double d[n], t1[n], t2[n], x1[n];
    int zero;

    mat_multv(n, n, A,x, t1);

    for(k = 0; k < n; k++)
    {    
        r[k] = b[k] - t1[k];
        d[k] = r[k];
    }

    k = 0;
    while(1)
    {
        zero = 1;
        for(i = 0; i < n; i++)
        {
            if(r[i] > EPSILON )
                zero = 0;
        }
        if(zero)
        {
            for (i = 0; i < n; ++i)
            {
                x[i] = x1[i];
            }
            return;
        }

        temp =0;
        for(i = 0; i < n; i++)
        {
            temp += r[i] * r[i];
        }


        for(i = 0; i < n ;i++)
            t2[i] =0;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                t2[i] += d[j] * A[j][i];
            }
        }

        temp2 =0;
        for(i = 0; i < n; i++)
        {
            temp2 += t2[i] * d[i];
        }

        alfa = temp/temp2;

        for(i = 0; i < n; i++)
        {
            x1[i] = x[i] + alfa * d[i];
        }

        mat_multv(n,n,A,d,t2);
        for(i = 0; i < n; i++)
        {
            r1[i] = r[i] - alfa * t2[i];
        }

        temp2 =0;
        for(i = 0; i < n; i++)
        {
            temp2 += r1[i] * r1[i];
        }
        beta = temp2/temp;
        for(i = 0; i<n ;i++)
        {
            d[i] = r1[i] - beta * d[i];
        }
        for(i =0 ; i < n; i++)
        {
            r[i] = r1[i];
        }
        for(i =0 ; i < n; i++)
        {
            x[i] = x1[i];
        }
        k++;
    }

}

int main()
{
    double A1_temp[][3] = {{1,-1,0} , {-1,2,1}, {0,1,2}};
    double A2_temp[][3] = {{1,-1,0}, {-1,2,1}, {0,1,5}};
    double b1[3] = {0,2,3};
    double b2[3] = {3,-3,4};
    double x1[3] = {0,0,0};
    double x2[3] = {0,0,0};
    double ** A1 = mat_cria(3,3);
    double ** A2 = mat_cria(3,3);
    int i;

    copia_matriz(3,3,A1, A1_temp);
    copia_matriz(3,3,A2, A2_temp);

    ConjugateGradient(3,A1, b1, x1);
    printf("\nResultado para o primeiro sistema:\n");
    print_vetor(3,x1);

    ConjugateGradient(3,A2, b2, x2);
    printf("\nResultado para o segundo sistema:\n");
    print_vetor(3,x2);
    printf("\n");

    Cholesky(3,A1);
    printf("Matriz R para o primeiro sistema: \n");
    print_matriz(3,A1);
    printf("\n");

    Cholesky(3,A2);
    printf("Matriz R para o segundo sistema: \n");
    print_matriz(3,A2); 
    printf("\n");


    

    return 1;

}