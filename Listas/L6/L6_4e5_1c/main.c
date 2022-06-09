#include <stdio.h>
typedef struct Pacote
{
    int identificador_mensagem;
    int identifica_pacote;
    char tamanho_conteudo;
    int tamanho_efetivo;
    char msg[100];
    int codigo_erro;

} tPacote;

tPacote LePacote();

int verificaPacote(tPacote pacote);

void ImprimeMensagem(tPacote pacote);

void Modifica(tPacote pacote[], int n);

int main(void)
{
    int n, i = 0, j = 0;

    scanf("%d", &n);

    tPacote pacote[n];

    for (i = 0; i < n; i++)
    {
        pacote[i] = LePacote();
    }

    Modifica(pacote, n);

    int cod = pacote[0].identificador_mensagem;

    for (i = 0; i < n; i++)
    {
        if (pacote[i].identificador_mensagem != cod)
        {
            cod = pacote[i].identificador_mensagem;
            printf("\n");
        }
        
        if (verificaPacote(pacote[i]) == pacote[i].codigo_erro)
        {
            ImprimeMensagem(pacote[i]);
        }
        else
        {
            printf("##FALHA##");
        }
    }

    return 0;
}

tPacote LePacote()
{
    tPacote pacote;

    int i = 0;

    char lixo[100];

    scanf("%d %d %c", &pacote.identificador_mensagem, &pacote.identifica_pacote, &pacote.tamanho_conteudo);

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

void ImprimeMensagem(tPacote pacote)
{
    printf("%s", pacote.msg);
}

int verificaPacote(tPacote pacote)
{
    int ver = 0, i = 0;

    ver += pacote.identificador_mensagem;
    ver += pacote.identifica_pacote;
    ver += pacote.tamanho_efetivo;

    for (i = 0; i < pacote.tamanho_efetivo; i++)
    {
        ver += pacote.msg[i];
    }

    return ver;
}

void Modifica(tPacote pacote[], int n)
{
    tPacote aux;
    int i = 0, j = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (pacote[j].identificador_mensagem > pacote[j + 1].identificador_mensagem)
            {
                aux = pacote[j];
                pacote[j] = pacote[j + 1];
                pacote[j + 1] = aux;
            }
            else if (pacote[j].identificador_mensagem == pacote[j + 1].identificador_mensagem)
            {
                if (pacote[j].identifica_pacote > pacote[j + 1].identifica_pacote)
                {
                    aux = pacote[j];
                    pacote[j] = pacote[j + 1];
                    pacote[j + 1] = aux;
                }
            }
        }
    }
}