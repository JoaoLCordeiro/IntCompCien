#include <stdio.h>
#include <stdlib.h>
#include <math.h>  

#include "meuLU.h"
#include "meuSistLineares.h"

int main (){
    t_sistLin *sistema;

    while (sistema = lerSistLin()){
        double* X = resolveLU (sistema);

        imprimeSistLin  (sistema);
        imprimeRes      (X,sistema->n);
    }

    return 1;
}                                       
