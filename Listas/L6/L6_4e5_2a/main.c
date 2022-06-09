#include <stdio.h>

typedef struct Cartela
{
    int identificador;
    int tamanho;
    int num[100][100];

} tCartela;

tCartela LeCartela();

void ImprimeCartela(tCartela cartela);

int main()
{
    tCartela cartela;

    cartela = LeCartela();

    ImprimeCartela(cartela);

    return 0;
}

tCartela LeCartela()
{
    tCartela cartela;

    int i = 0, j = 0;

    scanf("%d %d", &cartela.identificador, &cartela.tamanho);

    for (i = 0; i < cartela.tamanho; i++)
    {
        for (j = 0; j < cartela.tamanho; j++)
        {
            scanf("%d", &cartela.num[j][i]);
        }
    }
    return cartela;
}

void ImprimeCartela(tCartela cartela)
{
    int i = 0, j = 0;

    printf("ID:%d\n", cartela.identificador);

    for (i = 0; i < cartela.tamanho; i++)
    {
        for (j = 0; j < cartela.tamanho; j++)
        {
            printf("%.3d", cartela.num[i][j]);

            if (j != cartela.tamanho - 1)
            {
                printf("|");
            }
        }

        printf("\n");
    }
}