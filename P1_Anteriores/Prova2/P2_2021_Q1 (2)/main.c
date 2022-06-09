#include <stdio.h>
#include <string.h>

void InicializaMatriz(char matriz[50][60]);

void LeCacaPalavras(char matriz[50][60]);

void ImprimeCacaPalavras(char matriz[50][60]);

void ProcuraPalavras(char matriz[50][60]);

int LePalavra(char palavra[41]);

void ImprimePalavraHorizontal(char palavra[41], int x, int k, int guarda_inicio);

void ImprimePalavraVertical(char palavra[41], int i, int p, int q);

void ImprimePalavraDiagonal(char palavra[41], int k, int l, int guarda_inicio_l, int guarda_inicio_k);

void PalavraNaoEncontrada(char palavra[41]);

int main()
{
    char matriz[50][60];

    InicializaMatriz(matriz);

    LeCacaPalavras(matriz);

    ProcuraPalavras(matriz);

    return 0;
}

void InicializaMatriz(char matriz[50][60])
{
    int i, j;

    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 60; j++)
        {
            matriz[i][j] = '0';
        }
    }
}

void LeCacaPalavras(char matriz[50][60])
{
    int i, j;
    char c;

    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 60; j++)
        {
            scanf("%c", &c);

            if (c == '#')
            {
                scanf("\n");
                return;
            }

            else if (c == '\n')
            {
                break;
            }
            else
            {
                matriz[i][j] = c;
            }
        }
    }
}

void ImprimeCacaPalavras(char matriz[50][60])
{
    int i, j;

    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 60; j++)
        {
            if (matriz[i][j] != '0')
            {
                printf("%c", matriz[i][j]);
            }
        }

        printf("\n");
    }
}

void ProcuraPalavras(char matriz[50][60])
{
    int cont = 0, x = 0;
    int i = 0, j = 0;
    int k = 0, l = 0;
    int p = 0, q = 0;
    int cont_verifica = 0;
    int guarda_inicio = 0;
    int lido = 0;
    int guarda_inicio_l = 0;
    int guarda_inicio_k = 0;

    char palavra[41];

    while (LePalavra(palavra) == 1)
    {
        cont = 0;

        while (palavra[cont] != '\0')
        {
            cont++;
        }

        k = 0;
        lido = 0;

        for (i = 0; i < 50; i++)
        {
            for (j = 0; j < 60; j++)
            {
                if (matriz[i][j] != '0')
                {
                    k = i;
                    l = j;
                    x = 0;

                    while (palavra[x] == matriz[k][l] && palavra[x] != '\0')
                    {
                        if (cont_verifica == 0)
                        {
                            guarda_inicio = l;
                        }

                        cont_verifica++;
                        x++;
                        l++;
                    }

                    if (cont == cont_verifica)
                    {
                        k += 1;
                        guarda_inicio += 1;
                        x = guarda_inicio + cont - 1;

                        ImprimePalavraHorizontal(palavra, x, k, guarda_inicio);
                        cont_verifica = 0;
                        lido += 1;
                    }
                    else
                    {
                        cont_verifica = 0;
                    }
                }
            }
        }

        if (lido == 0)
        {
            for (i = 0; i < 50; i++)
            {
                for (j = 0; j < 60; j++)
                {
                    if (matriz[i][j] != '0')
                    {
                        k = i;
                        l = j;
                        x = 0;

                        while (palavra[x] == matriz[k][l] && palavra[x] != '\0')
                        {
                            if (cont_verifica == 0)
                            {
                                guarda_inicio = k;
                            }

                            cont_verifica++;
                            x++;
                            k++;
                        }

                        if (cont == cont_verifica)
                        {
                            l += 1;
                            guarda_inicio += 1;
                            x = guarda_inicio + cont - 1;

                            ImprimePalavraVertical(palavra, x, l, guarda_inicio);
                            cont_verifica = 0;
                            lido += 1;
                        }
                        else
                        {
                            cont_verifica = 0;
                        }
                    }
                }
            }
        }

        if (lido == 0)
        {
            for (i = 49; i >= 0; i--)
            {
                for (j = 59; j >= 0; j--)
                {
                    if (matriz[i][j] != '0')
                    {
                        k = i;
                        l = j;
                        x = 0;

                        while (palavra[x] == matriz[k][l] && palavra[x] != '\0')
                        {
                            if (cont_verifica == 0)
                            {
                                guarda_inicio = l;
                            }

                            cont_verifica++;
                            x++;
                            l--;
                        }

                        if (cont == cont_verifica)
                        {
                            k += 1;
                            guarda_inicio += 1;
                            x = guarda_inicio - cont + 1;

                            ImprimePalavraHorizontal(palavra, x, k, guarda_inicio);
                            cont_verifica = 0;
                            lido += 1;
                        }
                        else
                        {
                            cont_verifica = 0;
                        }
                    }
                }
            }
        }

        if (lido == 0)
        {
            for (i = 0; i < 50; i++)
            {
                for (j = 59; j >= 0; j--)
                {
                    if (matriz[i][j] != '0')
                    {
                        k = i;
                        l = j;
                        x = 0;

                        while (palavra[x] == matriz[k][l] && palavra[x] != '\0')
                        {
                            if (cont_verifica == 0)
                            {
                                guarda_inicio = k;
                            }

                            cont_verifica++;
                            x++;
                            k--;
                        }

                        if (cont == cont_verifica)
                        {
                            l += 1;
                            guarda_inicio += 1;
                            x = guarda_inicio - cont + 1;

                            ImprimePalavraVertical(palavra, x, l, guarda_inicio);
                            cont_verifica = 0;
                            lido += 1;
                        }
                        else
                        {
                            cont_verifica = 0;
                        }
                    }
                }
            }
        }

        if (lido == 0)
        {
            for (i = 0; i < 50; i++)
            {
                for (j = 0; j < 60; j++)
                {
                    if (matriz[i][j] != '0')
                    {
                        k = i;
                        l = j;
                        x = 0;

                        while (palavra[x] == matriz[k][l] && palavra[x] != '\0')
                        {
                            if (cont_verifica == 0)
                            {
                                guarda_inicio_l = l;
                                guarda_inicio_k = k;
                            }

                            cont_verifica++;
                            x++;
                            l++;
                            k++;
                        }

                        if (cont == cont_verifica)
                        {

                            guarda_inicio_l += 1;
                            guarda_inicio_l = l - cont + 1;
                            guarda_inicio_k += 1;
                            guarda_inicio_k = k - cont + 1;

                            ImprimePalavraDiagonal(palavra, k, l, guarda_inicio_l, guarda_inicio_k);
                            cont_verifica = 0;
                            lido += 1;
                        }
                        else
                        {
                            cont_verifica = 0;
                        }
                    }
                }
            }
        }

        if (lido == 0)
        {
            PalavraNaoEncontrada(palavra);
        }
    }
}

int LePalavra(char palavra[41])
{
    char c;
    int i = 0;

    while (scanf("%c", &c) == 1)
    {
        if (c == '\n')
        {
            palavra[i] = '\0';
            return 1;
        }
        else
        {
            palavra[i] = c;
            i++;
        }
    }

    return 0;
}

void ImprimePalavraHorizontal(char palavra[41], int x, int k, int guarda_inicio)
{
    int z;

    for (z = 0; z < 41; z++)
    {
        if (palavra[z] == '\0')
        {
            break;
        }
        else
        {
            printf("%c", palavra[z]);
        }
    }

    printf(" - (%d,%d) - (%d,%d)\n", k, guarda_inicio, k, x);
}

void ImprimePalavraVertical(char palavra[41], int x, int l, int guarda_inicio)
{
    int z;

    for (z = 0; z < 41; z++)
    {
        if (palavra[z] == '\0')
        {
            break;
        }
        else
        {
            printf("%c", palavra[z]);
        }
    }

    printf(" - (%d,%d) - (%d,%d)\n", guarda_inicio, l, x, l);
}

void ImprimePalavraDiagonal(char palavra[41], int k, int l, int guarda_inicio_l, int guarda_inicio_k)
{
    int z;

    for (z = 0; z < 41; z++)
    {
        if (palavra[z] == '\0')
        {
            break;
        }
        else
        {
            printf("%c", palavra[z]);
        }
    }

    printf(" - (%d,%d) - (%d,%d)\n", guarda_inicio_k, guarda_inicio_l, k, l);
}

void PalavraNaoEncontrada(char palavra[41])
{
    int z;

    for (z = 0; z < 41; z++)
    {
        if (palavra[z] == '\0')
        {
            break;
        }
        else
        {
            printf("%c", palavra[z]);
        }
    }

    printf(" - NAO ENCONTRADA!\n");
}