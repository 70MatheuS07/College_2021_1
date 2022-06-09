#include <stdio.h>

int main()
{
    int n;
    int i;
    int num;
    int cont_par = 0;
    int cont_impar = 0;

    scanf("%d\n", &n);

    int vetor[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        vetor[i] = num;
    }

    for (i = 0; i < n; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            cont_par++;
        }
        else
        {
            cont_impar++;
        }
    }

    if (vetor[0] % 2 == 0)
    {
        printf("QTD PARES:%d", cont_par);
    }
    else
    {
        printf("QTD IMPARES:%d", cont_impar);
    }

    return 0;
}