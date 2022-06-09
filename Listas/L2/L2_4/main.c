#include <stdio.h>

int main () {

    int num, numMaior=0, loop, loopInt=1, soma=0, qtd=0;
    float media;

        do {

            scanf ("%d", &num);

            loop = num - 1;
    
        while (loop < num) {

            if (num > numMaior) {

            numMaior = num;

            }

            if (num != 0) {
                
                printf ("%d ", numMaior);

            }

            loopInt = loop - 1;

            while ((loopInt < loop) && (num != 0)) {

                soma = soma + num;
                qtd = qtd + 1;
                media = (float) soma / qtd;

                printf ("%.6f\n", media);

                loopInt++;
            }

            loop++;
        }

    } while (num != 0);
        

    return 0;
}