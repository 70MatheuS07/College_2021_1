#include <stdio.h>
#include <math.h>

int main()
{

    long int n, numerador1 = 0, numerador2 = 0, numerador3 = 0, denominador1 = 0, denominador2 = 0, denominador3 = 0;
    double S1, S2, S3, total1 = 0, total2 = 0, total3 = 0;

    scanf("%ld", &n);

    if (n == 1)
    {

        numerador1 = 1;
        denominador1 = 1;

        while ((numerador1 < 100) && (denominador1 < 51))
        {

            S1 = (double)numerador1 / denominador1;
            total1 = (double)total1 + S1;
            numerador1 = numerador1 + 2;
            denominador1 = denominador1 + 1;
        }

        printf("%.6f", total1);
    }

    if (n == 2)
    {

        numerador2 = 2;
        denominador2 = 50;

        while (denominador2 > 0)
        {

            S2 = (double)numerador2 / denominador2;
            total2 = (double)total2 + S2;
            numerador2 = (numerador2 * 2);
            denominador2 = denominador2 - 1;
        }

        printf("%.6f", total2);
    }

    if (n == 3)
    {

        numerador3 = 1;
        denominador3 = 1;

        while ((numerador3 < 11) && (denominador3 < 101))
        {

            S3 = (double)numerador3 / denominador3;
            total3 = (double)total3 + S3;
            numerador3 = numerador3 + 1;
            denominador3 = (numerador3 * numerador3);
        }

        printf("%.6f", total3);
    }

    return 0;
}