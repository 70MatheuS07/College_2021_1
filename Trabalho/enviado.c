#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char nome[11];
    int identidade;
    int orientacao;
    char coordenada_i;
    int coordenada_j;

} tNavio;

int VerificaDiretorio(int argc, char *argv[], char diretorio[1001]);

void VerificaTabuleiros(int vetorValidadeTabuleiros[2], char coordenada_i_tabuleiro1[30][2], char coordenada_i_tabuleiro2[30][2], int coordenada_j_tabuleiro1[30], int coordenada_j_tabuleiro2[30], int identidadesTabuleiro1[30], int identidadesTabuleiro2[30], char diretorio[1001]);

void Inicializacao(char matriz[200][100], char diretorio[1001], char jogador1[17], char jogador2[17]);

void InicializaTabuleiros(int tabuleiro1[12][12], int tabuleiro2[12][12]);

void InicializaNavioTabuleiros(char naviosTabuleiro1[20][11], char naviosTabuleiro2[20][11]);

void ColocaNaviosNoMar(int vetorValidadeTabuleiros[2], char coordenada_i_tabuleiro1[30][2], char coordenada_i_tabuleiro2[30][2], int coordenada_j_tabuleiro1[30], int coordenada_j_tabuleiro2[30], char diretorio[1001], int tabuleiro1[12][12], int tabuleiro2[12][12], int tabuleiro1_identificado[12][12], int tabuleiro2_identificado[12][12]);

void InicializaTabuleirosIdentificados(int tabuleiro1_identificado[12][12], int tabuleiro2_identificado[12][12]);

void TranscreveTabuleiro1(int tabuleiro1_identificado[12][12], int tabuleiro1[12][12]);

void TranscreveTabuleiro2(int tabuleiro2_identificado[12][12], int tabuleiro2[12][12]);

int VerificaDistanciaNaviosTabuleiro1(int tabuleiro1_identificado[12][12]);

int VerificaDistanciaNaviosTabuleiro2(int tabuleiro2_identificado[12][12]);

void ImprimeValidadeTabuleiros(char diretorio[1001], int validadeTabuleiro1, int validadeTabuleiro2, int qtdNaviosTabuleiro1[5], int qtdNaviosTabuleiro2[5]);

void Cria_arquivo_inicializacao(char diretorio[1001], char jogador1[17], char jogador2[17], int tabuleiro1[12][12], int tabuleiro2[12][12]);

void InicializaJogadas(char jogadas_i[200][2], int jogadas_j[200]);

int Jogo(int identidadesTabuleiro1[30], int identidadesTabuleiro2[30], char matriz[200][100], char jogadas_i[200][2], int jogadas_j[200], char jogador1[17], char jogador2[17], int tabuleiro1[12][12], int tabuleiro2[12][12], int tabuleiro1_identificado[12][12], int tabuleiro2_identificado[12][12], char naviosTabuleiro1[30][11], char naviosTabuleiro2[30][11]);

void InicializaTabuleiros_saida(char tabuleiro1_saida[12][12], char tabuleiro2_saida[12][12]);

int AfundouNavioTabuleiro2(int num2, int tabuleiro2_identificado[12][12]);

int AfundouNavioTabuleiro1(int num1, int tabuleiro1_identificado[12][12]);

int NaoTemNavioTabuleiro2(int tabuleiro2_identificado[12][12]);

int NaoTemNavioTabuleiro1(int tabuleiro1_identificado[12][12]);

void InicializaIdentidades(int identidadesTabuleiro1[30], int identidadesTabuleiro2[30]);

void InicializaCoordenada_i(char coordenada_i_tabuleiro1[30][2], char coordenada_i_tabuleiro2[30][2]);

void InicializaCoordenada_j(int coordenada_j_tabuleiro1[30], int coordenada_j_tabuleiro2[30]);

int VarreCoordenadaInicalTabuleiro1(char coordenada_i_tabuleiro1[30][2], int coordenada_j_tabuleiro1[30]);

int VarreCoordenadaInicalTabuleiro2(char coordenada_i_tabuleiro2[30][2], int coordenada_j_tabuleiro2[30]);

void InicializaMatriz(char matriz[200][100]);

void ClassificaJogadas(char matriz[200][100], char jogadas_i[200][2], int jogadas_j[200]);

void ImprimeJogadaInvalidaJogador1(char matriz[200][100], int p, char jogador1[17]);

void ImprimeJogadaInvalidaJogador2(char matriz[200][100], int p, char jogador2[17]);

void GeraResultado(int numeroDoTiroTabuleiro1[50], int numeroDoTiroTabuleiro2[50], int naviosAcertados_id_Tabuleiro1[50], int naviosAcertados_id_Tabuleiro2[50], char naviosAcertadosTabuleiro1[50][11], char naviosAcertadosTabuleiro2[50][11], int jogadas_j_jogador1[100], int jogadas_j_jogador2[100], char jogadas_i_jogador1[100][2], char jogadas_i_jogador2[100][2], int tirosNavios[4], int venceuJogo, char diretorio[1001], char jogador1[17], char jogador2[17], char jogadas_i[200][2], int jogadas_j[200], char naviosTabuleiro1[30][11], char naviosTabuleiro2[30][11], int identidadesTabuleiro1[30], int identidadesTabuleiro2[30], int tabuleiro1[12][12], int tabuleiro2[12][12]);

void InicializaJogadasJogador1e2(char jogadas_i_jogador1[100][2], char jogadas_i_jogador2[100][2], int jogadas_j_jogador1[100], int jogadas_j_jogador2[100]);

void TransfereJogadasValidas(char jogadas_i_jogador1[100][2], char jogadas_i_jogador2[100][2], int jogadas_j_jogador1[100], int jogadas_j_jogador2[100], char jogadas_i[200][2], int jogadas_j[200]);

int IdentidadeNavioTabuleiro1(char coordenada_i, int coordenada_j, int tabuleiro1[12][12]);

int IdentidadeNavioTabuleiro2(char coordenada_i, int coordenada_j, int tabuleiro2[12][12]);

int AchaNavioCorreto1(int id, int identidadesTabuleiro1[30]);

int AchaNavioCorreto2(int id, int identidadesTabuleiro2[30]);

int QuantidadeLugaresNaviosTabuleiro1(int tabuleiro1[12][12]);

int QuantidadeLugaresNaviosTabuleiro2(int tabuleiro2[12][12]);

void CopiaTabuleiros(int tabuleiro1_copia[12][12], int tabuleiro2_copia[12][12], int tabuleiro1[12][12], int tabuleiro2[12][12]);

void GeraEstatisticas(int numeroDoTiroTabuleiro1[50], int numeroDoTiroTabuleiro2[50], int naviosAcertados_id_Tabuleiro1[50], int naviosAcertados_id_Tabuleiro2[50], char naviosAcertadosTabuleiro1[50][11], char naviosAcertadosTabuleiro2[50][11], int jogadas_j_jogador1[100], int jogadas_j_jogador2[100], char jogadas_i_jogador1[100][2], char jogadas_i_jogador2[100][2], char diretorio[1001], int tirosNavios[4], char jogador1[17], char jogador2[17]);

void CalculaMediaJogador1(float localizacaoMediaTirosJogador1[2], char jogadas_i_jogador1[100][2], int jogadas_j_jogador1[100], int tirosNavios[4]);

void CalculaMediaJogador2(float localizacaoMediaTirosJogador2[2], char jogadas_i_jogador2[100][2], int jogadas_j_jogador2[100], int tirosNavios[4]);

float CalculaDesvioJogador1(float localizacaoMediaTirosJogador1[2], char jogadas_i_jogador1[100][2], int jogadas_j_jogador1[100], int tirosNavios[4]);

float CalculaDesvioJogador2(float localizacaoMediaTirosJogador2[2], char jogadas_i_jogador2[100][2], int jogadas_j_jogador2[100], int tirosNavios[4]);

void InicializaNaviosAcertados(char naviosAcertadosTabuleiro1[50][11], char naviosAcertadosTabuleiro2[50][11]);

void InicializaNaviosAcertadosID(int naviosAcertados_id_Tabuleiro1[50], int naviosAcertados_id_Tabuleiro2[50]);

void OrganizaTabuleiro1(int numeroDosTirosOrganizadosTabuleiro1[50], char nomeDosNaviosOrganizadosTabuleiro1[50][11], int id_DosNaviosOrganizadosTabuleiro1[50], int numeroDoTiroTabuleiro1[50], char naviosAcertadosTabuleiro1[50][11], int naviosAcertados_id_Tabuleiro1[50]);

void OrganizaTabuleiro2(int numeroDosTirosOrganizadosTabuleiro2[50], char nomeDosNaviosOrganizadosTabuleiro2[50][11], int id_DosNaviosOrganizadosTabuleiro2[50], int numeroDoTiroTabuleiro2[50], char naviosAcertadosTabuleiro2[50][11], int naviosAcertados_id_Tabuleiro2[50]);

void InicializaOrganizados(int numeroDosTirosOrganizadosTabuleiro1[50], char nomeDosNaviosOrganizadosTabuleiro1[50][11], int id_DosNaviosOrganizadosTabuleiro1[50], int numeroDosTirosOrganizadosTabuleiro2[50], char nomeDosNaviosOrganizadosTabuleiro2[50][11], int id_DosNaviosOrganizadosTabuleiro2[50]);

void InicializaNumeroDoTiro(int numeroDoTiroTabuleiro1[50], int numeroDoTiroTabuleiro2[50]);

int main(int argc, char *argv[])
{
    char diretorio[1001];

    int tabuleiro1[12][12];
    int tabuleiro2[12][12];

    int tabuleiro1_identificado[12][12];
    int tabuleiro2_identificado[12][12];

    char jogador1[17];
    char jogador2[17];

    char naviosTabuleiro1[30][11];
    char naviosTabuleiro2[30][11];

    char jogadas_i[200][2];
    int jogadas_j[200];

    int identidadesTabuleiro1[30];
    int identidadesTabuleiro2[30];

    char coordenada_i_tabuleiro1[30][2];
    int coordenada_j_tabuleiro1[30];

    char coordenada_i_tabuleiro2[30][2];
    int coordenada_j_tabuleiro2[30];

    char jogadas_i_jogador1[100][2];
    char jogadas_i_jogador2[100][2];

    int jogadas_j_jogador1[100];
    int jogadas_j_jogador2[100];

    int vetorValidadeTabuleiros[2] = {0, 0};

    char matriz[200][100];

    int venceuJogo = -1;

    int tirosNavios[4] = {0, 0, 0, 0};

    char naviosAcertadosTabuleiro1[50][11];
    char naviosAcertadosTabuleiro2[50][11];

    int naviosAcertados_id_Tabuleiro1[50];
    int naviosAcertados_id_Tabuleiro2[50];

    int numeroDoTiroTabuleiro1[50];
    int numeroDoTiroTabuleiro2[50];

    if (VerificaDiretorio(argc, argv, diretorio) == 1)
    {
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado.\n");

        exit(1);
    }

    // Zero todas as matrizes e vetores que vou utilizar ao longo do código

    InicializaTabuleiros(tabuleiro1, tabuleiro2);

    InicializaNavioTabuleiros(naviosTabuleiro1, naviosTabuleiro2);

    InicializaJogadas(jogadas_i, jogadas_j);

    InicializaJogadasJogador1e2(jogadas_i_jogador1, jogadas_i_jogador2, jogadas_j_jogador1, jogadas_j_jogador2);

    InicializaIdentidades(identidadesTabuleiro1, identidadesTabuleiro2);

    InicializaNaviosAcertados(naviosAcertadosTabuleiro1, naviosAcertadosTabuleiro2);

    InicializaCoordenada_i(coordenada_i_tabuleiro1, coordenada_i_tabuleiro2);

    InicializaMatriz(matriz);

    InicializaNumeroDoTiro(numeroDoTiroTabuleiro1, numeroDoTiroTabuleiro2);

    VerificaTabuleiros(vetorValidadeTabuleiros, coordenada_i_tabuleiro1, coordenada_i_tabuleiro2, coordenada_j_tabuleiro1, coordenada_j_tabuleiro2, identidadesTabuleiro1, identidadesTabuleiro2, diretorio);

    Inicializacao(matriz, diretorio, jogador1, jogador2);

    ClassificaJogadas(matriz, jogadas_i, jogadas_j);

    ColocaNaviosNoMar(vetorValidadeTabuleiros, coordenada_i_tabuleiro1, coordenada_i_tabuleiro2, coordenada_j_tabuleiro1, coordenada_j_tabuleiro2, diretorio, tabuleiro1, tabuleiro2, tabuleiro1_identificado, tabuleiro2_identificado);

    Cria_arquivo_inicializacao(diretorio, jogador1, jogador2, tabuleiro1, tabuleiro2);

    venceuJogo = Jogo(identidadesTabuleiro1, identidadesTabuleiro2, matriz, jogadas_i, jogadas_j, jogador1, jogador2, tabuleiro1, tabuleiro2, tabuleiro1_identificado, tabuleiro2_identificado, naviosTabuleiro1, naviosTabuleiro2);

    GeraResultado(numeroDoTiroTabuleiro1, numeroDoTiroTabuleiro2, naviosAcertados_id_Tabuleiro1, naviosAcertados_id_Tabuleiro2, naviosAcertadosTabuleiro1, naviosAcertadosTabuleiro2, jogadas_j_jogador1, jogadas_j_jogador2, jogadas_i_jogador1, jogadas_i_jogador2, tirosNavios, venceuJogo, diretorio, jogador1, jogador2, jogadas_i, jogadas_j, naviosTabuleiro1, naviosTabuleiro2, identidadesTabuleiro1, identidadesTabuleiro2, tabuleiro1, tabuleiro2);

    GeraEstatisticas(numeroDoTiroTabuleiro1, numeroDoTiroTabuleiro2, naviosAcertados_id_Tabuleiro1, naviosAcertados_id_Tabuleiro2, naviosAcertadosTabuleiro1, naviosAcertadosTabuleiro2, jogadas_j_jogador1, jogadas_j_jogador2, jogadas_i_jogador1, jogadas_i_jogador2, diretorio, tirosNavios, jogador1, jogador2);

    return 0;
}

int VerificaDiretorio(int argc, char *argv[], char diretorio[1001])
{
    if (argc <= 1)
    {
        return 1;
    }

    strcpy(diretorio, argv[1]);

    return 0;
}

void InicializaTabuleiros(int tabuleiro1[12][12], int tabuleiro2[12][12])
{
    int i, j;

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (i == 0 || i == 11)
            {
                tabuleiro1[i][j] = -2;
            }

            else if (j == 0 || j == 11)
            {
                tabuleiro1[i][j] = -2;
            }

            else
            {
                tabuleiro1[i][j] = -1;
            }
        }
    }

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (i == 0 || i == 11)
            {
                tabuleiro2[i][j] = -2;
            }

            else if (j == 0 || j == 11)
            {
                tabuleiro2[i][j] = -2;
            }

            else
            {
                tabuleiro2[i][j] = -1;
            }
        }
    }
}

void InicializaNavioTabuleiros(char naviosTabuleiro1[20][11], char naviosTabuleiro2[20][11])
{
    int i, j;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 11; j++)
        {
            naviosTabuleiro1[i][j] = '0';
            naviosTabuleiro2[i][j] = '0';
        }
    }
}

void InicializaJogadas(char jogadas_i[200][2], int jogadas_j[200])
{
    int i, j;

    for (i = 0; i < 200; i++)
    {
        jogadas_i[i][0] = '0';
        jogadas_i[i][1] = '0';

        jogadas_j[i] = 0;
    }
}

void InicializaJogadasJogador1e2(char jogadas_i_jogador1[100][2], char jogadas_i_jogador2[100][2], int jogadas_j_jogador1[100], int jogadas_j_jogador2[100])
{
    int i;

    for (i = 0; i < 100; i++)
    {
        jogadas_i_jogador1[i][0] = '0';
        jogadas_i_jogador2[i][0] = '0';
        jogadas_i_jogador1[i][1] = '0';
        jogadas_i_jogador2[i][1] = '0';

        jogadas_j_jogador1[i] = 0;
        jogadas_j_jogador2[i] = 0;
    }
}

void InicializaIdentidades(int identidadesTabuleiro1[30], int identidadesTabuleiro2[30])
{
    int i;

    for (i = 0; i < 30; i++)
    {
        identidadesTabuleiro1[i] = 0;
        identidadesTabuleiro2[i] = 0;
    }
}

void InicializaNaviosAcertados(char naviosAcertadosTabuleiro1[50][11], char naviosAcertadosTabuleiro2[50][11])
{
    int i, j;

    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 11; j++)
        {
            naviosAcertadosTabuleiro1[i][j] = '0';
            naviosAcertadosTabuleiro2[i][j] = '0';
        }
    }
}

void InicializaCoordenada_i(char coordenada_i_tabuleiro1[30][2], char coordenada_i_tabuleiro2[30][2])
{
    int i;

    for (i = 0; i < 30; i++)
    {
        coordenada_i_tabuleiro1[i][0] = '0';
        coordenada_i_tabuleiro1[i][1] = '0';

        coordenada_i_tabuleiro2[i][0] = '0';
        coordenada_i_tabuleiro2[i][1] = '0';
    }
}

void InicializaCoordenada_j(int coordenada_j_tabuleiro1[30], int coordenada_j_tabuleiro2[30])
{
    int i;

    for (i = 0; i < 30; i++)
    {
        coordenada_j_tabuleiro1[i] = 0;

        coordenada_j_tabuleiro2[i] = 0;
    }
}

void InicializaMatriz(char matriz[200][100])
{
    int i, j;

    for (i = 0; i < 200; i++)
    {
        for (j = 0; j < 100; j++)
        {
            matriz[i][j] = '*';
        }
    }
}

void InicializaNumeroDoTiro(int numeroDoTiroTabuleiro1[50], int numeroDoTiroTabuleiro2[50])
{
    int i;

    for (i = 0; i < 50; i++)
    {
        numeroDoTiroTabuleiro1[i] = 0;
        numeroDoTiroTabuleiro2[i] = 0;
    }
}

void VerificaTabuleiros(int vetorValidadeTabuleiros[2], char coordenada_i_tabuleiro1[30][2], char coordenada_i_tabuleiro2[30][2], int coordenada_j_tabuleiro1[30], int coordenada_j_tabuleiro2[30], int identidadesTabuleiro1[30], int identidadesTabuleiro2[30], char diretorio[1001])
{
    char caracter;
    char diretorioConcatenado[1012];

    int i = 0;
    int cont_navio = 0;
    int cont = 0;
    int u = 0;

    tNavio navio;

    strcpy(diretorioConcatenado, diretorio);

    strcat(diretorioConcatenado, "/tabu_1.txt");

    FILE *tabuleiro;

    tabuleiro = fopen(diretorioConcatenado, "r");

    if (tabuleiro == NULL)
    {
        printf("Arquivo não encontrado, verifique o diretorio\n");
        exit(1);
    }

    do
    {

        while (fscanf(tabuleiro, "%c", &caracter) != '\0')
        {
            if (caracter == ';')
            {
                navio.nome[i] = '\0';
                break;
            }
            else
            {
                navio.nome[i] = caracter;
                i++;
            }
        }

        fscanf(tabuleiro, "%d;%d;%c%d\n", &navio.identidade, &navio.orientacao, &navio.coordenada_i, &navio.coordenada_j);

        if (navio.nome[0] != 'C' || navio.nome[1] != 'a' || navio.nome[2] != 'r' || navio.nome[3] != 'r' || navio.nome[4] != 'i' || navio.nome[5] != 'e' || navio.nome[6] != 'r' || navio.nome[7] != '\0')
        {
            if (navio.nome[0] != 'C' || navio.nome[1] != 'r' || navio.nome[2] != 'u' || navio.nome[3] != 'i' || navio.nome[4] != 's' || navio.nome[5] != 'e' || navio.nome[6] != 'r' || navio.nome[7] != '\0')
            {
                if (navio.nome[0] != 'D' || navio.nome[1] != 'e' || navio.nome[2] != 's' || navio.nome[3] != 't' || navio.nome[4] != 'r' || navio.nome[5] != 'o' || navio.nome[6] != 'y' || navio.nome[7] != 'e' || navio.nome[8] != 'r' || navio.nome[9] != '\0')
                {
                    if (navio.nome[0] != 'S' || navio.nome[1] != 'u' || navio.nome[2] != 'b' || navio.nome[3] != 'm' || navio.nome[4] != 'a' || navio.nome[5] != 'r' || navio.nome[6] != 'i' || navio.nome[7] != 'n' || navio.nome[8] != 'e' || navio.nome[9] != '\0')
                    {
                        if (navio.nome[0] != 'B' || navio.nome[1] != 'a' || navio.nome[2] != 't' || navio.nome[3] != 't' || navio.nome[4] != 'l' || navio.nome[5] != 'e' || navio.nome[6] != 's' || navio.nome[7] != 'h' || navio.nome[8] != 'i' || navio.nome[9] != 'p' || navio.nome[10] != '\0')
                        {
                            vetorValidadeTabuleiros[0]++;
                        }
                    }
                }
            }
        }

        if (navio.orientacao < 0 || navio.orientacao >= 2)
        {
            vetorValidadeTabuleiros[0]++;
        }

        if (navio.coordenada_i < 'a' || navio.coordenada_i > 'j')
        {
            vetorValidadeTabuleiros[0]++;
        }

        if (navio.coordenada_j < 1 || navio.coordenada_j > 10)
        {
            vetorValidadeTabuleiros[0]++;
        }

        for (cont_navio = 0; cont_navio < i; cont_navio++)
        {
            if (cont_navio == i - 1)
            {
                naviosTabuleiro1[u][cont_navio] = '\0';
            }

            naviosTabuleiro1[u][cont_navio] = navio.nome[cont_navio];
        }

        for (cont_navio = 0; cont_navio < i; i--)
        {
            navio.nome[i] = '\0';
        }

        identidadesTabuleiro1[u] = navio.identidade;

        coordenada_i_tabuleiro1[u][0] = navio.coordenada_i;
        coordenada_i_tabuleiro1[u][1] = '\0';

        coordenada_j_tabuleiro1[u] = navio.coordenada_j;

        u++;

    } while (!feof(tabuleiro));

    fclose(tabuleiro);

    strcpy(diretorioConcatenado, diretorio);

    strcat(diretorioConcatenado, "/tabu_2.txt");

    tabuleiro = fopen(diretorioConcatenado, "r");

    if (tabuleiro == NULL)
    {
        printf("Arquivo não encontrado, verifique o diretorio\n");
        exit(1);
    }

    u = 0;

    do
    {
        while (fscanf(tabuleiro, "%c", &caracter) != '\0')
        {
            if (caracter == ';')
            {
                navio.nome[i] = '\0';
                break;
            }
            else
            {
                navio.nome[i] = caracter;
                i++;
            }
        }

        fscanf(tabuleiro, "%d;%d;%c%d\n", &navio.identidade, &navio.orientacao, &navio.coordenada_i, &navio.coordenada_j);

        if (navio.nome[0] != 'C' || navio.nome[1] != 'a' || navio.nome[2] != 'r' || navio.nome[3] != 'r' || navio.nome[4] != 'i' || navio.nome[5] != 'e' || navio.nome[6] != 'r' || navio.nome[7] != '\0')
        {
            if (navio.nome[0] != 'C' || navio.nome[1] != 'r' || navio.nome[2] != 'u' || navio.nome[3] != 'i' || navio.nome[4] != 's' || navio.nome[5] != 'e' || navio.nome[6] != 'r' || navio.nome[7] != '\0')
            {
                if (navio.nome[0] != 'D' || navio.nome[1] != 'e' || navio.nome[2] != 's' || navio.nome[3] != 't' || navio.nome[4] != 'r' || navio.nome[5] != 'o' || navio.nome[6] != 'y' || navio.nome[7] != 'e' || navio.nome[8] != 'r' || navio.nome[9] != '\0')
                {
                    if (navio.nome[0] != 'S' || navio.nome[1] != 'u' || navio.nome[2] != 'b' || navio.nome[3] != 'm' || navio.nome[4] != 'a' || navio.nome[5] != 'r' || navio.nome[6] != 'i' || navio.nome[7] != 'n' || navio.nome[8] != 'e' || navio.nome[9] != '\0')
                    {
                        if (navio.nome[0] != 'B' || navio.nome[1] != 'a' || navio.nome[2] != 't' || navio.nome[3] != 't' || navio.nome[4] != 'l' || navio.nome[5] != 'e' || navio.nome[6] != 's' || navio.nome[7] != 'h' || navio.nome[8] != 'i' || navio.nome[9] != 'p' || navio.nome[10] != '\0')
                        {
                            vetorValidadeTabuleiros[1] += 1;
                        }
                    }
                }
            }
        }

        if (navio.orientacao < 0 || navio.orientacao >= 2)
        {
            vetorValidadeTabuleiros[1] += 1;
        }

        if (navio.coordenada_i < 'a' || navio.coordenada_i > 'j')
        {
            vetorValidadeTabuleiros[1] += 1;
        }

        if (navio.coordenada_j < 1 || navio.coordenada_j > 10)
        {
            vetorValidadeTabuleiros[1]++;
        }

        for (cont_navio = 0; cont_navio < i; cont_navio++)
        {
            if (cont_navio == i - 1)
            {
                naviosTabuleiro2[u][cont_navio] = '\0';
            }

            naviosTabuleiro2[u][cont_navio] = navio.nome[cont_navio];
        }

        for (cont_navio = 0; cont_navio < i; i--)
        {
            navio.nome[i] = '\0';
        }

        identidadesTabuleiro2[u] = navio.identidade;

        coordenada_i_tabuleiro2[u][0] = navio.coordenada_i;
        coordenada_i_tabuleiro2[u][1] = '\0';

        coordenada_j_tabuleiro2[u] = navio.coordenada_j;

        u++;

    } while (!feof(tabuleiro));

    fclose(tabuleiro);
}

void Inicializacao(char matriz[200][100], char diretorio[1001], char jogador1[17], char jogador2[17])
{
    int i = 0;
    int j = 0;

    char caracter;
    int num;

    char diretorioConcatenado[1014];

    strcpy(diretorioConcatenado, diretorio);

    strcat(diretorioConcatenado, "/jogadas.txt");

    FILE *inicializacao;

    inicializacao = fopen(diretorioConcatenado, "r");

    fscanf(inicializacao, "%s\n", jogador1);

    fscanf(inicializacao, "%s\n", jogador2);

    if (strlen(jogador1) > 16)
    {
        printf("Nome do primeiro jogador invalido.\n");
        exit(1);
    }

    else if (strlen(jogador2) > 16)
    {
        printf("Nome do segundo jogador invalido.\n");
        exit(1);
    }

    while (!feof(inicializacao))
    {
        while (fscanf(inicializacao, "%c", &caracter) == 1)
        {
            if (caracter == '\n')
            {
                i++;
                j = 0;
            }
            else
            {
                matriz[i][j] = caracter;
                j++;
            }
        }
    }

    fclose(inicializacao);
}

void ClassificaJogadas(char matriz[200][100], char jogadas_i[200][2], int jogadas_j[200])
{
    int i, j;

    for (i = 0; i < 200; i++)
    {
        for (j = 0; matriz[i][j] != '*'; j++)
        {
            if (matriz[i][0] < 'a' || matriz[i][0] > 'j')
            {
                jogadas_i[i][0] = 'z';
                jogadas_i[i][1] = '\0';

                jogadas_j[i] = 0;

                break;
            }

            else if (matriz[i][1] < '1' || matriz[i][1] > '9')
            {
                jogadas_i[i][0] = 'z';
                jogadas_i[i][1] = '\0';

                jogadas_j[i] = 0;

                break;
            }

            else
            {
                jogadas_i[i][0] = matriz[i][0];

                if (matriz[i][1] == '1')
                {
                    if (matriz[i][2] == '0')
                    {
                        if (matriz[i][3] != '*')
                        {
                            jogadas_i[i][0] = 'z';
                            jogadas_i[i][1] = '\0';

                            jogadas_j[i] = 0;

                            break;
                        }
                        else
                        {
                            jogadas_j[i] = 10;
                        }
                    }
                    else
                    {
                        if (matriz[i][2] != '*')
                        {
                            jogadas_i[i][0] = 'z';
                            jogadas_i[i][1] = '\0';

                            jogadas_j[i] = 0;

                            break;
                        }
                        else
                        {
                            jogadas_j[i] = 1;
                        }
                    }
                }

                else
                {
                    if (matriz[i][2] != '*')
                    {
                        jogadas_i[i][0] = 'z';
                        jogadas_i[i][1] = '\0';

                        jogadas_j[i] = 0;

                        break;
                    }
                    else
                    {
                        jogadas_j[i] = matriz[i][1] - 48;
                    }
                }

                break;
            }
        }
    }
}

void ColocaNaviosNoMar(int vetorValidadeTabuleiros[2], char coordenada_i_tabuleiro1[30][2], char coordenada_i_tabuleiro2[30][2], int coordenada_j_tabuleiro1[30], int coordenada_j_tabuleiro2[30], char diretorio[1001], int tabuleiro1[12][12], int tabuleiro2[12][12], int tabuleiro1_identificado[12][12], int tabuleiro2_identificado[12][12])
{
    char caracter;
    char diretorioConcatenado[1012];

    int i = 0;
    int j = 0;
    int cont_navio = 0;
    int cont = 0;
    int k = 1;
    int l = 1;

    char Carrier[8] = {'C', 'a', 'r', 'r', 'i', 'e', 'r'};
    char Cruiser[8] = {'C', 'r', 'u', 'i', 's', 'e', 'r'};
    char Destroyer[10] = {'D', 'e', 's', 't', 'r', 'o', 'y', 'e', 'r'};
    char Submarine[10] = {'S', 'u', 'b', 'm', 'a', 'r', 'i', 'n', 'e'};
    char Battleship[11] = {'B', 'a', 't', 't', 'l', 'e', 's', 'h', 'i', 'p'};

    int Carrier_tam = 5;
    int Cruiser_tam = 3;
    int Destroyer_tam = 2;
    int Submarine_tam = 3;
    int Battleship_tam = 4;

    int validadeTabuleiro1 = 0;
    int validadeTabuleiro2 = 0;

    int qtdNaviosTabuleiro1[5] = {0, 0, 0, 0, 0};
    int qtdNaviosTabuleiro2[5] = {0, 0, 0, 0, 0};

    tNavio navio;

    InicializaTabuleirosIdentificados(tabuleiro1_identificado, tabuleiro2_identificado);

    strcpy(diretorioConcatenado, diretorio);

    strcat(diretorioConcatenado, "/tabu_1.txt");

    FILE *tabuleiro_1;

    tabuleiro_1 = fopen(diretorioConcatenado, "r");

    do
    {
        i = 0;

        while (fscanf(tabuleiro_1, "%c", &caracter) != '\0')
        {
            if (caracter == ';')
            {
                navio.nome[i] = '\0';
                break;
            }
            else
            {
                navio.nome[i] = caracter;
                i++;
            }
        }

        fscanf(tabuleiro_1, "%d;%d;%c%d\n", &navio.identidade, &navio.orientacao, &navio.coordenada_i, &navio.coordenada_j);

        if (strcmp(navio.nome, Carrier) == 0)
        {
            qtdNaviosTabuleiro1[0]++;

            if (navio.orientacao == 1)
            {

                for (j = 0; j < Carrier_tam; j++)
                {
                    tabuleiro1[navio.coordenada_i - 96][navio.coordenada_j + j] = navio.identidade;
                }
            }
            else
            {
                for (i = 0; i < Carrier_tam; i++)
                {
                    tabuleiro1[navio.coordenada_i - 96 + i][navio.coordenada_j] = navio.identidade;
                }
            }

            if (navio.coordenada_j > 6 && navio.orientacao == 1)
            {
                validadeTabuleiro1++;
            }

            if (navio.coordenada_i > 'f' && navio.orientacao == 0)
            {
                validadeTabuleiro1++;
            }
        }

        else if (strcmp(navio.nome, Battleship) == 0)
        {
            qtdNaviosTabuleiro1[1]++;

            if (navio.orientacao == 1)
            {
                for (j = 0; j < Battleship_tam; j++)
                {
                    tabuleiro1[navio.coordenada_i - 96][navio.coordenada_j + j] = navio.identidade;
                }
            }
            else
            {
                for (i = 0; i < Battleship_tam; i++)
                {
                    tabuleiro1[navio.coordenada_i - 96 + i][navio.coordenada_j] = navio.identidade;
                }
            }

            if (navio.coordenada_j > 7 && navio.orientacao == 1)
            {
                validadeTabuleiro1++;
            }

            if (navio.coordenada_i > 'g' && navio.orientacao == 0)
            {
                validadeTabuleiro1++;
            }
        }

        else if (strcmp(navio.nome, Cruiser) == 0)
        {
            qtdNaviosTabuleiro1[2]++;

            if (navio.orientacao == 1)
            {
                for (j = 0; j < Cruiser_tam; j++)
                {
                    tabuleiro1[navio.coordenada_i - 96][navio.coordenada_j + j] = navio.identidade;
                }
            }
            else
            {
                for (i = 0; i < Cruiser_tam; i++)
                {
                    tabuleiro1[navio.coordenada_i - 96 + i][navio.coordenada_j] = navio.identidade;
                }
            }

            if (navio.coordenada_j > 8 && navio.orientacao == 1)
            {
                validadeTabuleiro1++;
            }

            if (navio.coordenada_i > 'h' && navio.orientacao == 0)
            {
                validadeTabuleiro1++;
            }
        }

        else if (strcmp(navio.nome, Submarine) == 0)
        {
            qtdNaviosTabuleiro1[3]++;

            if (navio.orientacao == 1)
            {
                for (j = 0; j < Submarine_tam; j++)
                {
                    tabuleiro1[navio.coordenada_i - 96][navio.coordenada_j + j] = navio.identidade;
                }
            }
            else
            {
                for (i = 0; i < Submarine_tam; i++)
                {
                    tabuleiro1[navio.coordenada_i - 96 + i][navio.coordenada_j] = navio.identidade;
                }
            }

            if (navio.coordenada_j > 8 && navio.orientacao == 1)
            {
                validadeTabuleiro1++;
            }

            if (navio.coordenada_i > 'h' && navio.orientacao == 0)
            {
                validadeTabuleiro1++;
            }
        }

        else if (strcmp(navio.nome, Destroyer) == 0)
        {
            qtdNaviosTabuleiro1[4]++;

            if (navio.orientacao == 1)
            {
                for (j = 0; j < Destroyer_tam; j++)
                {
                    tabuleiro1[navio.coordenada_i - 96][navio.coordenada_j + j] = navio.identidade;
                }
            }
            else
            {
                for (i = 0; i < Destroyer_tam; i++)
                {
                    tabuleiro1[navio.coordenada_i - 96 + i][navio.coordenada_j] = navio.identidade;
                }
            }

            if (navio.coordenada_j > 9 && navio.orientacao == 1)
            {
                validadeTabuleiro1++;
            }

            if (navio.coordenada_i > 'i' && navio.orientacao == 0)
            {
                validadeTabuleiro1++;
            }
        }

    } while (!feof(tabuleiro_1));

    fclose(tabuleiro_1);

    strcpy(diretorioConcatenado, diretorio);

    strcat(diretorioConcatenado, "/tabu_2.txt");

    FILE *tabuleiro_2;

    tabuleiro_2 = fopen(diretorioConcatenado, "r");

    do
    {
        i = 0;

        while (fscanf(tabuleiro_2, "%c", &caracter) != '\0')
        {
            if (caracter == ';')
            {
                navio.nome[i] = '\0';
                break;
            }
            else
            {
                navio.nome[i] = caracter;
                i++;
            }
        }

        fscanf(tabuleiro_2, "%d;%d;%c%d\n", &navio.identidade, &navio.orientacao, &navio.coordenada_i, &navio.coordenada_j);

        if (strcmp(navio.nome, Carrier) == 0)
        {
            qtdNaviosTabuleiro2[0]++;

            if (navio.orientacao == 1)
            {

                for (j = 0; j < Carrier_tam; j++)
                {
                    tabuleiro2[navio.coordenada_i - 96][navio.coordenada_j + j] = navio.identidade;
                }
            }
            else
            {
                for (i = 0; i < Carrier_tam; i++)
                {
                    tabuleiro2[navio.coordenada_i - 96 + i][navio.coordenada_j] = navio.identidade;
                }
            }
        }

        else if (strcmp(navio.nome, Battleship) == 0)
        {
            qtdNaviosTabuleiro2[1]++;

            if (navio.orientacao == 1)
            {
                for (j = 0; j < Battleship_tam; j++)
                {
                    tabuleiro2[navio.coordenada_i - 96][navio.coordenada_j + j] = navio.identidade;
                }
            }
            else
            {
                for (i = 0; i < Battleship_tam; i++)
                {
                    tabuleiro2[navio.coordenada_i - 96 + i][navio.coordenada_j] = navio.identidade;
                }
            }
        }

        else if (strcmp(navio.nome, Cruiser) == 0)
        {
            qtdNaviosTabuleiro2[2]++;

            if (navio.orientacao == 1)
            {
                for (j = 0; j < Cruiser_tam; j++)
                {
                    tabuleiro2[navio.coordenada_i - 96][navio.coordenada_j + j] = navio.identidade;
                }
            }
            else
            {
                for (i = 0; i < Cruiser_tam; i++)
                {
                    tabuleiro2[navio.coordenada_i - 96 + i][navio.coordenada_j] = navio.identidade;
                }
            }
        }

        else if (strcmp(navio.nome, Submarine) == 0)
        {
            qtdNaviosTabuleiro2[3]++;

            if (navio.orientacao == 1)
            {
                for (j = 0; j < Submarine_tam; j++)
                {
                    tabuleiro2[navio.coordenada_i - 96][navio.coordenada_j + j] = navio.identidade;
                }
            }
            else
            {
                for (i = 0; i < Submarine_tam; i++)
                {
                    tabuleiro2[navio.coordenada_i - 96 + i][navio.coordenada_j] = navio.identidade;
                }
            }
        }

        else if (strcmp(navio.nome, Destroyer) == 0)
        {
            qtdNaviosTabuleiro2[4]++;

            if (navio.orientacao == 1)
            {
                for (j = 0; j < Destroyer_tam; j++)
                {
                    tabuleiro2[navio.coordenada_i - 96][navio.coordenada_j + j] = navio.identidade;
                }
            }
            else
            {
                for (i = 0; i < Destroyer_tam; i++)
                {
                    tabuleiro2[navio.coordenada_i - 96 + i][navio.coordenada_j] = navio.identidade;
                }
            }
        }

    } while (!feof(tabuleiro_2));

    fclose(tabuleiro_2);

    // Faço uma copia identica para evitar mudar os tabuleiros principais

    TranscreveTabuleiro1(tabuleiro1_identificado, tabuleiro1);
    TranscreveTabuleiro2(tabuleiro2_identificado, tabuleiro2);

    validadeTabuleiro1 += vetorValidadeTabuleiros[0];
    validadeTabuleiro2 += vetorValidadeTabuleiros[1];

    validadeTabuleiro1 += VerificaDistanciaNaviosTabuleiro1(tabuleiro1_identificado);
    validadeTabuleiro2 += VerificaDistanciaNaviosTabuleiro2(tabuleiro2_identificado);

    validadeTabuleiro1 += VarreCoordenadaInicalTabuleiro1(coordenada_i_tabuleiro1, coordenada_j_tabuleiro1);
    validadeTabuleiro2 += VarreCoordenadaInicalTabuleiro2(coordenada_i_tabuleiro2, coordenada_j_tabuleiro2);

    ImprimeValidadeTabuleiros(diretorio, validadeTabuleiro1, validadeTabuleiro2, qtdNaviosTabuleiro1, qtdNaviosTabuleiro2);

    printf("Nome do Jogador 1:\n");
    printf("Nome do Jogador 2:\n\n");
}

void Cria_arquivo_inicializacao(char diretorio[1001], char jogador1[17], char jogador2[17], int tabuleiro1[12][12], int tabuleiro2[12][12])
{
    int i, j;
    char diretorioConcatenado[1014];

    strcpy(diretorioConcatenado, diretorio);

    strcat(diretorioConcatenado, "/saida/inicializacao.txt");

    FILE *inicializacao;

    inicializacao = fopen(diretorioConcatenado, "a+");

    fprintf(inicializacao, "%s\n", jogador1);

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro1[i][j] > 0)
            {
                fprintf(inicializacao, "X");
            }
            else
            {
                fprintf(inicializacao, "o");
            }

            if (j != 10)
            {
                fprintf(inicializacao, " ");
            }
        }

        fprintf(inicializacao, "\n");
    }

    fprintf(inicializacao, "\n");

    fprintf(inicializacao, "%s\n", jogador2);

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro2[i][j] > 0)
            {
                fprintf(inicializacao, "X");
            }
            else
            {
                fprintf(inicializacao, "o");
            }

            if (j != 10)
            {
                fprintf(inicializacao, " ");
            }
        }

        if (i != 10)
        {
            fprintf(inicializacao, "\n");
        }
    }

    fclose(inicializacao);
}

int Jogo(int identidadesTabuleiro1[30], int identidadesTabuleiro2[30], char matriz[200][100], char jogadas_i[200][2], int jogadas_j[200], char jogador1[17], char jogador2[17], int tabuleiro1[12][12], int tabuleiro2[12][12], int tabuleiro1_identificado[12][12], int tabuleiro2_identificado[12][12], char naviosTabuleiro1[30][11], char naviosTabuleiro2[30][11])
{
    char diretorioConcatenado[1012];

    int i = 0;
    int j = 0;

    char coordenada_i;
    int coordenada_j;

    char caracter;

    char tabuleiro1_saida[12][12];
    char tabuleiro2_saida[12][12];

    int k;
    int l;

    int num1 = 0;
    int num2 = 0;

    int naviosDestruidosTabuleiro1 = 0;
    int naviosDestruidosTabuleiro2 = 0;

    int p = 0;
    int teveJogada = 0;
    int cont = 0;

    InicializaTabuleiros_saida(tabuleiro1_saida, tabuleiro2_saida);

    while (jogadas_i[p][0] != '0')
    {
        coordenada_i = jogadas_i[p][0];
        coordenada_j = jogadas_j[p];

        k = coordenada_i - 96;
        l = coordenada_j;

        printf("Jogada de %s:\n\n", jogador1);

        // Esse loop para caso tenha jogadas invalidas

        while (coordenada_i == 'z' || tabuleiro2_identificado[k][l] == -3)
        {
            ImprimeJogadaInvalidaJogador1(matriz, p, jogador1);

            jogadas_i[p][0] = 'z';
            jogadas_i[p][1] = '\0';

            jogadas_j[p] = 0;

            p++;

            coordenada_i = jogadas_i[p][0];
            coordenada_j = jogadas_j[p];

            k = coordenada_i - 96;
            l = coordenada_j;

            cont++;
        }

        if (tabuleiro2[k][l] > -1)
        {
            num2 = tabuleiro2[k][l];

            tabuleiro2_saida[k][l] = 'X';

            tabuleiro2_identificado[k][l] = -3;

            if (AfundouNavioTabuleiro2(num2, tabuleiro2_identificado) == 0)
            {
                naviosDestruidosTabuleiro2++;

                printf("%c%d:Afundou ", coordenada_i, coordenada_j);

                // Achar o navio correto usando as identidades

                for (i = 0; i < 30; i++)
                {
                    if (identidadesTabuleiro2[i] == num2)
                    {
                        break;
                    }
                }

                for (j = 0; naviosTabuleiro2[i][j] != '0'; j++)
                {
                    printf("%c", naviosTabuleiro2[i][j]);
                }

                printf("\n\n");
            }
            else
            {
                printf("%c%d:Tiro!\n\n", coordenada_i, coordenada_j);
            }

            printf("Tabuleiro atual de %s apos a jogada de %s\n", jogador2, jogador1);

            for (i = 1; i < 11; i++)
            {
                for (j = 1; j < 11; j++)
                {
                    printf("%c", tabuleiro2_saida[i][j]);

                    if (j != 10)
                    {
                        printf(" ");
                    }
                }

                printf("\n");
            }

            printf("\n");
        }
        else
        {
            tabuleiro2_saida[k][l] = 'o';

            printf("%c%d:Agua\n\n", coordenada_i, coordenada_j);

            printf("Tabuleiro atual de %s apos a jogada de %s\n", jogador2, jogador1);

            for (i = 1; i < 11; i++)
            {
                for (j = 1; j < 11; j++)
                {
                    printf("%c", tabuleiro2_saida[i][j]);

                    if (j != 10)
                    {
                        printf(" ");
                    }
                }

                printf("\n");
            }

            printf("\n");
        }

        // Caso Jogador1 tenha destruido todos os navios, Jogador2 ainda tem mais uma jogada para tentar o empate

        if (NaoTemNavioTabuleiro2(tabuleiro2_identificado) == 1)
        {
            p++;

            coordenada_i = jogadas_i[p][0];
            coordenada_j = jogadas_j[p];

            k = coordenada_i - 96;
            l = coordenada_j;

            printf("Jogada de %s:\n\n", jogador2);

            // Loop que descarta jogadas invalidas

            while (coordenada_i == 'z' || tabuleiro1_identificado[k][l] == -3)
            {
                ImprimeJogadaInvalidaJogador2(matriz, p, jogador2);

                jogadas_i[p][0] = 'z';
                jogadas_i[p][1] = '\0';

                jogadas_j[p] = 0;

                p++;

                coordenada_i = jogadas_i[p][0];
                coordenada_j = jogadas_j[p];

                k = coordenada_i - 96;
                l = coordenada_j;
            }

            if (tabuleiro1[k][l] > 0)
            {
                num1 = tabuleiro1[k][l];

                tabuleiro1_saida[k][l] = 'X';

                tabuleiro1_identificado[k][l] = -3;

                if (AfundouNavioTabuleiro1(num1, tabuleiro1_identificado) == 0)
                {
                    printf("%c%d:Afundou ", coordenada_i, coordenada_j);

                    // Achar o navio correto usando as identidades

                    for (i = 0; i < 30; i++)
                    {
                        if (identidadesTabuleiro1[i] == num1)
                        {
                            break;
                        }
                    }

                    for (j = 0; naviosTabuleiro1[i][j] != '0'; j++)
                    {
                        printf("%c", naviosTabuleiro1[i][j]);
                    }

                    printf("\n\n");
                }
                else
                {
                    printf("%c%d:Tiro!\n\n", coordenada_i, coordenada_j);
                }

                printf("Tabuleiro atual de %s apos a jogada de %s\n", jogador1, jogador2);

                for (i = 1; i < 11; i++)
                {
                    for (j = 1; j < 11; j++)
                    {
                        printf("%c", tabuleiro1_saida[i][j]);

                        if (j != 10)
                        {
                            printf(" ");
                        }
                    }

                    printf("\n");
                }

                printf("\n");
            }
            else
            {
                tabuleiro1_saida[k][l] = 'o';

                printf("%c%d:Agua\n\n", coordenada_i, coordenada_j);

                printf("Tabuleiro atual de %s apos a jogada de %s\n", jogador1, jogador2);

                for (i = 1; i < 11; i++)
                {
                    for (j = 1; j < 11; j++)
                    {
                        printf("%c", tabuleiro1_saida[i][j]);

                        if (j != 10)
                        {
                            printf(" ");
                        }
                    }

                    printf("\n");
                }

                printf("\n");
            }

            if (NaoTemNavioTabuleiro1(tabuleiro1_identificado) == 1)
            {
                printf("Empate\n");
                return 0;
            }

            printf("Vencedor: %s\n", jogador1);
            return 1;
        }

        p++;

        coordenada_i = jogadas_i[p][0];
        coordenada_j = jogadas_j[p];

        k = coordenada_i - 96;
        l = coordenada_j;

        printf("Jogada de %s:\n\n", jogador2);

        // Loop que descarta jogadas invalidas

        while (coordenada_i == 'z' || tabuleiro1_identificado[k][l] == -3)
        {
            ImprimeJogadaInvalidaJogador2(matriz, p, jogador2);

            jogadas_i[p][0] = 'z';
            jogadas_i[p][1] = '\0';

            jogadas_j[p] = 0;

            p++;

            coordenada_i = jogadas_i[p][0];
            coordenada_j = jogadas_j[p];

            k = coordenada_i - 96;
            l = coordenada_j;
        }

        if (tabuleiro1[k][l] > 0)
        {
            num1 = tabuleiro1[k][l];

            tabuleiro1_saida[k][l] = 'X';

            tabuleiro1_identificado[k][l] = -3;

            if (AfundouNavioTabuleiro1(num1, tabuleiro1_identificado) == 0)
            {
                naviosDestruidosTabuleiro1++;

                printf("%c%d:Afundou ", coordenada_i, coordenada_j);

                // Achar o navio correto usando as identidades

                for (i = 0; i < 30; i++)
                {
                    if (identidadesTabuleiro1[i] == num1)
                    {
                        break;
                    }
                }

                for (j = 0; naviosTabuleiro1[i][j] != '0'; j++)
                {
                    printf("%c", naviosTabuleiro1[i][j]);
                }

                printf("\n\n");
            }
            else
            {
                printf("%c%d:Tiro!\n\n", coordenada_i, coordenada_j);
            }

            printf("Tabuleiro atual de %s apos a jogada de %s\n", jogador1, jogador2);

            for (i = 1; i < 11; i++)
            {
                for (j = 1; j < 11; j++)
                {
                    printf("%c", tabuleiro1_saida[i][j]);

                    if (j != 10)
                    {
                        printf(" ");
                    }
                }

                printf("\n");
            }

            printf("\n");
        }
        else
        {
            tabuleiro1_saida[k][l] = 'o';

            printf("%c%d:Agua\n\n", coordenada_i, coordenada_j);

            printf("Tabuleiro atual de %s apos a jogada de %s\n", jogador1, jogador2);

            for (i = 1; i < 11; i++)
            {
                for (j = 1; j < 11; j++)
                {
                    printf("%c", tabuleiro1_saida[i][j]);

                    if (j != 10)
                    {
                        printf(" ");
                    }
                }

                printf("\n");
            }

            printf("\n");
        }

        if (NaoTemNavioTabuleiro1(tabuleiro1_identificado) == 1)
        {
            printf("Vencedor: %s\n", jogador2);
            return 2;
        }

        p++;
    }

    if (naviosDestruidosTabuleiro1 > naviosDestruidosTabuleiro2)
    {
        printf("Vencedor: %s\n", jogador2);
        return 2;
    }

    else if (naviosDestruidosTabuleiro2 > naviosDestruidosTabuleiro1)
    {
        printf("Vencedor: %s\n", jogador1);
        return 1;
    }

    else
    {
        printf("Empate\n");
        return 0;
    }
}

void GeraResultado(int numeroDoTiroTabuleiro1[50], int numeroDoTiroTabuleiro2[50], int naviosAcertados_id_Tabuleiro1[50], int naviosAcertados_id_Tabuleiro2[50], char naviosAcertadosTabuleiro1[50][11], char naviosAcertadosTabuleiro2[50][11], int jogadas_j_jogador1[100], int jogadas_j_jogador2[100], char jogadas_i_jogador1[100][2], char jogadas_i_jogador2[100][2], int tirosNavios[4], int venceuJogo, char diretorio[1001], char jogador1[17], char jogador2[17], char jogadas_i[200][2], int jogadas_j[200], char naviosTabuleiro1[30][11], char naviosTabuleiro2[30][11], int identidadesTabuleiro1[30], int identidadesTabuleiro2[30], int tabuleiro1[12][12], int tabuleiro2[12][12])
{
    char coordenada_i;
    int coordenada_j;

    int id = -3;
    int i = 0;
    int j = 0;
    int x = 0;

    int tabuleiro1_cont = 0;
    int tabuleiro2_cont = 0;

    int tabuleiro1_cont_venceu = 0;

    int cont = 0;
    int cont_venceu = 0;

    int n = 0;
    int m = 0;

    int a = 0;

    int contador = 1;

    void InicializaCoordenada_i(char coordenada_i_tabuleiro1[30][2], char coordenada_i_tabuleiro2[30][2]);

    TransfereJogadasValidas(jogadas_i_jogador1, jogadas_i_jogador2, jogadas_j_jogador1, jogadas_j_jogador2, jogadas_i, jogadas_j);

    tabuleiro1_cont = QuantidadeLugaresNaviosTabuleiro1(tabuleiro1);
    tabuleiro2_cont = QuantidadeLugaresNaviosTabuleiro2(tabuleiro2);

    char caracter;
    char diretorioConcatenado[1012];

    strcpy(diretorioConcatenado, diretorio);

    strcat(diretorioConcatenado, "/saida/resultado.txt");

    FILE *resultado;

    resultado = fopen(diretorioConcatenado, "a+");

    fprintf(resultado, "%s\n", jogador1);

    tabuleiro1_cont_venceu = tabuleiro1_cont;

    if (venceuJogo == 2)
    {
        for (i = 0; i < 100; i++)
        {
            if (tabuleiro1_cont_venceu == 0)
            {
                break;
            }

            coordenada_i = jogadas_i_jogador2[i][0];
            coordenada_j = jogadas_j_jogador2[i];

            id = IdentidadeNavioTabuleiro1(coordenada_i, coordenada_j, tabuleiro1);

            if (id > -1)
            {
                tabuleiro1_cont_venceu--;
            }

            cont_venceu++;
        }
    }

    for (i = 0; i < 100; i++)
    {
        if (venceuJogo == 2 && cont_venceu == 0)
        {
            break;
        }

        if (tabuleiro2_cont == 0 || jogadas_i_jogador1[i][0] == '0')
        {
            break;
        }

        coordenada_i = jogadas_i_jogador1[i][0];
        coordenada_j = jogadas_j_jogador1[i];

        id = IdentidadeNavioTabuleiro2(coordenada_i, coordenada_j, tabuleiro2);

        x = AchaNavioCorreto2(id, identidadesTabuleiro2);

        if (id == -1)
        {
            fprintf(resultado, "%c%d - Agua\n", coordenada_i, coordenada_j);
            tirosNavios[0]++;
            contador += 1;
        }
        else
        {
            fprintf(resultado, "%c%d - Tiro - ", coordenada_i, coordenada_j);

            for (j = 0; naviosTabuleiro2[x][j] != '0'; j++)
            {
                fprintf(resultado, "%c", naviosTabuleiro2[x][j]);
                naviosAcertadosTabuleiro2[m][j] = naviosTabuleiro2[x][j];
            }

            fprintf(resultado, " - ID %02d\n", id);
            naviosAcertados_id_Tabuleiro2[m] = id;

            tirosNavios[1]++;

            tabuleiro2_cont--;

            numeroDoTiroTabuleiro2[m] = contador;

            m++;
            contador += 1;
        }

        cont++;
        cont_venceu--;
    }

    fprintf(resultado, "\n%s\n", jogador2);

    contador = 1;

    for (i = 0; i < 100; i++)
    {
        if (tabuleiro1_cont == 0 || cont == 0)
        {
            break;
        }

        coordenada_i = jogadas_i_jogador2[i][0];
        coordenada_j = jogadas_j_jogador2[i];

        id = IdentidadeNavioTabuleiro1(coordenada_i, coordenada_j, tabuleiro1);

        x = AchaNavioCorreto1(id, identidadesTabuleiro1);

        if (id == -1)
        {
            fprintf(resultado, "%c%d - Agua\n", coordenada_i, coordenada_j);

            tirosNavios[2]++;
            contador += 1;
        }
        else
        {
            fprintf(resultado, "%c%d - Tiro - ", coordenada_i, coordenada_j);

            for (j = 0; naviosTabuleiro1[x][j] != '0'; j++)
            {
                fprintf(resultado, "%c", naviosTabuleiro1[x][j]);
                naviosAcertadosTabuleiro1[n][j] = naviosTabuleiro1[x][j];
            }

            fprintf(resultado, " - ID %02d\n", id);
            naviosAcertados_id_Tabuleiro1[n] = id;

            tirosNavios[3]++;

            numeroDoTiroTabuleiro1[n] = contador;

            tabuleiro1_cont--;
            n++;
            contador += 1;
        }

        cont--;
    }

    if (venceuJogo == 0)
    {
        fprintf(resultado, "\nEmpate");
    }

    else if (venceuJogo == 1)
    {
        fprintf(resultado, "\nVencedor: %s", jogador1);
    }

    else if (venceuJogo == 2)
    {
        fprintf(resultado, "\nVencedor: %s", jogador2);
    }

    fclose(resultado);
}

void GeraEstatisticas(int numeroDoTiroTabuleiro1[50], int numeroDoTiroTabuleiro2[50], int naviosAcertados_id_Tabuleiro1[50], int naviosAcertados_id_Tabuleiro2[50], char naviosAcertadosTabuleiro1[50][11], char naviosAcertadosTabuleiro2[50][11], int jogadas_j_jogador1[100], int jogadas_j_jogador2[100], char jogadas_i_jogador1[100][2], char jogadas_i_jogador2[100][2], char diretorio[1001], int tirosNavios[4], char jogador1[17], char jogador2[17])
{
    int i, j;

    float localizacaoMediaTirosJogador1[2] = {0, 0};
    float localizacaoMediaTirosJogador2[2] = {0, 0};

    int numeroDosTirosOrganizadosTabuleiro1[50];
    int numeroDosTirosOrganizadosTabuleiro2[50];

    char nomeDosNaviosOrganizadosTabuleiro1[50][11];
    char nomeDosNaviosOrganizadosTabuleiro2[50][11];

    int id_DosNaviosOrganizadosTabuleiro1[50];
    int id_DosNaviosOrganizadosTabuleiro2[50];

    InicializaOrganizados(numeroDosTirosOrganizadosTabuleiro1, nomeDosNaviosOrganizadosTabuleiro1, id_DosNaviosOrganizadosTabuleiro1, numeroDosTirosOrganizadosTabuleiro2, nomeDosNaviosOrganizadosTabuleiro2, id_DosNaviosOrganizadosTabuleiro2);

    float desvioPadrao = 0;

    char diretorioConcatenado[1012];

    strcpy(diretorioConcatenado, diretorio);

    strcat(diretorioConcatenado, "/saida/estatisticas.txt");

    FILE *estatisticas;

    estatisticas = fopen(diretorioConcatenado, "a+");

    fprintf(estatisticas, "%s\n", jogador1);

    fprintf(estatisticas, "Tiros Errados: %d\n", tirosNavios[0]);
    fprintf(estatisticas, "Tiros Acertados: %d\n", tirosNavios[1]);

    CalculaMediaJogador1(localizacaoMediaTirosJogador1, jogadas_i_jogador1, jogadas_j_jogador1, tirosNavios);

    fprintf(estatisticas, "Localizacao Media: (%.2f,%.2f)\n", localizacaoMediaTirosJogador1[0], localizacaoMediaTirosJogador1[1]);

    desvioPadrao = CalculaDesvioJogador1(localizacaoMediaTirosJogador1, jogadas_i_jogador1, jogadas_j_jogador1, tirosNavios);

    fprintf(estatisticas, "Desvio Padrao da Localizacao: %.2f\n", desvioPadrao);

    fprintf(estatisticas, "Navios de %s:\n", jogador1);

    OrganizaTabuleiro1(numeroDosTirosOrganizadosTabuleiro1, nomeDosNaviosOrganizadosTabuleiro1, id_DosNaviosOrganizadosTabuleiro1, numeroDoTiroTabuleiro1, naviosAcertadosTabuleiro1, naviosAcertados_id_Tabuleiro1);

    for (i = 0; nomeDosNaviosOrganizadosTabuleiro1[i][0] != '0'; i++)
    {
        fprintf(estatisticas, "%02d - ", numeroDosTirosOrganizadosTabuleiro1[i]);

        for (j = 0; nomeDosNaviosOrganizadosTabuleiro1[i][j] != '0'; j++)
        {
            fprintf(estatisticas, "%c", nomeDosNaviosOrganizadosTabuleiro1[i][j]);
        }

        fprintf(estatisticas, " - ID %02d\n", id_DosNaviosOrganizadosTabuleiro1[i]);
    }

    fprintf(estatisticas, "\n%s\n", jogador2);

    fprintf(estatisticas, "Tiros Errados: %d\n", tirosNavios[2]);
    fprintf(estatisticas, "Tiros Acertados: %d\n", tirosNavios[3]);

    CalculaMediaJogador2(localizacaoMediaTirosJogador2, jogadas_i_jogador2, jogadas_j_jogador2, tirosNavios);

    fprintf(estatisticas, "Localizacao Media: (%.2f,%.2f)\n", localizacaoMediaTirosJogador2[0], localizacaoMediaTirosJogador2[1]);

    desvioPadrao = CalculaDesvioJogador2(localizacaoMediaTirosJogador2, jogadas_i_jogador2, jogadas_j_jogador2, tirosNavios);

    fprintf(estatisticas, "Desvio Padrao da Localizacao: %.2f\n", desvioPadrao);

    fprintf(estatisticas, "Navios de %s:\n", jogador2);

    OrganizaTabuleiro2(numeroDosTirosOrganizadosTabuleiro2, nomeDosNaviosOrganizadosTabuleiro2, id_DosNaviosOrganizadosTabuleiro2, numeroDoTiroTabuleiro2, naviosAcertadosTabuleiro2, naviosAcertados_id_Tabuleiro2);

    for (i = 0; nomeDosNaviosOrganizadosTabuleiro2[i][0] != '0'; i++)
    {
        fprintf(estatisticas, "%02d - ", numeroDosTirosOrganizadosTabuleiro2[i]);

        for (j = 0; nomeDosNaviosOrganizadosTabuleiro2[i][j] != '0'; j++)
        {
            fprintf(estatisticas, "%c", nomeDosNaviosOrganizadosTabuleiro2[i][j]);
        }

        fprintf(estatisticas, " - ID %02d\n", id_DosNaviosOrganizadosTabuleiro2[i]);
    }

    fclose(estatisticas);
}

void InicializaTabuleirosIdentificados(int tabuleiro1_identificado[12][12], int tabuleiro2_identificado[12][12])
{
    int i, j;

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (i == 0 || i == 11)
            {
                tabuleiro1_identificado[i][j] = -2;
            }

            else if (j == 0 || j == 11)
            {
                tabuleiro1_identificado[i][j] = -2;
            }

            else
            {
                tabuleiro1_identificado[i][j] = -1;
            }
        }
    }

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (i == 0 || i == 11)
            {
                tabuleiro2_identificado[i][j] = -2;
            }

            else if (j == 0 || j == 11)
            {
                tabuleiro2_identificado[i][j] = -2;
            }

            else
            {
                tabuleiro2_identificado[i][j] = -1;
            }
        }
    }
}

void TranscreveTabuleiro1(int tabuleiro1_identificado[12][12], int tabuleiro1[12][12])
{
    int i, j;

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro1[i][j] > 0)
            {
                tabuleiro1_identificado[i][j] = tabuleiro1[i][j];
            }
        }
    }
}

void TranscreveTabuleiro2(int tabuleiro2_identificado[12][12], int tabuleiro2[12][12])
{
    int i, j;

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro2[i][j] > 0)
            {
                tabuleiro2_identificado[i][j] = tabuleiro2[i][j];
            }
        }
    }
}

int VerificaDistanciaNaviosTabuleiro1(int tabuleiro1_identificado[12][12])
{
    int i, j;

    int validadeTabuleiro1 = 0;

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro1_identificado[i][j] > -1)
            {
                if (tabuleiro1_identificado[i - 1][j] > -1)
                {
                    if (tabuleiro1_identificado[i - 1][j] != tabuleiro1_identificado[i][j])
                    {
                        validadeTabuleiro1++;
                    }
                }

                if (tabuleiro1_identificado[i - 1][j - 1] > -1)
                {
                    if (tabuleiro1_identificado[i - 1][j - 1] != tabuleiro1_identificado[i][j])
                    {
                        validadeTabuleiro1++;
                    }
                }

                if (tabuleiro1_identificado[i][j - 1] > -1)
                {
                    if (tabuleiro1_identificado[i][j - 1] != tabuleiro1_identificado[i][j])
                    {
                        validadeTabuleiro1++;
                    }
                }

                if (tabuleiro1_identificado[i + 1][j - 1] > -1)
                {
                    if (tabuleiro1_identificado[i + 1][j - 1] != tabuleiro1_identificado[i][j])
                    {
                        validadeTabuleiro1++;
                    }
                }

                if (tabuleiro1_identificado[i + 1][j] > -1)
                {
                    if (tabuleiro1_identificado[i + 1][j] != tabuleiro1_identificado[i][j])
                    {
                        validadeTabuleiro1++;
                    }
                }

                if (tabuleiro1_identificado[i + 1][j + 1] > -1)
                {
                    if (tabuleiro1_identificado[i + 1][j + 1] != tabuleiro1_identificado[i][j])
                    {
                        validadeTabuleiro1++;
                    }
                }

                if (tabuleiro1_identificado[i][j + 1] > -1)
                {
                    if (tabuleiro1_identificado[i][j + 1] != tabuleiro1_identificado[i][j])
                    {
                        validadeTabuleiro1++;
                    }
                }

                if (tabuleiro1_identificado[i - 1][j] > -1)
                {
                    if (tabuleiro1_identificado[i - 1][j] != tabuleiro1_identificado[i][j])
                    {
                        validadeTabuleiro1++;
                    }
                }
            }
        }
    }

    return validadeTabuleiro1;
}

int VerificaDistanciaNaviosTabuleiro2(int tabuleiro2_identificado[12][12])
{
    int i, j;

    int validadeTabuleiro2 = 0;

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro2_identificado[i][j] > -1)
            {
                if (tabuleiro2_identificado[i - 1][j] > -1)
                {
                    if (tabuleiro2_identificado[i - 1][j] != tabuleiro2_identificado[i][j])
                    {
                        validadeTabuleiro2++;
                    }
                }

                if (tabuleiro2_identificado[i - 1][j - 1] > -1)
                {
                    if (tabuleiro2_identificado[i - 1][j - 1] != tabuleiro2_identificado[i][j])
                    {
                        validadeTabuleiro2++;
                    }
                }

                if (tabuleiro2_identificado[i][j - 1] > -1)
                {
                    if (tabuleiro2_identificado[i][j - 1] != tabuleiro2_identificado[i][j])
                    {
                        validadeTabuleiro2++;
                    }
                }

                if (tabuleiro2_identificado[i + 1][j - 1] > -1)
                {
                    if (tabuleiro2_identificado[i + 1][j - 1] != tabuleiro2_identificado[i][j])
                    {
                        validadeTabuleiro2++;
                    }
                }

                if (tabuleiro2_identificado[i + 1][j] > -1)
                {
                    if (tabuleiro2_identificado[i + 1][j] != tabuleiro2_identificado[i][j])
                    {
                        validadeTabuleiro2++;
                    }
                }

                if (tabuleiro2_identificado[i + 1][j + 1] > -1)
                {
                    if (tabuleiro2_identificado[i + 1][j + 1] != tabuleiro2_identificado[i][j])
                    {
                        validadeTabuleiro2++;
                    }
                }

                if (tabuleiro2_identificado[i][j + 1] > -1)
                {
                    if (tabuleiro2_identificado[i][j + 1] != tabuleiro2_identificado[i][j])
                    {
                        validadeTabuleiro2++;
                    }
                }

                if (tabuleiro2_identificado[i - 1][j] > -1)
                {
                    if (tabuleiro2_identificado[i - 1][j] != tabuleiro2_identificado[i][j])
                    {
                        validadeTabuleiro2++;
                    }
                }
            }
        }
    }

    return validadeTabuleiro2;
}

void ImprimeValidadeTabuleiros(char diretorio[1001], int validadeTabuleiro1, int validadeTabuleiro2, int qtdNaviosTabuleiro1[5], int qtdNaviosTabuleiro2[5])
{
    int i, j;
    char diretorioConcatenado[1014];

    strcpy(diretorioConcatenado, diretorio);

    strcat(diretorioConcatenado, "/saida/validacao_tabuleiros.txt");

    FILE *validacao_tabuleiros;

    validacao_tabuleiros = fopen(diretorioConcatenado, "a+");

    if (validadeTabuleiro1 == 0 && validadeTabuleiro2 > 0)
    {
        fprintf(validacao_tabuleiros, "tabu_1.txt;valido\ntabu_2.txt;invalido");
        fclose(validacao_tabuleiros);
        exit(1);
    }
    else if (validadeTabuleiro1 > 0 && validadeTabuleiro2 == 0)
    {
        fprintf(validacao_tabuleiros, "tabu_1.txt;invalido\ntabu_2.txt;valido");
        fclose(validacao_tabuleiros);
        exit(1);
    }
    else if (validadeTabuleiro1 > 0 && validadeTabuleiro2 > 0)
    {
        fprintf(validacao_tabuleiros, "tabu_1.txt;invalido\ntabu_2.txt;invalido");
        fclose(validacao_tabuleiros);
        exit(1);
    }

    else
    {
        fprintf(validacao_tabuleiros, "tabu_1.txt;valido\ntabu_2.txt;valido\n");
    }

    if (qtdNaviosTabuleiro1[0] != qtdNaviosTabuleiro2[0])
    {
        fprintf(validacao_tabuleiros, "Tabuleiros incompativeis entre si");
        exit(1);
    }

    else if (qtdNaviosTabuleiro1[1] != qtdNaviosTabuleiro2[1])
    {
        fprintf(validacao_tabuleiros, "Tabuleiros incompativeis entre si");
        exit(1);
    }

    else if (qtdNaviosTabuleiro1[2] != qtdNaviosTabuleiro2[2])
    {
        fprintf(validacao_tabuleiros, "Tabuleiros incompativeis entre si");
        exit(1);
    }

    else if (qtdNaviosTabuleiro1[3] != qtdNaviosTabuleiro2[3])
    {
        fprintf(validacao_tabuleiros, "Tabuleiros incompativeis entre si");
        exit(1);
    }

    else if (qtdNaviosTabuleiro1[4] != qtdNaviosTabuleiro2[4])
    {
        fprintf(validacao_tabuleiros, "Tabuleiros incompativeis entre si");
        exit(1);
    }

    else
    {
        fprintf(validacao_tabuleiros, "Tabuleiros compativeis entre si");
    }

    fclose(validacao_tabuleiros);
}

void InicializaTabuleiros_saida(char tabuleiro1_saida[12][12], char tabuleiro2_saida[12][12])
{
    int i, j;

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (i == 0 || i == 11)
            {
                tabuleiro1_saida[i][j] = '*';
            }

            else if (j == 0 || j == 11)
            {
                tabuleiro1_saida[i][j] = '*';
            }

            else
            {
                tabuleiro1_saida[i][j] = '.';
            }
        }
    }

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (i == 0 || i == 11)
            {
                tabuleiro2_saida[i][j] = '*';
            }

            else if (j == 0 || j == 11)
            {
                tabuleiro2_saida[i][j] = '*';
            }

            else
            {
                tabuleiro2_saida[i][j] = '.';
            }
        }
    }
}

int AfundouNavioTabuleiro2(int num2, int tabuleiro2_identificado[12][12])
{
    int i, j;
    int cont = 0;

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro2_identificado[i][j] == num2)
            {
                cont++;
            }
        }
    }

    return cont;
}

int AfundouNavioTabuleiro1(int num1, int tabuleiro1_identificado[12][12])
{
    int i, j;
    int cont = 0;

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro1_identificado[i][j] == num1)
            {
                cont++;
            }
        }
    }

    return cont;
}

int NaoTemNavioTabuleiro2(int tabuleiro2_identificado[12][12])
{
    int i, j;

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro2_identificado[i][j] > -1)
            {
                return 0;
            }
        }
    }

    return 1;
}

int NaoTemNavioTabuleiro1(int tabuleiro1_identificado[12][12])
{
    int i, j;

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro1_identificado[i][j] > -1)
            {
                return 0;
            }
        }
    }

    return 1;
}

int VarreCoordenadaInicalTabuleiro1(char coordenada_i_tabuleiro1[30][2], int coordenada_j_tabuleiro1[30])
{
    int i, j;
    int cont;

    for (i = 0; coordenada_j_tabuleiro1[i] > 0; i++)
    {
        for (j = 0; coordenada_j_tabuleiro1[j] > 0; j++)
        {
            if (i != j)
            {
                if (coordenada_i_tabuleiro1[i][0] == coordenada_i_tabuleiro1[j][0])
                {
                    if (coordenada_j_tabuleiro1[i] == coordenada_j_tabuleiro1[j])
                    {
                        cont++;
                    }
                }
            }
        }
    }

    return cont;
}

int VarreCoordenadaInicalTabuleiro2(char coordenada_i_tabuleiro2[30][2], int coordenada_j_tabuleiro2[30])
{
    int i, j;
    int cont;

    for (i = 0; coordenada_j_tabuleiro2[i] > 0; i++)
    {
        for (j = 0; coordenada_j_tabuleiro2[j] > 0; j++)
        {
            if (i != j)
            {
                if (coordenada_i_tabuleiro2[i][0] == coordenada_i_tabuleiro2[j][0])
                {
                    if (coordenada_j_tabuleiro2[i] == coordenada_j_tabuleiro2[j])
                    {
                        cont++;
                    }
                }
            }
        }
    }

    return cont;
}

void ImprimeJogadaInvalidaJogador1(char matriz[200][100], int p, char jogador1[17])
{
    int i, j;

    for (i = 0; matriz[p][i] != '*'; i++)
    {
        printf("%c", matriz[p][i]);
    }

    printf(":Jogada invalida! Jogue novamente %s:\n\n", jogador1);
}

void ImprimeJogadaInvalidaJogador2(char matriz[200][100], int p, char jogador2[17])
{
    int i, j;

    for (i = 0; matriz[p][i] != '*'; i++)
    {
        printf("%c", matriz[p][i]);
    }

    printf(":Jogada invalida! Jogue novamente %s:\n\n", jogador2);
}

void TransfereJogadasValidas(char jogadas_i_jogador1[100][2], char jogadas_i_jogador2[100][2], int jogadas_j_jogador1[100], int jogadas_j_jogador2[100], char jogadas_i[200][2], int jogadas_j[200])
{
    int i, j, k = 0, l = 0;
    int cont = 0;

    for (i = 0; i < 200; i++)
    {
        while (jogadas_i[i][0] == 'z')
        {
            i++;
        }

        jogadas_i_jogador1[k][0] = jogadas_i[i][0];
        jogadas_j_jogador1[k] = jogadas_j[i];

        i++;
        k++;

        while (jogadas_i[i][0] == 'z')
        {
            i++;
        }

        jogadas_i_jogador2[l][0] = jogadas_i[i][0];
        jogadas_j_jogador2[l] = jogadas_j[i];

        l++;
    }
}

int IdentidadeNavioTabuleiro1(char coordenada_i, int coordenada_j, int tabuleiro1[12][12])
{
    int i, j;
    int num;

    i = coordenada_i - 96;
    j = coordenada_j;

    num = tabuleiro1[i][j];

    return num;
}

int IdentidadeNavioTabuleiro2(char coordenada_i, int coordenada_j, int tabuleiro2[12][12])
{
    int i, j;
    int num;

    i = coordenada_i - 96;
    j = coordenada_j;

    num = tabuleiro2[i][j];

    return num;
}

int AchaNavioCorreto1(int id, int identidadesTabuleiro1[30])
{
    int i;

    for (i = 0; i < 30; i++)
    {
        if (id == identidadesTabuleiro1[i])
        {
            return i;
        }
    }
}

int AchaNavioCorreto2(int id, int identidadesTabuleiro2[30])
{
    int i;

    for (i = 0; i < 30; i++)
    {
        if (id == identidadesTabuleiro2[i])
        {
            return i;
        }
    }
}

int QuantidadeLugaresNaviosTabuleiro1(int tabuleiro1[12][12])
{
    int i, j;
    int cont = 0;

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro1[i][j] > -1)
            {
                cont++;
            }
        }
    }

    return cont;
}

int QuantidadeLugaresNaviosTabuleiro2(int tabuleiro2[12][12])
{
    int i, j;
    int cont = 0;

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
        {
            if (tabuleiro2[i][j] > -1)
            {
                cont++;
            }
        }
    }

    return cont;
}

void CopiaTabuleiros(int tabuleiro1_copia[12][12], int tabuleiro2_copia[12][12], int tabuleiro1[12][12], int tabuleiro2[12][12])
{
    int i, j;

    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            tabuleiro1_copia[i][j] = tabuleiro1[i][j];
            tabuleiro2_copia[i][j] = tabuleiro2[i][j];
        }
    }
}

void CalculaMediaJogador1(float localizacaoMediaTirosJogador1[2], char jogadas_i_jogador1[100][2], int jogadas_j_jogador1[100], int tirosNavios[4])
{
    int i = 0;

    float x = 0.00;
    float y = 0.00;

    y = tirosNavios[0] + tirosNavios[1];

    for (i = 0; i < y; i++)
    {
        x += jogadas_i_jogador1[i][0] - 96;
    }

    localizacaoMediaTirosJogador1[0] = x / y;

    x = 0;

    for (i = 0; i < y; i++)
    {
        x += jogadas_j_jogador1[i];
    }

    localizacaoMediaTirosJogador1[1] = x / y;
}

void CalculaMediaJogador2(float localizacaoMediaTirosJogador2[2], char jogadas_i_jogador2[100][2], int jogadas_j_jogador2[100], int tirosNavios[4])
{
    int i;

    float x = 0;
    float y = 0;

    y = tirosNavios[2] + tirosNavios[3];

    for (i = 0; i < y; i++)
    {
        x += jogadas_i_jogador2[i][0] - 96;
    }

    localizacaoMediaTirosJogador2[0] = x / y;

    x = 0;

    for (i = 0; i < y; i++)
    {
        x += jogadas_j_jogador2[i];
    }

    localizacaoMediaTirosJogador2[1] = x / y;
}

float CalculaDesvioJogador1(float localizacaoMediaTirosJogador1[2], char jogadas_i_jogador1[100][2], int jogadas_j_jogador1[100], int tirosNavios[4])
{
    int i;

    float n = 0;
    float linha = 0;
    float coluna = 0;
    float somatorio = 0;

    n = tirosNavios[0] + tirosNavios[1];

    for (i = 1; i <= n; i++)
    {
        linha = jogadas_i_jogador1[i - 1][0] - 96;
        coluna = jogadas_j_jogador1[i - 1];

        somatorio += ((pow(linha - localizacaoMediaTirosJogador1[0], 2)) + (pow(coluna - localizacaoMediaTirosJogador1[1], 2)));
    }

    somatorio /= n;

    somatorio = sqrt(somatorio);

    return somatorio;
}

float CalculaDesvioJogador2(float localizacaoMediaTirosJogador2[2], char jogadas_i_jogador2[100][2], int jogadas_j_jogador2[100], int tirosNavios[4])
{
    int i;

    float n = 0;
    float linha = 0;
    float coluna = 0;
    float somatorio = 0;

    n = tirosNavios[2] + tirosNavios[3];

    for (i = 1; i <= n; i++)
    {
        linha = jogadas_i_jogador2[i - 1][0] - 96;
        coluna = jogadas_j_jogador2[i - 1];

        somatorio += ((pow(linha - localizacaoMediaTirosJogador2[0], 2)) + (pow(coluna - localizacaoMediaTirosJogador2[1], 2)));
    }

    somatorio /= n;

    somatorio = sqrt(somatorio);

    return somatorio;
}

void InicializaNaviosAcertadosID(int naviosAcertados_id_Tabuleiro1[50], int naviosAcertados_id_Tabuleiro2[50])
{
    int i;

    for (i = 0; i < 50; i++)
    {
        naviosAcertados_id_Tabuleiro1[i] = 0;
        naviosAcertados_id_Tabuleiro2[i] = 0;
    }
}

void OrganizaTabuleiro1(int numeroDosTirosOrganizadosTabuleiro1[50], char nomeDosNaviosOrganizadosTabuleiro1[50][11], int id_DosNaviosOrganizadosTabuleiro1[50], int numeroDoTiroTabuleiro1[50], char naviosAcertadosTabuleiro1[50][11], int naviosAcertados_id_Tabuleiro1[50])
{
    int i = -1, j = 0;
    int k = 1, l = 0;
    int b = 0, c = 0;
    int n = 0;

    for (i = 0; i < 50; i++)
    {
        for (j = 1; j < 50; j++)
        {
            if (naviosAcertados_id_Tabuleiro1[i] == naviosAcertados_id_Tabuleiro1[j] && i != j)
            {
                naviosAcertados_id_Tabuleiro1[j] = 0;
            }
        }
    }

    for (i = 0; naviosAcertadosTabuleiro1[i][0] != '0'; i++)
    {
        if (naviosAcertadosTabuleiro1[i][0] == 'B' && naviosAcertados_id_Tabuleiro1[i] > 0)
        {
            numeroDosTirosOrganizadosTabuleiro1[n] = numeroDoTiroTabuleiro1[i];

            for (j = 0; j < 11; j++)
            {
                nomeDosNaviosOrganizadosTabuleiro1[n][j] = naviosAcertadosTabuleiro1[i][j];
            }

            id_DosNaviosOrganizadosTabuleiro1[n] = naviosAcertados_id_Tabuleiro1[i];

            n++;
        }
    }

    for (i = 0; naviosAcertadosTabuleiro1[i][0] != '0'; i++)
    {
        if (naviosAcertadosTabuleiro1[i][0] == 'C' && naviosAcertadosTabuleiro1[i][1] == 'a' && naviosAcertados_id_Tabuleiro1[i] > 0)
        {
            numeroDosTirosOrganizadosTabuleiro1[n] = numeroDoTiroTabuleiro1[i];

            for (j = 0; j < 11; j++)
            {
                nomeDosNaviosOrganizadosTabuleiro1[n][j] = naviosAcertadosTabuleiro1[i][j];
            }

            id_DosNaviosOrganizadosTabuleiro1[n] = naviosAcertados_id_Tabuleiro1[i];

            n++;
        }
    }

    for (i = 0; naviosAcertadosTabuleiro1[i][0] != '0'; i++)
    {
        if (naviosAcertadosTabuleiro1[i][0] == 'C' && naviosAcertadosTabuleiro1[i][1] == 'r' && naviosAcertados_id_Tabuleiro1[i] > 0)
        {
            numeroDosTirosOrganizadosTabuleiro1[n] = numeroDoTiroTabuleiro1[i];

            for (j = 0; j < 11; j++)
            {
                nomeDosNaviosOrganizadosTabuleiro1[n][j] = naviosAcertadosTabuleiro1[i][j];
            }

            id_DosNaviosOrganizadosTabuleiro1[n] = naviosAcertados_id_Tabuleiro1[i];

            n++;
        }
    }

    for (i = 0; naviosAcertadosTabuleiro1[i][0] != '0'; i++)
    {
        if (naviosAcertadosTabuleiro1[i][0] == 'D' && naviosAcertados_id_Tabuleiro1[i] > 0)
        {
            numeroDosTirosOrganizadosTabuleiro1[n] = numeroDoTiroTabuleiro1[i];

            for (j = 0; j < 11; j++)
            {
                nomeDosNaviosOrganizadosTabuleiro1[n][j] = naviosAcertadosTabuleiro1[i][j];
            }

            id_DosNaviosOrganizadosTabuleiro1[n] = naviosAcertados_id_Tabuleiro1[i];

            n++;
        }
    }

    for (i = 0; naviosAcertadosTabuleiro1[i][0] != '0'; i++)
    {
        if (naviosAcertadosTabuleiro1[i][0] == 'S' && naviosAcertados_id_Tabuleiro1[i] > 0)
        {
            numeroDosTirosOrganizadosTabuleiro1[n] = numeroDoTiroTabuleiro1[i];

            for (j = 0; j < 11; j++)
            {
                nomeDosNaviosOrganizadosTabuleiro1[n][j] = naviosAcertadosTabuleiro1[i][j];
            }

            id_DosNaviosOrganizadosTabuleiro1[n] = naviosAcertados_id_Tabuleiro1[i];

            n++;
        }
    }
}

void OrganizaTabuleiro2(int numeroDosTirosOrganizadosTabuleiro2[50], char nomeDosNaviosOrganizadosTabuleiro2[50][11], int id_DosNaviosOrganizadosTabuleiro2[50], int numeroDoTiroTabuleiro2[50], char naviosAcertadosTabuleiro2[50][11], int naviosAcertados_id_Tabuleiro2[50])
{
    int i = -1, j = 0;
    int k = 1, l = 0;
    int b = 0, c = 0;
    int n = 0;

    for (i = 0; i < 50; i++)
    {
        for (j = 1; j < 50; j++)
        {
            if (naviosAcertados_id_Tabuleiro2[i] == naviosAcertados_id_Tabuleiro2[j] && i != j)
            {
                naviosAcertados_id_Tabuleiro2[j] = 0;
            }
        }
    }

    for (i = 0; naviosAcertadosTabuleiro2[i][0] != '0'; i++)
    {
        if (naviosAcertadosTabuleiro2[i][0] == 'B' && naviosAcertados_id_Tabuleiro2[i] > 0)
        {
            numeroDosTirosOrganizadosTabuleiro2[n] = numeroDoTiroTabuleiro2[i];

            for (j = 0; j < 11; j++)
            {
                nomeDosNaviosOrganizadosTabuleiro2[n][j] = naviosAcertadosTabuleiro2[i][j];
            }

            id_DosNaviosOrganizadosTabuleiro2[n] = naviosAcertados_id_Tabuleiro2[i];

            n++;
        }
    }

    for (i = 0; naviosAcertadosTabuleiro2[i][0] != '0'; i++)
    {
        if (naviosAcertadosTabuleiro2[i][0] == 'C' && naviosAcertadosTabuleiro2[i][1] == 'a' && naviosAcertados_id_Tabuleiro2[i] > 0)
        {
            numeroDosTirosOrganizadosTabuleiro2[n] = numeroDoTiroTabuleiro2[i];

            for (j = 0; j < 11; j++)
            {
                nomeDosNaviosOrganizadosTabuleiro2[n][j] = naviosAcertadosTabuleiro2[i][j];
            }

            id_DosNaviosOrganizadosTabuleiro2[n] = naviosAcertados_id_Tabuleiro2[i];

            n++;
        }
    }

    for (i = 0; naviosAcertadosTabuleiro2[i][0] != '0'; i++)
    {
        if (naviosAcertadosTabuleiro2[i][0] == 'C' && naviosAcertadosTabuleiro2[i][1] == 'r' && naviosAcertados_id_Tabuleiro2[i] > 0)
        {
            numeroDosTirosOrganizadosTabuleiro2[n] = numeroDoTiroTabuleiro2[i];

            for (j = 0; j < 11; j++)
            {
                nomeDosNaviosOrganizadosTabuleiro2[n][j] = naviosAcertadosTabuleiro2[i][j];
            }

            id_DosNaviosOrganizadosTabuleiro2[n] = naviosAcertados_id_Tabuleiro2[i];

            n++;
        }
    }

    for (i = 0; naviosAcertadosTabuleiro2[i][0] != '0'; i++)
    {
        if (naviosAcertadosTabuleiro2[i][0] == 'D' && naviosAcertados_id_Tabuleiro2[i] > 0)
        {
            numeroDosTirosOrganizadosTabuleiro2[n] = numeroDoTiroTabuleiro2[i];

            for (j = 0; j < 11; j++)
            {
                nomeDosNaviosOrganizadosTabuleiro2[n][j] = naviosAcertadosTabuleiro2[i][j];
            }

            id_DosNaviosOrganizadosTabuleiro2[n] = naviosAcertados_id_Tabuleiro2[i];

            n++;
        }
    }

    for (i = 0; naviosAcertadosTabuleiro2[i][0] != '0'; i++)
    {
        if (naviosAcertadosTabuleiro2[i][0] == 'S' && naviosAcertados_id_Tabuleiro2[i] > 0)
        {
            numeroDosTirosOrganizadosTabuleiro2[n] = numeroDoTiroTabuleiro2[i];

            for (j = 0; j < 11; j++)
            {
                nomeDosNaviosOrganizadosTabuleiro2[n][j] = naviosAcertadosTabuleiro2[i][j];
            }

            id_DosNaviosOrganizadosTabuleiro2[n] = naviosAcertados_id_Tabuleiro2[i];

            n++;
        }
    }
}

void InicializaOrganizados(int numeroDosTirosOrganizadosTabuleiro1[50], char nomeDosNaviosOrganizadosTabuleiro1[50][11], int id_DosNaviosOrganizadosTabuleiro1[50], int numeroDosTirosOrganizadosTabuleiro2[50], char nomeDosNaviosOrganizadosTabuleiro2[50][11], int id_DosNaviosOrganizadosTabuleiro2[50])
{
    int i, j;

    for (i = 0; i < 50; i++)
    {
        numeroDosTirosOrganizadosTabuleiro1[i] = 0;
        numeroDosTirosOrganizadosTabuleiro2[i] = 0;

        for (j = 0; j < 11; j++)
        {
            nomeDosNaviosOrganizadosTabuleiro1[i][j] = '0';
            nomeDosNaviosOrganizadosTabuleiro2[i][j] = '0';
        }

        id_DosNaviosOrganizadosTabuleiro1[i] = 0;
        id_DosNaviosOrganizadosTabuleiro2[i] = 0;
    }
}