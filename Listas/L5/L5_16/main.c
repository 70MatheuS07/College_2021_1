#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;

} tCandidato;

tCandidato LeCandidato();

void ImprimeCandidato(tCandidato candidato);

void OrdenaCrescente(tCandidato vetor[], int qtd);

void TrocaValor(tCandidato vetor[], int x, int y);

int main()
{
    int qtdCand, i = 0, j;

    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];

    for (i = 0; i < qtdCand; i++)
    {
        candidatos[i] = LeCandidato();
    }

    OrdenaCrescente(candidatos, qtdCand);

    for (i = 0; i < qtdCand; i++)
    {
        ImprimeCandidato(candidatos[i]);
    }

    return 0;
}

tCandidato LeCandidato()
{
    tCandidato candidato;
    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]\n");
    return candidato;
}

void OrdenaCrescente(tCandidato *vetor, int qtd)
{
    int i, menor, aux, j;

    for (i = 0; i < qtd - 1; i++)
    {
        for (j = i + 1; j < qtd; j++)
        {
            if (vetor[i].nota < vetor[j].nota)
            {
                TrocaValor(vetor, i, j);
            }
            else if (vetor[i].nota == vetor[j].nota)
            {
                if (vetor[i].idade > vetor[j].idade)
                {
                    TrocaValor(vetor, i, j);
                }
                else if (vetor[i].idade == vetor[j].idade)
                {
                    if (vetor[i].codigo > vetor[j].codigo)
                    {
                        TrocaValor(vetor, i, j);
                    }
                }
            }
        }
    }
}

void TrocaValor(tCandidato vetor[], int x, int y)
{
    tCandidato aux;

    aux = vetor[y];
    vetor[y] = vetor[x];
    vetor[x] = aux;
}

void ImprimeCandidato(tCandidato candidato)
{
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
}