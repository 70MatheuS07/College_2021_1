#include <stdio.h>

int main () {

    int n, nNega=0, nPosi=0, somaNega=0, somaPosi=0, loop = 1;

    while ((loop < 100) && (loop > -100)) {

        scanf ("%d", &n);

        if (n < 0) {

            nNega = (nNega + 1);

            somaNega = (somaNega + n);

            loop = 1;
        }

        if (n > 0) {

            nPosi = (nPosi + 1);

            somaPosi = (somaPosi + n);

            loop = 1;
        }

        if (n = 0) {

            loop = 101;
        }
            
        loop++;
    }

    printf ("%d ", nNega);

    printf ("%d ", nPosi);

    printf ("%d ", somaNega);

    printf ("%d", somaPosi);
    

    

















    return 0;
}