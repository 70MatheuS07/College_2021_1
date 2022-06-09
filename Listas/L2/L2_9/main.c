#include <stdio.h>

int main()
{

    int long n, m, den, loop, multiplo;

    scanf("%d %d", &n, &m);

    n = n + 1;
    m = m - 1;
    den = 1;
    loop = 0;

    for (n; n <= m; n++)
    {

        while (den <= n)
        {

            if (n % den == 0)
            {

                loop++;
            }

            den++;
        }

        if (loop == 2)
        {

            den = 1;
            loop = 0;
            multiplo = n * 2;

            printf("%d \n", n);

            if (multiplo <= m)
            {

                multiplo = (multiplo / 2) + 1;

                while (multiplo <= m)
                {

                    if (multiplo % n == 0)
                    {
                        printf("%d ", multiplo);
                    }

                    multiplo++;
                }
                
                printf(" \n");
            }
            else if (multiplo * 2 > m)
            {
                printf("*");
                printf(" \n");
            }
        }

        den = 1;
        loop = 0;
        multiplo = 1;
    }

    return 0;
}