#include <stdio.h>

int main()
{
    int h1 = 0, h2 = 0;
    int min1 = 0, min2 = 0;
    int seg1 = 0, seg2 = 0;
    int soma1 = 0, soma2 = 0;
    int unidade = 0, dezena = 0, digitoDaDezena = 0;
    int hMaior = 0, minMaior = 0, segMaior = 0;

    scanf("%d %d %d %d %d %d", &h1, &min1, &seg1, &h2, &min2, &seg2);

    soma1 = h1 + min1 + seg1;
    soma2 = h2 + min2 + seg2;

    if (h1 == h2 && min1 == min2 && seg1 == seg2)
    {
        printf("IGUAIS");
    }
    else
    {
        if (h1 > h2)
        {
            if (soma1 < 10)
            {
                printf("RESP:0");
            }
            else
            {
                unidade = soma1 % 10;
                dezena = soma1 % 100;
                digitoDaDezena = (dezena - unidade) / 10;

                printf("RESP:%d", digitoDaDezena);
            }
        }

        else if (h2 > h1)
        {
            if (soma2 < 10)
            {
                printf("RESP:0");
            }
            else
            {
                unidade = soma2 % 10;
                dezena = soma2 % 100;
                digitoDaDezena = (dezena - unidade) / 10;

                printf("RESP:%d", digitoDaDezena);
            }
        }

        else if (h1 == h2)
        {
            if (min1 > min2)
            {
                if (soma1 < 10)
                {
                    printf("RESP:0");
                }
                else
                {
                    unidade = soma1 % 10;
                    dezena = soma1 % 100;
                    digitoDaDezena = (dezena - unidade) / 10;

                    printf("RESP:%d", digitoDaDezena);
                }
            }
            else if (min2 > min1)
            {
                if (soma2 < 10)
                {
                    printf("RESP:0");
                }
                else
                {
                    unidade = soma2 % 10;
                    dezena = soma2 % 100;
                    digitoDaDezena = (dezena - unidade) / 10;

                    printf("RESP:%d", digitoDaDezena);
                }
            }
            else if (min1 == min2)
            {
                if (seg1 > seg2)
                {
                    if (soma1 < 10)
                    {
                        printf("RESP:0");
                    }
                    else
                    {
                        unidade = soma1 % 10;
                        dezena = soma1 % 100;
                        digitoDaDezena = (dezena - unidade) / 10;

                        printf("RESP:%d", digitoDaDezena);
                    }
                }
                else if (seg2 > seg1)
                {
                    if (soma2 < 10)
                    {
                        printf("RESP:0");
                    }
                    else
                    {
                        unidade = soma2 % 10;
                        dezena = soma2 % 100;
                        digitoDaDezena = (dezena - unidade) / 10;

                        printf("RESP:%d", digitoDaDezena);
                    }
                }
            }
        }
    }
    
    return 0;
}