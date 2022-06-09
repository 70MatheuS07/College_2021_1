#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PreencheVetor_A(int numA[], int n1);
void PreencheVetor_B(int numB[], int n2);
void OrdenaCrescente_A(int numA[], int n1);
void OrdenaCrescente_B(int numB[], int n2);
void ImprimeComparaAeB(int numA[], int numB[], int n1, int n2);

int main()
{
    int n1 = 0;
    int n2 = 0;
    int rtn = 0;

    scanf("%d", &n1);

    int numA[n1];

    PreencheVetor_A(numA, n1);

    scanf("%d", &n2);

    int numB[n2];

    PreencheVetor_B(numB, n2);

    OrdenaCrescente_A(numA, n1);

    OrdenaCrescente_B(numB, n2);

    ImprimeComparaAeB(numA, numB, n1, n2);

    return 0;
}

void PreencheVetor_A(int numA[], int n1)
{
    int i = 0;

    for (i = 0; i < n1; i++)
    {
        scanf("%d", &numA[i]);
    }
}

void PreencheVetor_B(int numB[], int n2)
{
    int i = 0;

    for (i = 0; i < n2; i++)
    {
        scanf("%d", &numB[i]);
    }
}

void OrdenaCrescente_A(int numA[], int n1)
{
    int i1 = 0;
    int i2 = 0;
    int num_maior = 0, num_menor = 0;

    for (i1 = 0; i1 < n1; i1++)
    {
        for (i2 = 0; i2 < n1; i2++)
        {
            if (i1 != i2 && numA[i1] < numA[i2])
            {
                num_maior = numA[i1];
                num_menor = numA[i2];

                numA[i2] = num_maior;
                numA[i1] = num_menor;
            }
        }
    }
}

void OrdenaCrescente_B(int numB[], int n2)
{
    int i1 = 0;
    int i2 = 0;
    int num_maior = 0, num_menor = 0;

    for (i1 = 0; i1 < n2; i1++)
    {
        for (i2 = 0; i2 < n2; i2++)
        {
            if (i1 != i2 && numB[i1] < numB[i2])
            {
                num_maior = numB[i1];
                num_menor = numB[i2];

                numB[i2] = num_maior;
                numB[i1] = num_menor;
            }
        }
    }
}

void ImprimeComparaAeB(int numA[], int numB[], int n1, int n2)
{
    int i = 0, j = 0;
    int cont_A = 0, cont_B = 0;

    for (i = 0; i < n1; i++)
    {
        for (j = cont_B; j < n2; j++)
        {
            if (numA[i] <= numB[j])
            {
                printf("A");
                cont_A++;
                break;
            }

            else if (numB[j] < numA[i])
            {
                printf("B");
                cont_B++;
            }
        }

        if (i == n1 - 1)
        {
            while (cont_A != n1)
            {
                printf("A");
                cont_A++;
            }

            while (cont_B != n2)
            {
                printf("B");
                cont_B++;
            }
        }
    }
}

// terminar de montar ImprimeComparaAeB.