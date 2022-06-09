#include <stdio.h>

int EhPrimo(int num);

int main()
{
    int n = 0, m = 0, num = 0, i = 0, primo = 0;

    scanf("%d %d", &n, &m);

    num = n + 1;
    i = m - 1;

    for (num; num <= i; num++)
    {

        primo = EhPrimo(num);

        if (primo != 0)
        {
            printf("%d ", primo);
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