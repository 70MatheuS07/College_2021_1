#include <stdio.h>
#include <math.h>

int main () {

    int n, k=1;
    double pi, soma=0.0, raiz;

    scanf ("%d", &n);

    while (k <= n) {

        pi = (double) 6 / (k*k);
        
        soma = soma + pi;
        k++;
        pi = 0;
    }

    raiz = sqrt (soma);

    printf ("%.6f", raiz);

    return 0;
}