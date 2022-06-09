#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int mensagem[100];
    int pacote[100];
    int tamanho[100];
    char string[100][11];
    int verificador[100];

} tPacotes;

tPacotes InicializaPacote(tPacotes pacote);

tPacotes LehPacote(tPacotes pacote);

void ImprimePacote(tPacotes pacote);

int main()
{
    tPacotes pacote;

    pacote = InicializaPacote(pacote);

    pacote = LehPacote(pacote);

    ImprimePacote(pacote);

    return 0;
}

tPacotes InicializaPacote(tPacotes pacote)
{
    int i, j;

    for (i = 0; i < 100; i++)
    {
        pacote.mensagem[i] = 0;
        pacote.pacote[i] = 0;
        pacote.tamanho[i] = 0;

        for (j = 0; j < 11; j++)
        {
            pacote.string[i][j] = '\0';
        }

        pacote.verificador[i] = 0;
    }

    return pacote;
}

tPacotes LehPacote(tPacotes pacote)
{
    char caracter, caracter1, caracter2, caracter3;
    int i = 0, j = 0;
    int msg = 0;
    int pc = 0;
    int t = 0;
    int vr = 0;

    while (scanf("%c", &caracter1) == 1)
    {
        scanf("%c%c%d ", &caracter2, &caracter3, &msg);

        scanf("%c%c%d ", &caracter1, &caracter2, &pc);

        scanf("%c%d ", &caracter1, &t);

        while (scanf("%c", &caracter) == 1)
        {
            if (j == 10)
            {
                j = 0;
                break;
            }

            else
            {
                pacote.string[pc - 1][j] = caracter;
                j++;
            }
        }

        scanf(" %c%c%d\n", &caracter1, &caracter2, &vr);

        pacote.mensagem[pc - 1] = msg;
        pacote.pacote[pc - 1] = pc;
        pacote.tamanho[pc - 1] = t;
        pacote.verificador[pc - 1] = vr;
    }

    return pacote;
}

void ImprimePacote(tPacotes pacote)
{
    int i = 0, j = 0, k = 0, l = 0;
    int qtd = 0;

    for (i = 0; i < 100; i++)
    {
        if (pacote.pacote[i] > 0)
        {
            printf("MENSAGEM: %d PACOTE: %d CONTEUDO: ", pacote.mensagem[i], pacote.pacote[i]);

            for (j = 0; j < pacote.tamanho[i]; j++)
            {
                printf("%c", pacote.string[i][j]);
            }

            printf("\n");
        }
    }

    printf("\n");

    for(i=0;i<100;i++)
    {}
}