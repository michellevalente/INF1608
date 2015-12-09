
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matriz.h"
#include "gauss.h"

//void troca
void swap(double**x,double**y){
int *a = (int *)x,
	*b = (int *)y;
 *a ^= *b;
 *b ^= *a;
 *a ^= *b;
}
double vet_mul(int size, double* a, double* b){
	double soma = 0;
	int i;
	for (i=0;i<size;i++){
		soma += a[i]*b[i];
	}
	return soma;
}
int i_max(int start, int stop,int pos, double **a){
	int max = fabs(a[start][pos]);
	int i_max = start;
	start ++;
	while(start<stop){
		if(fabs(a[start][pos]) > max){
			max = fabs(a[start][pos]);
			i_max = start;
		} 
		start++;
	}
	return i_max;
}
double ** fatoracao(int n, double** A){

	double ** P = mat_cria(n,n);
	double fator;
	int i,j,k, pivot;
	// puts("___fatoração___\n\n");

	/*  PRODUZ IDENTIDADE P */
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			P[i][j] = 0;
		P[i][i] = 1;
	}

	/*  FATORA L U */
	//processar cada coluna
	for(j=0;j<n;j++){

		/* PIVOTAMENTO */
		pivot = i_max(j,n,j,A);
		if(pivot!=j){
			swap(&A[pivot],&A[j]);
			swap(&P[pivot],&P[j]);
		}

		/* HOW: processa cada elemento da coluna; e
		atualiza valores da mesma linha que o elemento processado */
		for(i=j+1;i<n;i++){

			fator = A[i][j]/A[j][j];
			//parte onde atualizamos toda linha processada
			for(k=j;k<n;k++){

				A[i][k] -= fator * A[j][k];
			}
			A[i][j] = fator;
		}
	}

	// puts("fim da fatoração \n\n");

	return P;
} 

double * substituicao(int n, double ** A, double** P, double * b){
	double soma,*x,*y = malloc(sizeof(double)*n);
	int i,j,k;
	// puts("___subtituição___\n\n");


	/*---------------------------------------------
			Encontra Y
	---------------------------------------------*/

	/*ZERA Y*/
	for(i=0;i<n;i++)
		y[i]=0;		
	//Linha a linha
	for(i=0;i<n;i++){
		soma = 0;
		for(j=0;j<=i;j++){
			if(i==j){
				y[i]= vet_mul(n,P[i],b) - soma; 
				//vet_mul(n,P[i],b) = b[i] onde b[i] estah arrumado
			}
			soma += A[i][j]*y[j];
		}
	}

	/*---------------------------------------------
			Calcula X
	---------------------------------------------*/
	x = malloc(sizeof(double)*n);
	/*ZERA X*/
	for(i=0;i<n;i++)
		x[i]=0;		
	//Linha a Linha
	for(i=n-1;i>=0;i--){
		soma = 0;
		for(j=n-1;j>=0;j--){
			if(i==j){
				x[i] = (y[i] - soma)/A[i][i];
			}
			soma += A[i][j]* x[j];
		}
	}

	free(y);
	// puts("__fim da substituicao__ \n\n");
	return x;
}