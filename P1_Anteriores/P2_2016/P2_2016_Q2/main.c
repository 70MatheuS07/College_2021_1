#include <stdio.h>

int main()
{
    int result;
    int n;
    char c;

    while (scanf("%d%c", &n, &c) == 2)
    {
        
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
        return 1;
    }

    return 0;
}