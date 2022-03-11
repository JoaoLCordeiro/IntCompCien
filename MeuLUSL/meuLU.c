#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "meuLU.h"
#include "meuSistLineares.h"

void fatLU (t_sistLin* sistema){
    int i,j,k,mult;

    for (i = 0 ; i < sistema->n ; i++)
        for (j = 0 ; j < sistema->n ; j++)
            sistema->U[i][j] = sistema->A[i][j];

    for (i = 0 ; i < sistema->n ; i++){

        sistema->L[i][i] = 1;                                   //adiciona um 1 na L para cada liha

        for (j = i+1 ; j < sistema->n ; j++){
            mult = sistema->U[j][i] / sistema->U[i][i];         //encontra o multiplicador
            
            sistema->L[j][i] = mult;                            //adiciona o mult à L

            sistema->U[j][i] = 0.0;                             //zera o elemento

            for (k = i+1 ; k < sistema->n ; k++){               //termina a subtracão de equacoes
                sistema->U[j][k] -= sistema->U[i][k] * mult;
            }
        }
    }

    for (j = 0 ; j < sistema->n ; j++)                          //termina a matriz L
        for (i = 0 ; i < j ; i++){
                sistema->L[i][j] = 0.0;
            }
}

double* resolveLU (t_sistLin* sistema){
    fatLU (sistema);

    double* X   = (double *) malloc (sizeof(double)*sistema->n);
    double* Y   = (double *) malloc (sizeof(double)*sistema->n);
    
    int i,j;

    for (i = 0 ; i < sistema->n ; i++){
        Y[i] = sistema->B[i];                   //pega o valor de B
        for (j = 0 ; j < i ; j++){
            Y[i] -= sistema->L[i][j] * Y[j];    //subtrai os valores, resolvendo equacoes
        }
    }

    for (i = sistema->n - 1 ; i >= 0 ; i--){        //esquema bem parecido com o da matriz L
        X[i] = Y[i];                                //mas começa de baixo e da direita

        for (j = sistema->n - 1 ; j > i ; j--){
            X[i] -= sistema->U[i][j] * X[j];
        }

        X[i] /= sistema->U[i][i];                   //ultima divisão já que o indice nem sempre sera 1    
    }

    return X; 
}
