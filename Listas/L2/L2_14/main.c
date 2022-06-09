#include <stdio.h>

int main () {

    char letra;

    printf ("RESP:");

    while (letra != 1) {

        scanf ("%c", &letra);

        if (letra == 32) {
            
            printf ("");
        }

        else if (letra == 33) {

            printf ("!");
            letra = 1;
        }
        
        else if (letra == 46) {

            printf (".");
            letra = 1;
        }

        else if (letra == 63) {

            printf ("?");
            letra = 1;
        }
        
        else if (letra != (32) || (33) || (46) || (63)) {

            printf ("%c", letra);
        }

    }

    return 0;
}