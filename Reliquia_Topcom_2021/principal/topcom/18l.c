#include <stdio.h>
#include <string.h>

void ZeraMatriz(int numPessoas, int mat[numPessoas][100]);

int main()
{
    int i, j, numPessoas, amigosEmComum, numAmigos, j, amigo;

    scanf("%d", &numPessoas);

    int matriz[numPessoas][100];

    ZeraMatriz(numPessoas, matriz);

    for (i = 0; i < numPessoas; i++)
    {
        scanf("%d", &numAmigos);

        for (j = 0; j < numAmigos; j++)
        {
            scanf("%d", &amigo);

            matriz[i][j] = amigo;
        }
    }

    amigosEmComum = AmigosEmComum(numPessoas, matriz);
    
    if (amigosEmComum == 0)
    {
        printf("IMPOSSIVEL !");
    }
    else
    {
        printf("%d amigos em comum !", amigosEmComum);
    }
    return 0;
}

void ZeraMatriz(int numPessoas, int mat[numPessoas][100])
{
    int l = 0, c = 0;

    for (l = 0; l < numPessoas; l++)
    {
        for (c = 0; c < 100; c++)
        {
            mat[l][c] = 0;
        }
    }
}

int AmigosEmComum(int numPessoas, int mat[numPessoas][100])
{
    int l = 0, c = 0, amigosEmComum = 0, procurado = 0, proximasLinhas, proximasColunas;

    for (l = 0; l < numPessoas; l++)
    {
        while (mat[l][c] != 0)
        {
            procurado = mat[l][c];

            for (proximasLinhas = l + 1; proximasLinhas < numPessoas; proximasLinhas++)
            {
                proximasColunas = 0;

                while (mat[proximasLinhas][proximasColunas] != 0)
                {
                    if (mat[proximasLinhas][proximasColunas] == procurado)
                    {
                        amigosEmComum++;
                    }
                    proximasColunas++;
                }

                c++;
            }
        }
    }
    return amigosEmComum;
}
