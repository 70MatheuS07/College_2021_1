#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PreencheVetor(int num[], int n);
void OrdenaCrescente(int num[], int n);
void ImprimeVetor(int num[], int n);

int main()
{
    int n = 0;

    scanf("%d", &n);

    int num[n];

    PreencheVetor(num, n);

    OrdenaCrescente(num, n);

    ImprimeVetor(num, n);

    return 0;
}

void PreencheVetor(int num[], int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
}

void OrdenaCrescente(int num[], int n)
{
    int i1 = 0;
    int i2 = 0;
    int num_maior = 0, num_menor = 0;

    for (i1 = 0; i1 < n; i1++)
    {
        for (i2 = 0; i2 < n; i2++)
        {
            if (num[i1] < num[i2])
            {
                num_maior = num[i1];
                num_menor = num[i2];

                num[i2] = num_maior;
                num[i1] = num_menor;
            }
        }
    }
}

void ImprimeVetor(int num[], int n)
{
    int i = 0;

    printf("{");

    for (i = 0; i < n; i++)
    {
        printf("%d", num[i]);

        if (i < n - 1)
        {
            printf(", ");
        }
    }

    printf("}");
}