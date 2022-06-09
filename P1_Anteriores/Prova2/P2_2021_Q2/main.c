#include <stdio.h>
#include <string.h>

typedef struct locadora
{
    int vetor_codigo[21];
    char vetor_nome[21][20];
    int vetor_valor[21];
    int vetor_qtd[21];
    int qtd_filmes;

} tLocadora;

typedef struct filme
{
    int codigo;
    char nome[20];
    int valor;
    int qtd_disponivel;

} tFilme;

tLocadora CadastraFilmeLocadora(tLocadora locadora, char nome[20], int codigo, int valor, int quantidade);

void ConsultaEstoqueLocadora(tLocadora locadora);

void ImprimeCadastroLocadora(tLocadora locadora);

void OrdenaCrescente(tLocadora locadora);

void TrocaValor(tLocadora locadora, int x, int y);

int main()
{
    tLocadora locadora;

    tFilme filme;

    int codigo;
    char nome[20];
    int valor;
    int quantidade;

    int i = 0;
    char c;

    char string[10];
    char Estoque[8] = {'E', 's', 't', 'o', 'q', 'u', 'e'};
    char Cadastrar[10] = {'C', 'a', 'd', 'a', 's', 't', 'r', 'a', 'r'};

    scanf("%s", &*string);

    if (strcmp(string, Cadastrar) == 0)
    {
        locadora = CadastraFilmeLocadora(locadora, nome, codigo, valor, quantidade);

        ImprimeCadastroLocadora(locadora);
    }

    scanf("%s", &*string);

    if (strcmp(string, Estoque) == 0)
    {
        ConsultaEstoqueLocadora(locadora);
    }

    return 0;
}

tLocadora CadastraFilmeLocadora(tLocadora locadora, char nome[20], int codigo, int valor, int quantidade)
{
    char c;
    int z = 0;
    int i = 0, j = 0;
    int k = 0, l = 0;

    while (scanf("%d,", &codigo) == 1)
    {
        z = 0;

        while (scanf("%c", &c) == 1)
        {
            if (c == ',')
            {
                nome[z] = '\0';
                break;
            }
            else
            {
                nome[z] = c;
                z++;
            }
        }

        scanf("%d,%d\n", &valor, &quantidade);

        locadora.vetor_codigo[k] = codigo;

        for (j = 0; j < 20; j++)
        {
            locadora.vetor_nome[k][j] = nome[j];

            if (nome[j] == '\0')
            {
                break;
            }
        }

        locadora.vetor_valor[k] = valor;

        locadora.vetor_qtd[k] = quantidade;

        k++;
    }

    scanf("#");

    locadora.qtd_filmes = k;

    return locadora;
}

void ImprimeCadastroLocadora(tLocadora locadora)
{
    int i;

    for (i = 0; i < locadora.qtd_filmes; i++)
    {
        printf("Filme cadastrado %d - %s\n", locadora.vetor_codigo[i], locadora.vetor_nome[i]);
    }

    printf("\n");
}

void ConsultaEstoqueLocadora(tLocadora locadora)
{
    int i = 0;

    printf("~ESTOQUE~\n");

    if (locadora.qtd_filmes == 1)
    {
        printf("%d - %s Fitas em estoque: %d\n", locadora.vetor_codigo[i], locadora.vetor_nome[i], locadora.vetor_qtd[i]);
    }
    else
    {
        locadora = OrdenaCrescente(locadora);

        for (i = 0; i < locadora.qtd_filmes; i++)
        {

            printf("%d - %s Fitas em estoque: %d\n", locadora.vetor_codigo[i], locadora.vetor_nome[i], locadora.vetor_qtd[i]);
        }
    }
}

tLocadora OrdenaCrescente(tLocadora locadora)
{
    int i, menor, aux, j;
    int k = 0, l = 1;

    for (i = 0; i < locadora.qtd_filmes - 1; i++)
    {
        for (j = i + 1; j < locadora.qtd_filmes; j++)
        {
            if (strcmp(locadora.vetor_nome[i][j], locadora.vetor_nome[j][j]) > 0)
            {
                TrocaValor(vetor, i, j);
            }
        }

        k++;
        l++;
    }
}