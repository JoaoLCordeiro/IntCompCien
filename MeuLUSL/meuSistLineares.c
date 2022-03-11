#include <stdio.h>
#include <stdlib.h>
#include <math.h>  

#include "meuSistLineares.h"

t_sistLin* alocaSist (int n){
    t_sistLin* sistema   = (t_sistLin *) malloc(sizeof(t_sistLin));

    sistema->n          = n;

    int i;

    //aloca a matriz A

    sistema->A          = (double **) malloc(sizeof(double *)*n);
    for (i = 0 ; i < n ; i++)
        sistema->A[i]   = (double * ) malloc(sizeof(double  )*n);

    //aloca a matriz L

    sistema->L          = (double **) malloc(sizeof(double *)*n);
    for (i = 0 ; i < n ; i++)
        sistema->L[i]   = (double * ) malloc(sizeof(double  )*n);

    //aloca a matriz U

    sistema->U          = (double **) malloc(sizeof(double *)*n);
    for (i = 0 ; i < n ; i++)
        sistema->U[i]   = (double * ) malloc(sizeof(double  )*n);

    //aloca o vetor B

    sistema->B          = (double * ) malloc(sizeof(double  )*n);
   
    return sistema; 
}

t_sistLin* lerSistLin (){
    int n,i,j;
    t_sistLin* SL       = NULL;

    if (scanf("%d",&n) != EOF){                 //lê o n, depois aloca espaco
        SL = alocaSist (n);

        for (i = 0 ; i < n ; i++)               //lê o sistema
            for (j = 0 ; j < n ; j++)
                scanf("%lf", &(SL->A[i][j]));

        for (i = 0 ; i < n ; i++)
            scanf("%lf", &(SL->B[i]));
    }

    return SL;
}

void    imprimeSistLin (t_sistLin *sistema){
    int i,j;

    printf("-----------SISTEMA LINEAR-----------\n");
    printf("\n");
    printf("A:\n");

    for (i = 0 ; i < sistema->n ; i++){
        for (j = 0 ; j < sistema->n ; j++){
            printf("%g ", sistema->A[i][j]);
        }
        printf("\n");
    }                                           

    printf("\n");
    printf("L:\n");    
                                                
    for (i = 0 ; i < sistema->n ; i++){
        for (j = 0 ; j < sistema->n ; j++){
            printf("%g ", sistema->L[i][j]);
        }
        printf("\n");
    }                                           

    printf("\n");                                
    printf("U:\n");   
                                               
    for (i = 0 ; i < sistema->n ; i++){
        for (j = 0 ; j < sistema->n ; j++){
            printf("%g ", sistema->U[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");                                        
}

void	imprimeRes (double *X, int n){
	int i;
	printf("Resultados:\n");
	for (i = 0 ; i < n ; i++)
		printf("%g	",X[i]);

	printf("\n\n");
}
