#include <stdio.h>

int main () {

    int n, m, loop, resultadoTabuada;

    scanf ("%d %d", &n, &m);

    loop = 1;

    while (n <= m) {

        while (loop <= 10) {

            resultadoTabuada = (n * loop);
            printf ("%d x %d = %d \n", n, loop, resultadoTabuada);
            
            loop++;
            resultadoTabuada = 0;
        }
    
        loop = 1;
        n++;
    }

    return 0;
}