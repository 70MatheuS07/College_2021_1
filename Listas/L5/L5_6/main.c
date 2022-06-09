#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PreencheVetorA(int num[], int n1);
void PreencheVetorB(int num[], int n2);
int VarreComparaVetores(int numA[], int numB[], int n1, int n2);
void ImprimeResult(int rtn, int n1);

int main()
{
    int n1 = 0;
    int n2 = 0;
    int rtn = 0;

    scanf("%d", &n1);

    int numA[n1];

    PreencheVetorA(numA, n1);

    scanf("%d", &n2);

    int numB[n2];

    PreencheVetorB(numB, n2);

    rtn = VarreComparaVetores(numA, numB, n1, n2);

    ImprimeResult(rtn, n1);

    return 0;
}

void PreencheVetorA(int numA[], int n1)
{
    int i = 0;

    for (i = 0; i < n1; i++)
    {
        scanf("%d", &numA[i]);
    }
}

void PreencheVetorB(int numB[], int n2)
{
    int i = 0;

    for (i = 0; i < n2; i++)
    {
        scanf("%d", &numB[i]);
    }
}

int VarreComparaVetores(int numA[], int numB[], int n1, int n2)
{
    int i1 = 0;
    int i2 = 0;
    int cont = 0;

    for (i1 = 0; i1 < n1; i1++)
    {
        for (i2 = 0; i2 < n2; i2++)
        {
            if (numA[i1] == numB[i2])
            {
                cont++;
                break;
            }
        }
    }

    return cont;
}

void ImprimeResult(int rtn, int n1)
{
    if (rtn == 0)
    {
        printf("NENHUM");
    }

    else if (rtn == n1)
    {
        printf("TODOS");
    }

    else if (rtn > 0 && rtn < n1)
    {
        printf("PARCIAL");
    }
}

// resolver o problema do test_a.
// fazer mais test's depois, para confirmar.