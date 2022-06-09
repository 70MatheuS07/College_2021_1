#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int lucro = 0;

typedef struct filme
{
    int codigo;
    char nome[20];
    int qnt;
    int valor;
    int alugados;

} tFilme;

typedef struct locadora
{
    tFilme filmes[1024];
    int qntfilmes;

} tLocadora;

int BuscarFilme(tLocadora locadora, int codigo);

tLocadora orderArray(tLocadora locadora);

tLocadora Cadastrar();

tLocadora Devolver(tLocadora locadora);

tLocadora Alugar(tLocadora locadora);

void Estoque(tLocadora locadora);

int main()
{
    tLocadora locadora;

    char str[256];

    while (scanf("%s", str) == 1)
    {
        if (strcmp(str, "#") == 0)
        {
            continue;
        }

        if (strcmp(str, "Cadastrar") == 0)
        {
            locadora = Cadastrar(locadora);
            scanf("%s", str);
            printf("\n");
        }

        else if (strcmp(str, "Devolver") == 0)
        {
            locadora = Devolver(locadora);
            scanf("%s", str);
            printf("\n");
        }

        else if (strcmp(str, "Alugar") == 0)
        {
            locadora = Alugar(locadora);
            scanf("%s", str);
            printf("\n");
        }

        else if (strcmp(str, "Estoque") == 0)
        {
            Estoque(locadora);
        }
    }

    if (lucro)
    {
        printf("Lucro total R$%d\n", lucro);
    }

    return 0;
}

tLocadora orderArray(tLocadora locadora)
{
    int i = 0;
    int j = 0;

    tFilme filme_aux;

    for (i = 0; i < locadora.qntfilmes; i++)
    {
        for (j = i + 1; j < locadora.qntfilmes; j++)
        {
            if (strcmp(locadora.filmes[i].nome, locadora.filmes[j].nome) > 0)
            {
                filme_aux = locadora.filmes[i];
                locadora.filmes[i] = locadora.filmes[j];
                locadora.filmes[j] = filme_aux;
            }
        }
    }

    return locadora;
}

tLocadora Cadastrar()
{
    tLocadora locadora;
    locadora.qntfilmes = 0;

    int codigo;
    char nome[20];
    int qnt;
    int valor;
    int i = locadora.qntfilmes;

    while (1)
    {
        if (scanf("%d", &codigo) != 1)
            break;

        scanf(",%[^,],%d,%d", nome, &valor, &qnt);
        if (BuscarFilme(locadora, codigo))
        {
            printf("Filme ja cadastrado no estoque\n");
            continue;
        }

        locadora.filmes[i].codigo = codigo;
        strcpy(locadora.filmes[i].nome, nome);
        locadora.filmes[i].qnt = qnt;
        locadora.filmes[i].valor = valor;
        locadora.filmes[i].alugados = 0;
        locadora.qntfilmes++;
        i++;
        printf("Filme cadastrado %d - %s\n", codigo, nome);
        // printf("\nCadastros: %d\n", locadora.qntfilmes);
    }
    return locadora;
}

int BuscarFilme(tLocadora locadora, int codigo)
{
    int i = 0;

    for (i = 0; i < locadora.qntfilmes; i++)
    {
        if (locadora.filmes[i].codigo == codigo)
            return 1;
    }
    return 0;
}

tLocadora Devolver(tLocadora locadora)
{
    int codigo;
    int i;

    while (1)
    {
        if (scanf("%d", &codigo) != 1)
            break;

        for (i = 0; i < locadora.qntfilmes; i++)
        {
            if (codigo == locadora.filmes[i].codigo)
            {

                if (locadora.filmes[i].alugados == 0)
                {
                    printf("Nao e possivel devolver o filme %d - %s.\n", codigo, locadora.filmes[i].nome);
                }
                else if (locadora.filmes[i].alugados > 0)
                {
                    locadora.filmes[i].alugados--;
                    lucro += locadora.filmes[i].valor;
                    printf("Filme %d - %s Devolvido!\n", locadora.filmes[i].codigo, locadora.filmes[i].nome);
                }
                //return;
            }
        }
    }
    return locadora;
}

tLocadora Alugar(tLocadora locadora)
{
    int codigo;
    int total_alugados = 0;
    int n_alugados = 0;
    int i;
    int found = 0;
    while (1)
    {
        found = 0;
        if (scanf("%d", &codigo) != 1)
            break;

        for (i = 0; i < locadora.qntfilmes; i++)
        {
            if (codigo == locadora.filmes[i].codigo)
            {
                found = 1;
                if (locadora.filmes[i].alugados < locadora.filmes[i].qnt)
                {
                    locadora.filmes[i].alugados++;
                    total_alugados += locadora.filmes[i].valor;
                    n_alugados++;
                }
                else
                {
                    printf("Filme %d - %s nao disponivel no estoque. Volte mais tarde.\n", codigo, locadora.filmes[i].nome);
                }
            }
        }
        if (!found)
        {
            printf("Filme %d nao cadastrado.\n", codigo);
        }
    }
    if (n_alugados)
        printf("Total de filmes alugados: %d com custo de R$%d\n", n_alugados, total_alugados);

    return locadora;
}

void Estoque(tLocadora locadora)
{
    locadora = orderArray(locadora);
    int i = 0;
    printf("~ESTOQUE~\n");
    for (i = 0; i < locadora.qntfilmes; i++)
    {
        printf("%d - %s Fitas em estoque: %d\n", locadora.filmes[i].codigo, locadora.filmes[i].nome, locadora.filmes[i].qnt - locadora.filmes[i].alugados);
    }
}