#ifndef _SISTLIN_
#define _SISTLIN_

typedef struct t_sistLin {
    int         n;
    double**    A;
    double**    L;
    double**    U;
    double*     B;
} t_sistLin;

t_sistLin*  alocaSist (int n);

t_sistLin*  lerSistLin ();

void        imprimeSistLin (t_sistLin *sistema);

void		imprimeRes	   (double* X, int n);

#endif
