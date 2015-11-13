/*
 * =====================================================================================
 *
 *       Filename:  ejercicio.c
 *
 *    Description:  valor aproximado de pi, metodo de montecarlo
 *
 *        Version:  1.0
 *        Created:  12/11/15 14:05:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Daniel Monzalvo 
 *   Organization:  ITESM, CSF
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 50

int main(){

	int suma = 0;
	int adentro = 0;
	int radio = 100;
	int i,x, y;
	double d;
	srand(time(NULL));

#pragma omp parallel for private(i,x,y,d) reduction(+:suma)
		for (i = 0; i < N; ++i){
			x = rand() % radio;
			y = rand() % radio;
			suma++;
			d = sqrt((x*x)+(y*y));
			if(d <= radio){
				adentro++;
			}
		}

		float pi = 4*(adentro/suma);
		printf("PI= %f \n", pi);

	return 0;
}

