#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "SistLinear.h"
#include "EliminacaoGauss.h"

void pivot(SistLinear_t *SL, int i) {
  double max = fabs(SL->A[i][i]);
  int max_i = i;
  for (int j = i+1; j < SL->n; ++j) {
    double v = fabs(SL->A[j][i]);
    if (v > max) {
      max = v;
      max_i = j;
    }
  }
  if (max_i != i) {
    double *tmp = SL->A[i];
    SL->A[i] = SL->A[max_i];
    SL->A[max_i] = tmp;

    double aux = SL->b[i];
    SL->b[i] = SL->b[max_i];
    SL->b[max_i] = aux;
  }
} 

void retrossubs(SistLinear_t *SL, double *X) {
  for (int i = SL->n-1; i >= 0; --i) {
    X[i] = SL->b[i];
    for (int j = i+1; j < SL->n; j++)
      X[i] -= SL->A[i][j] * X[j];
    X[i] /= SL->A[i][i];
  }
}

void triang(SistLinear_t *SL) {
  for (int i = 0; i < SL->n; ++i) {
    pivot(SL, i);
    for (int k = i+1; k < SL->n; ++k) {
      double m = SL->A[k][i] / SL->A[i][i];
      if (isnan(m))
        printf("ERRO: %g\n", SL->A[i][i]);
      SL->A[k][i] = 0.0;
      for (int j = i+1; j < SL->n; ++j)
        SL->A[k][j] -= SL->A[i][j] * m;
      SL->b[k] -= SL->b[i] * m;
    }
  }
}

void eliminacaoGauss(SistLinear_t *SL, double *X) {
  triang(SL);
  retrossubs(SL, X);
}

