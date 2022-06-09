#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0;
    int M = 0;
    int i, j;
    int moedas;
    int nvl_atual_arma;

    scanf("%d", &N);

    scanf("%d", &M);

    int runasPreco[M - 1];

    for (i = 0; i < M; i++)
    {
        scanf("%d", &num);

        runasPreco[i] = num;
    }

    for (j = 0; j < N; j++)
    {
        scanf("%d %d", &moedas, &nvl_atual_arma);

        if (nvl_atual_arma == 0)
        {
            for (i = 0; i < M; i++)
            {
                if(moedas - runasPreco[i] >= 0)
                {
                    cont++;
                }
            }
        }

        return 0;
    }