#include <stdio.h>

int main()
{
    int qtdDeGeneros = 0, i = 0;
    int valorCritica = 0, maiorNota = -1, menorNota = 6;
    int mediaDoGenero = 0, numerador = 0, denominador = 1;
    int maiorNotaGeral = -1, menorNotaGeral = 6;
    int filmeMaisPopular = -1;
    int criticasTotalGenero = 0;
    int generoMaisPopular = -1;
    int maiorMediaDoGenero = -1;
    int maiorNotaGeneroMaisPopular = 0;
    int filmesSemCriticas = 0;

    char letra;
    char genero1, genero2, genero3;
    char filme1, filme2, filme3;
    char filmeMaiorNota1, filmeMaiorNota2, filmeMaiorNota3;
    char filmeMenorNota1, filmeMenorNota2, filmeMenorNota3;
    char filmeMaiorNotaGeral1, filmeMaiorNotaGeral2, filmeMaiorNotaGeral3;
    char filmeMenorNotaGeral1, filmeMenorNotaGeral2, filmeMenorNotaGeral3;
    char filmeMaisPopular1, filmeMaisPopular2, filmeMaisPopular3;
    char generoMaisPopular1, generoMaisPopular2, generoMaisPopular3;
    char maiorMediaDoGenero1, maiorMediaDoGenero2, maiorMediaDoGenero3;

    scanf("%d\n", &qtdDeGeneros);

    for (i = 1; i <= qtdDeGeneros; i++)
    {
        scanf("#%c%c%c\n", &genero1, &genero2, &genero3);

        while (scanf("%c%c%c ", &filme1, &filme2, &filme3) == 3)
        {
            if (filme1 == 'F' && filme2 == 'I' && filme3 == 'M')
            {
                break;
            }

            else
            {
                scanf("%*c");

                while (scanf("%d%*c", &valorCritica) == 1)
                {
                    if (valorCritica > maiorNota)
                    {
                        maiorNota = valorCritica;

                        filmeMaiorNota1 = filme1;
                        filmeMaiorNota2 = filme2;
                        filmeMaiorNota3 = filme3;
                    }

                    if (valorCritica < menorNota)
                    {
                        menorNota = valorCritica;

                        filmeMenorNota1 = filme1;
                        filmeMenorNota2 = filme2;
                        filmeMenorNota3 = filme3;
                    }

                    if (maiorNota > maiorNotaGeral)
                    {
                        maiorNotaGeral = maiorNota;

                        filmeMaiorNotaGeral1 = filme1;
                        filmeMaiorNotaGeral2 = filme2;
                        filmeMaiorNotaGeral3 = filme3;
                    }

                    if (menorNotaGeral > menorNota)
                    {
                        menorNotaGeral = menorNota;

                        filmeMenorNotaGeral1 = filme1;
                        filmeMenorNotaGeral2 = filme2;
                        filmeMenorNotaGeral3 = filme3;
                    }

                    numerador += valorCritica;
                    denominador += 1;

                    if (filmeMaisPopular < denominador)
                    {
                        filmeMaisPopular = denominador;

                        filmeMaisPopular1 = filme1;
                        filmeMaisPopular2 = filme2;
                        filmeMaisPopular3 = filme3;
                    }
                }
            }

            mediaDoGenero = numerador / denominador;

            if (maiorMediaDoGenero < mediaDoGenero)
            {
                maiorMediaDoGenero = mediaDoGenero;

                maiorMediaDoGenero1 = genero1;
                maiorMediaDoGenero2 = genero2;
                maiorMediaDoGenero3 = genero3;
            }

            criticasTotalGenero += denominador;

            if (generoMaisPopular < criticasTotalGenero)
            {
                generoMaisPopular = criticasTotalGenero;

                generoMaisPopular1 = genero1;
                generoMaisPopular2 = genero2;
                generoMaisPopular3 = genero3;

                maiorNotaGeneroMaisPopular = maiorNota;
            }
        }

        printf("FILME DO GENERO %c%c%c COM MAIOR NOTA: %c%c%c (%d)\n", genero1, genero2, genero3, filmeMaiorNota1, filmeMaiorNota2, filmeMaiorNota3, maiorNota);

        printf("FILME DO GENERO %c%c%c COM MENOR NOTA: %c%c%c (%d)\n", genero1, genero2, genero3, filmeMenorNota1, filmeMenorNota2, filmeMenorNota3, menorNota);

        printf("MEDIA DO GENERO %c%c%c: %d\n\n", genero1, genero2, genero3, mediaDoGenero);

        scanf("\n");

        maiorNota = -1;
        menorNota = 6;
        numerador = 0;
        denominador = 1;
        mediaDoGenero = 0;
    }

    printf("FILME GERAL COM MAIOR NOTA: %c%c%c (%d)\n", filmeMaiorNota1, filmeMaiorNota2, filmeMaiorNota3, maiorNotaGeral);

    printf("FILME GERAL COM MENOR NOTA: %c%c%c (%d)\n", filmeMenorNota1, filmeMenorNota2, filmeMenorNota3, menorNotaGeral);

    printf("FILME MAIS POPULAR: %c%c%c (%d CRITICAS)\n", filmeMaisPopular1, filmeMaisPopular2, filmeMaisPopular3, filmeMaisPopular);

    printf("GENERO MAIS POPULAR: %c%c%c (%d CRITICAS)\n", generoMaisPopular1, generoMaisPopular2, generoMaisPopular3, generoMaisPopular);

    printf("GENERO COM MAIOR MEDIA TRUNCADA: %c%c%c (%d)\n", maiorMediaDoGenero1, maiorMediaDoGenero2, maiorMediaDoGenero3, maiorMediaDoGenero);

    printf("FILME COM MAIOR NOTA DO GENERO MAIS POPULAR: %c%c%c (%d)\n", generoMaisPopular1, generoMaisPopular2, generoMaisPopular3, maiorNotaGeneroMaisPopular);

    printf("FILMES QUE NAO POSSUEM CRITICAS: %d", filmesSemCriticas);

    return 0;
}