#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char titulo[101];
    int edicao;
    int preco_adquirido;
    int linha;
    int coluna;

} tRevista;

typedef struct
{
    int prateleira[10][15];
    tRevista revista[150];
    int aquisicaoQuantidade;
    int aquisicaoValor;
    int vendaQuantidade;
    int vendaValor;

} tSebo;

tSebo InicializaSebo(tSebo sebo);

tSebo CadastrarRevistasSebo(tSebo sebo);

void ConsultarAcervoSebo(tSebo sebo);

tSebo VenderRevistasSebo(tSebo sebo);

void ConsultarCaixaSebo(tSebo sebo);

void InicializaTitulo_lido(char titulo_lido[101]);

void LehTitulo(char titulo_lido[101]);

int Verifica_id(tSebo sebo, int id_lido);

int VerificaLinhaColuna(tSebo sebo, int linha_lido, int coluna_lido);

int main()
{
    tSebo sebo;

    int i = 0;

    char caracter;
    char string[17];
    char consulta[17] = {"CONSULTAR-ACERVO"};
    char cadastro[10] = {"CADASTRAR"};
    char vende[7] = {"VENDER"};
    char caixa[16] = {"CONSULTAR-CAIXA"};

    while (scanf("%c", &caracter) == 1)
    {
        for (i = 0; i < 17; i++)
        {
            string[i] = '\0';
        }

        scanf("\n%s\n", string);

        if (strcmp(string, consulta) == 0)
        {
            printf("#\n");
            ConsultarAcervoSebo(sebo);
        }

        else if (strcmp(string, cadastro) == 0)
        {
            printf("#\n");
            sebo = CadastrarRevistasSebo(sebo);
        }

        else if (strcmp(string, vende) == 0)
        {
            printf("#\n");
            sebo = VenderRevistasSebo(sebo);
        }

        else if (strcmp(string, caixa) == 0)
        {
            printf("#\n");
            ConsultarCaixaSebo(sebo);
        }
    }

    printf("#\n");

    return 0;
}

tSebo InicializaSebo(tSebo sebo)
{
    int i, j;
    int k = 0, l = 0;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 15; j++)
        {
            sebo.prateleira[i][j] = -1;
        }
    }

    for (i = 0; i < 150; i++)
    {
        sebo.revista[i].coluna = 0;
        sebo.revista[i].edicao = 0;
        sebo.revista[i].id = 0;
        sebo.revista[i].linha = 0;
        sebo.revista[i].preco_adquirido = 0;

        for (j = 0; j < 101; j++)
        {
            sebo.revista[i].titulo[j] = '\0';
        }
    }

    sebo.aquisicaoValor = 0;
    sebo.aquisicaoQuantidade = 0;
    sebo.vendaValor = 0;
    sebo.vendaQuantidade = 0;

    return sebo;
}

tSebo CadastrarRevistasSebo(tSebo sebo)
{
    int i = 0;
    int j = 0;

    int k, l;

    int id_lido = 0;
    char titulo_lido[101];
    int edicao_lido = 0;
    int preco_adquirido_lido = 0;
    int linha_lido = 0;
    int coluna_lido = 0;

    while (scanf("%d,", &id_lido) == 1)
    {
        InicializaTitulo_lido(titulo_lido);

        LehTitulo(titulo_lido);

        scanf("%d,%d,%d,%d\n", &edicao_lido, &preco_adquirido_lido, &linha_lido, &coluna_lido);

        if (Verifica_id(sebo, id_lido) == 0)
        {
            if (VerificaLinhaColuna(sebo, linha_lido, coluna_lido) == 0)
            {
                while (1)
                {
                    if (sebo.revista[i].id == 0)
                    {
                        break;
                    }

                    i++;
                }

                sebo.revista[i].id = id_lido;

                for (k = 0; k < 101; k++)
                {
                    if (titulo_lido[k] != '\0')
                    {
                        sebo.revista[i].titulo[k] = titulo_lido[k];
                    }

                    else
                    {
                        sebo.revista[i].titulo[k] = '\0';
                        break;
                    }
                }

                sebo.revista[i].edicao = edicao_lido;

                sebo.revista[i].preco_adquirido = preco_adquirido_lido;

                sebo.revista[i].linha = linha_lido;

                sebo.revista[i].coluna = coluna_lido;

                sebo.prateleira[linha_lido - 1][coluna_lido - 1] = id_lido;

                printf("Cadastro %03d ok\n", sebo.revista[i].id);

                if (sebo.revista[i].preco_adquirido > 0)
                {
                    sebo.aquisicaoValor += (sebo.revista[i].preco_adquirido);
                    sebo.aquisicaoQuantidade++;
                }
            }

            else
            {
                printf("Cadastro %03d invalido\n", id_lido);
            }
        }

        else
        {
            printf("Cadastro %03d invalido\n", id_lido);
        }

        i = 0;
    }

    return sebo;
}

void ConsultarAcervoSebo(tSebo sebo)
{
    int i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 15; j++)
        {
            if (sebo.prateleira[i][j] == 0)
            {
                printf("--- ");
            }

            else
            {
                printf("%03d ", sebo.prateleira[i][j]);
            }
        }

        printf("\n");
    }
}

tSebo VenderRevistasSebo(tSebo sebo)
{
    int linha_lido = 0;
    int coluna_lido = 0;
    int valorVenda = 0;
    int id_lido = 0;
    int i = 0;
    int j = 0;

    while (scanf("%d,", &linha_lido) == 1)
    {
        scanf("%d,%d\n", &coluna_lido, &valorVenda);

        if (sebo.prateleira[linha_lido - 1][coluna_lido - 1] > 0)
        {
            if (linha_lido >= 1 && linha_lido <= 10 && coluna_lido >= 1 && coluna_lido <= 15)
            {
                for (i = 0; i < 150; i++)
                {
                    if (sebo.revista[i].id == sebo.prateleira[linha_lido - 1][coluna_lido - 1])
                    {
                        sebo.prateleira[linha_lido - 1][coluna_lido - 1] = 0;

                        printf("%03d - ", sebo.revista[i].id);

                        for (j = 0; j < 101; j++)
                        {
                            if (sebo.revista[i].titulo[j] == '\0')
                            {
                                break;
                            }

                            printf("%c", sebo.revista[i].titulo[j]);
                        }

                        printf(" #%d vendida\n", sebo.revista[i].edicao);

                        sebo.revista[i].id = 0;

                        for (j = 0; j < 101; j++)
                        {
                            sebo.revista[i].titulo[j] = '0';
                        }

                        if (valorVenda > 0)
                        {
                            sebo.vendaValor += valorVenda;
                            sebo.vendaQuantidade++;
                        }

                        sebo.revista[i].edicao = 0;

                        sebo.revista[i].preco_adquirido = 0;

                        sebo.revista[i].linha = 0;

                        sebo.revista[i].coluna = 0;

                        break;
                    }
                }
            }

            else
            {
                printf("Venda invalida\n");
            }
        }

        else
        {
            printf("Venda invalida\n");
        }
    }

    return sebo;
}

void ConsultarCaixaSebo(tSebo sebo)
{
    int valor = 0;
    int saldo = 0;
    int saldo_antesVirgula = 0;
    int saldo_depoisVirgula = 0;

    int aquisicao_antesVirgula = 0;
    int aquisicao_depoisVirgula = 0;

    int venda_antesVirgula = 0;
    int venda_depoisVirgula = 0;

    saldo = sebo.vendaValor - sebo.aquisicaoValor;

    saldo_antesVirgula = saldo / 100;
    saldo -= saldo_antesVirgula * 100;
    saldo_depoisVirgula = saldo;

    valor = sebo.aquisicaoValor;
    aquisicao_antesVirgula = valor / 100;
    valor -= aquisicao_antesVirgula * 100;
    aquisicao_depoisVirgula = valor;

    valor = sebo.vendaValor;
    venda_antesVirgula = valor / 100;
    valor -= venda_antesVirgula * 100;
    venda_depoisVirgula = valor;

    printf("%d aquisicoes: %d,%02d reais\n", sebo.aquisicaoQuantidade, aquisicao_antesVirgula, aquisicao_depoisVirgula);

    printf("%d vendas: %d,%02d reais\n", sebo.vendaQuantidade, venda_antesVirgula, venda_depoisVirgula);

    if (saldo_antesVirgula > 0 || saldo_depoisVirgula > 0)
    {
        printf("Caixa atual: %d,%02d reais de lucro\n", saldo_antesVirgula, saldo_depoisVirgula);
    }

    else if (saldo_antesVirgula < 0 || saldo_depoisVirgula < 0)
    {
        saldo_antesVirgula *= -1;
        saldo_depoisVirgula *= -1;

        printf("Caixa atual: %d,%02d reais de prejuizo\n", saldo_antesVirgula, saldo_depoisVirgula);
    }

    else
    {
        printf("Caixa atual: %d,%02d reais\n", saldo_antesVirgula, saldo_depoisVirgula);
    }
}

void InicializaTitulo_lido(char titulo_lido[101])
{
    int i;

    for (i = 0; i < 101; i++)
    {
        titulo_lido[i] = '\0';
    }
}

void LehTitulo(char titulo_lido[101])
{
    int i = 0;
    char caracter;

    while (scanf("%c", &caracter) == 1)
    {
        if (caracter == ',')
        {
            titulo_lido[i] = '\0';
            break;
        }

        else
        {
            titulo_lido[i] = caracter;
            i++;
        }
    }
}

int Verifica_id(tSebo sebo, int id_lido)
{
    int i;

    for (i = 0; i < 150; i++)
    {
        if (sebo.revista[i].id == 0)
        {
            break;
        }

        else
        {
            if (sebo.revista[i].id == id_lido)
            {
                return 1;
            }
        }
    }

    return 0;
}

int VerificaLinhaColuna(tSebo sebo, int linha_lido, int coluna_lido)
{
    if ((linha_lido < 1 || linha_lido > 10) || (coluna_lido < 1 || coluna_lido > 15))
    {
        return 1;
    }

    else if (sebo.prateleira[linha_lido - 1][coluna_lido - 1] > 0)
    {
        return 1;
    }

    return 0;
}