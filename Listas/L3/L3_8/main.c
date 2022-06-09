#include <stdio.h>

int verificaPrimo(int n);

int transformaPrimo(int n);

int verificaNegativo(int n);

int main()
{
    int matriz = 0, i = 0, j = 0;
    int linha = 0, coluna = 0, n = 0;
    int valorMaior = 0, linhaDoMaior = 0, colunaDoMaior = 0;
    int verificaNumeroPrimo = 0;
    int transformaNumeroEmPrimo = 0;

    scanf("%d %d", &linha, &coluna);

    if (linha >= 1 && linha <= 100 && coluna >= 1 && coluna <= 100)
    {
        for (i = 1; i <= linha; i++)
        {
            printf("	");

            for (j = 1; j <= coluna; j++)
            {
                scanf("%d ", &n);

                verificaNumeroPrimo = verificaPrimo(n);

                if (verificaNumeroPrimo == 1)
                {
                    printf("%d ", n);
                }
                else
                {
                    transformaNumeroEmPrimo = transformaPrimo(n);

                    if (transformaNumeroEmPrimo == 0)
                    {
                        printf("%d ", n);
                    }
                    else
                    {
                        printf("%d ", transformaNumeroEmPrimo);
                    }
                }
            }

            printf("\n");
        }
    }

    return 0;
}

int verificaPrimo(int n)
{
    int den = 1, loop = 0;

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
        return (1);
    }
    else
    {
        return (0);
    }
}

int transformaPrimo(int n)
{
    int den = 0, loop = 0, num = 0, verificaNumeroNegativo = 2;

    num = n;

    verificaNumeroNegativo = verificaNegativo(n);

    if (verificaNumeroNegativo == 0)
    {
        den = 1;

        for (num; num <= 32000; num++)
        {
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

            den = 1;
            loop = 0;
        }
        return (0);
    }

    else if (verificaNumeroNegativo == 1)
    {
        den = -1;

        for (num; num >= -32000; num--)
        {
            while (den >= num)
            {
                if (num % den == 0)
                {
                    loop++;
                }
                den--;
            }

            if (loop == 2)
            {
                return (num);
            }

            den = -1;
            loop = 0;
        }
        return (0);
    }
}

int verificaNegativo(int n)
{
    if (n < 0)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}