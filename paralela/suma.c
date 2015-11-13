/*
 * =====================================================================================
 *
 *       Filename:  suma.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/11/15 13:52:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <omp.h>

#define N 10000

int main(){
	int numeros[N];
	int suma = 0;
	int i;

	for (i = 0; i < N; ++i){
		numeros[i] = 1;
	}
	#pragma omp parallel for private(i) reduction(+:suma)
	for (i = 0; i < N; ++i){
		//#pragma omp atomic
		suma += numeros[i];
	}

	printf("Suma: %d \n", suma);
}
