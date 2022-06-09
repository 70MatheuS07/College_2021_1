#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PreencheVetor(int num[], int n);
int AnalisaProgressaoAritmetica(int num[], int n);
void ImprimeProgressaoAritmetica(int rtn);

int main()
{
    int n = 0;
    int rtn = -1;

    scanf("%d", &n);

    int num[n];

    PreencheVetor(num, n);

    rtn = AnalisaProgressaoAritmetica(num, n);

    ImprimeProgressaoAritmetica(rtn);

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

int AnalisaProgressaoAritmetica(int num[], int n)
{
    int i = 0;
    int razao = 0;
    int razaoPositiva = -1;
    int razaoNegativa = 1;
    int razaoAnterior = 0;
    int a = i + 1;
    int cont = 0;

    for (i = 0; i < n; i++)
    {
        if (n == 1)
        {
            razao = -2147483647;

            return razao;
        }

        else if (n == 2)
        {
            if (num[i] > num[a])
            {
                razao = num[a] - num[i];

                return razao;
            }

            else if (num[i] < num[a])
            {
                razao = num[i] - num[a];

                return razao;
            }
        }

        else if (n >= 3)
        {

            a = i + 1;

            razao = num[a] - num[i];

            if (i == 0)
            {
                razaoAnterior = razao;
            }

            else if (a < n)
            {
                if (razao == razaoAnterior)
                {
                    if (a == n - 1)
                    {
                        return razao;
                    }
                }
                else
                {
                    cont = -2147483647;

                    return cont;
                }
            }
        }
    }
}

void ImprimeProgressaoAritmetica(int rtn)
{
    if (rtn == -2147483647)
    {
        printf("NAO");
    }
    else
    {
        printf("RESP:%d", rtn);
    }
}