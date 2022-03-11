#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "SistLinear.h"
#include "EliminacaoGauss.h"
#include "Refinamento.h"

void refinamento(SistLinear_t *SL, double *X, int MAXIT) {

  double *W = (double *) malloc(sizeof(double)*SL->n);

  long double *LX = (long double *) malloc(sizeof(long double)*SL->n); 
  for (int i = 0; i < SL->n; ++i)
    LX[i] = (long double) X[i];

  printf("  --> Refinamento:\n");
  for (int i = 0; i < MAXIT; ++i) {
    long double *res = long_residuo(SL, LX);
    printf("  ----> iteração %d. Resíduo: ", i);
    prnVetorLongDouble(res, SL->n);

    SistLinear_t *U = dupSL(SL);
    for (int j = 0; j < SL->n; ++j)
      U->b[j] = (double) res[j];

    eliminacaoGauss(U, W);

    for(int k = 0; k < SL->n; ++k)
      LX[k] += (long double) W[k];
    
    liberaSistLinear(U);
    free(res);
  }
}

