#include <stdio.h>

int EhPrimo(int num);
void ImprimeMultiplos(int num, int max);

int main()
{
    int n = 0, m = 0, num = 0, i = 0, primo = 0, max = 0;

    scanf("%d %d", &n, &m);

    num = n + 1;
    i = m - 1;
    max = i;

    for (num; num <= i; num++)
    {

        primo = EhPrimo(num);

        if (primo != 0)
        {
            printf("%d ", primo);
           
            ImprimeMultiplos (num, max);
        }
    }

    

    return 0;
}

int EhPrimo(int num)
{
    int den = 1, loop = 0;

    while (den <= num)
    {

        if (num % den == 0)
        {
            loop++;
        }
        den++;
    }

    if (loop == 2)
    {
        return (num);
    }

    return 0;
}

void ImprimeMultiplos(int num, int max)
{
    int multiplo = 0;
    
    multiplo = num * 2;

    printf ("\n");
    
    if (multiplo <= max)
    {
        multiplo = (multiplo / 2) + 1;

        while (multiplo <= max)
        {

            if (multiplo % num == 0)
            {
                printf("%d ", multiplo);
            }

            multiplo++;
        }
        
        printf(" \n");
    }
    else if (multiplo * 2 > max)
    {
        printf("*");
        printf(" \n");
    }
}