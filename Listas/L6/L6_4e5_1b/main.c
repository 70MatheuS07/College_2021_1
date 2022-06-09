#include <stdio.h>
typedef struct Pacote
{
    int identificador_mensagem;
    int identeifica_pacote;
    char tamanho_conteudo;
    int tamanho_efetivo;
    char msg[100];
    int codigo_erro;

} tPacote;

tPacote LePacote();

int verificaPacote(tPacote pacote);

void ImprimePacote(tPacote pacote);

int main(void)
{
    int n, i = 0;

    scanf("%d", &n);

    tPacote pacote[n];

    for (i = 0; i < n; i++)
    {
        pacote[i] = LePacote();
        if (verificaPacote(pacote[i]) == pacote[i].codigo_erro)
        {
            ImprimePacote(pacote[i]);
        }
        else
        {
            printf("FALHA!\n");
        }
    }
    return 0;
}

tPacote LePacote()
{
    tPacote pacote;

    int i = 0;
    char lixo[100];

    scanf("%d %d %c", &pacote.identificador_mensagem, &pacote.identeifica_pacote, &pacote.tamanho_conteudo);

    pacote.tamanho_efetivo = pacote.tamanho_conteudo - '0';

    for (i = 0; i < pacote.tamanho_efetivo; i++)
    {
        scanf("%c", &pacote.msg[i]);
    }

    pacote.msg[i] = '\0';

    scanf("%[^ 9-0]", lixo);
    scanf("%d\n", &pacote.codigo_erro);
    
    return pacote;
}

void ImprimePacote(tPacote pacote)
{
    printf("PCT: %d,%d,%d,%s,%d\n", pacote.identificador_mensagem, pacote.identeifica_pacote, pacote.tamanho_efetivo, pacote.msg, pacote.codigo_erro);
}

int verificaPacote(tPacote pacote)
{
    int ver = 0, i = 0;
    
    ver += pacote.identificador_mensagem;
    ver += pacote.identeifica_pacote;
    ver += pacote.tamanho_efetivo;

    for (i = 0; i < pacote.tamanho_efetivo; i++)
    {
        ver += pacote.msg[i];
    }

    return ver;
}