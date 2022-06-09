#include <stdio.h>

int main () {

    int qtd, loop, loopint, pares=0, impares=0, numMaior=0, numMenor=999999, num, soma=0;
    float media;

    scanf ("%d", &qtd);
    
    loop = 1;

    while (loop <= qtd) {

        scanf ("%d", &num);

        if (num > numMaior) {
                
            numMaior = num;
        }
        
        if (num <= numMenor) {
                
            numMenor = num;
        }
    
        loopint = loop;
        while ((num % 2 == 0) && (loopint <= loop)) {

            pares = pares + 1;
            loopint++;
        }
        
        loopint = loop;
        while ((num % 2 != 0) && (loopint <= loop)) {

            impares = impares + 1;
            loopint++;
        } 

        loopint = loop;
        while (loopint <= loop) {

            soma = soma + num;
            loopint++;
        }
        
        loop++;
    }
    
    media = (float) soma/qtd;

    printf ("%d ", numMaior);
    printf ("%d ", numMenor);
    printf ("%d ", pares);
    printf ("%d ", impares);
    printf ("%.6f", media);

    return 0;
}