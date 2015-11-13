
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <omp.h>

#define N 100000

int main(){
  int A[N], B[N], S[N];
  int i;
  float t;
  srand(time(NULL));
  /* 3 Etapas*/
  /*Inizialisación*/
  #pragma omp parallel private(i)
  {
    printf("Hilo %d de %d \n", omp_get_thread_num(), omp_get_num_threads());
    #pragma omp for
    for (i = 0; i < N; ++i){
	    A[i] = rand() % 100;
   	    B[i] = rand() % 100;
	    S[i] = 0;
	    S[i] = A[i] + B[i];
    }
  }
  /*Visualización de resultados */
  for (i = 0; i < N; ++i){
    //printf("[%7d] % 3d + %3d = %4d \n", i, A[i], B[i], S[i]);
  }
  //printf("Tiempo: %f \n", (float)t/CLOCKS_PER_SEC);



  return 0;
}
