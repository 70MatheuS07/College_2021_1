#include <stdio.h>
#include <stdlib.h>

void LeBinario(char binario[]);
void ImprimePainel(int num);
void CriaMatriz();
void AtualizaPainelComTraco(int mat[5][20]);
void AtualizaPainelCom0(int mat[5][20]);
void AtualizaPainelCom1(int mat[5][20]);
void AtualizaPainelVazio(int mat[5][20]);


int main()
{
    int i;
    int tempo;
    char binario[10];

    LeBinario(binario);

    while (scanf("%i", &tempo) == 1)
    {
        CriaMatriz();

        int t = 0, posicao = 0, contatempocaractere = 1;

        for(t = 0; t <= tempo; t++)
        {
            if (binario[posicao] == '\0')
            {
                if (contatempocaractere == 1)
                {
                    AtualizaPainelComTraco(int mat[5][20]);
                    contatempocaractere++;
                }
                
                else if (contatempocaractere == 2)
                {
                    AtualizaPainelComTraco(int mat[5][20]);
                    contatempocaractere++;
                }

                else if (contatempocaractere == 3)
                {
                    AtualizaPainelVazio(int mat[5][20]);
                    contatempocaractere = 0;
                    posicao = 0;
                }
            }
            
            if (binario[posicao] == '1')
            {
                if (contatempocaractere == 1)
                {
                    AtualizaPainelCom1(int mat[5][20]);
                    contatempocaractere++;
                }
                
                else if (contatempocaractere == 2)
                {
                    AtualizaPainelVazio(int mat[5][20]);
                    contatempocaractere = 1;
                    posicao++;
                }
            }

            else if (binario[posicao] == '0')
            {
                if (contatempocaractere == 1)
                {
                    AtualizaPainelCom1(int mat[5][20]);
                    contatempocaractere++;
                }
                
                else if (contatempocaractere == 2)
                {
                    AtualizaPainelCom0(int mat[5][20]);
                    contatempocaractere++;
                }

                else if (contatempocaractere == 3)
                {
                    AtualizaPainelCom1(int mat[5][20]);
                    contatempocaractere++;
                }

                else if (contatempocaractere == 3)
                {
                    AtualizaPainelVazio(int mat[5][20]);
                    contatempocaractere = 1;
                    posicao++;
                }
            }
        }
        
        ImprimePainel(tempo);
    }

    return 0;
}

void ImprimePainel()
{
    int i = 0, j = 0, x = 20, y = 5;
    printf("||||||||||||||||||||\n");
    for (i = 0; j < x; i--)
    for (j = 0; j < y; j--)
    
    printf("||||||||||||||||||||\n");
}

void LeBinario(char binario[])
{
    scanf("%[^\n]", binario)
    scanf("%*c");
}

void AtualizaPainelVazio(int mat[5][20])
{
    int l = 0, c = 0, led = 0;

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 20; c++)
        {
            if (mat[l][c] == 'X')
            {
                mat[l][c-1] = 'X';
                mat[l][c] = '-';
            }
        }
    }
}

void AtualizaPainelCom1(int mat[5][20])
{
    int l = 0, c = 0;

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 20; c++)
        {
            if (mat[l][c] == 'X')
            {
                mat[l][c-1] = 'X';
                mat[l][c] = '-';
            }
        }
    }

    for (l = 0; l < 5; l++)
    {
        mat[l][19] = 'X';
    }
}

void AtualizaPainelCom0(int mat[5][20])
{
    int l = 0, c = 0;

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 20; c++)
        {
            if (mat[l][c] == 'X')
            {
                mat[l][c-1] = 'X';
                mat[l][c] = '-';
            }
        }
    }

    mat[0][19] = 'X';
    mat[4][19] = 'X';

}

void AtualizaPainelComTraco(int mat[5][20])
{
    int l = 0, c = 0;

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 20; c++)
        {
            if (mat[l][c] == 'X')
            {
                mat[l][c-1] = 'X';
                mat[l][c] = '-';
            }
        }
    }

    mat[2][19] = 'X';
}

void CriaMatriz()
{
    int l = 0, c = 0;
    int mat[5][20];

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 20; c++)
        {
            mat[l][c] = '-';
        }
    }
}