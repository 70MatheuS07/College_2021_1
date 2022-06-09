#include <stdio.h>

int main()
{
    int troco1 = 0, troco2 = 0;
    int dinheiro1 = 0, dinheiro2 = 0;
    int notasDeCinco1 = 0, notasDeUm1 = 0;
    int notasDeCinco2 = 0, notasDeUm2 = 0;
    int notasTotais1 = 0, notasTotais2 = 0;
    int diferenca = 0;

    scanf("%d %d", &troco1, &troco2);

    while (troco1 != dinheiro1)
    {
        diferenca = troco1 - dinheiro1;

        if (diferenca >= 5)
        {
            dinheiro1 += 5;
            notasDeCinco1 += 1;
        }

        else if (diferenca < 5)
        {
            dinheiro1 += 1;
            notasDeUm1 += 1;
        }
    }

    while (troco2 != dinheiro2)
    {
        diferenca = troco2 - dinheiro2;

        if (diferenca >= 5)
        {
            dinheiro2 += 5;
            notasDeCinco2 += 1;
        }

        else if (diferenca < 5)
        {
            dinheiro2 += 1;
            notasDeUm2 += 1;
        }
    }

    notasTotais1 = notasDeCinco1 + notasDeUm1;
    notasTotais2 = notasDeCinco2 + notasDeUm2;

    if (notasTotais1 > notasTotais2)
    {
        printf("QTD troco 1 eh maior!");
    }

    else if (notasTotais2 > notasTotais1)
    {
        printf("QTD troco 2 eh maior!");
    }

    else
    {
        printf("Iguais!");
    }

    return 0;
}