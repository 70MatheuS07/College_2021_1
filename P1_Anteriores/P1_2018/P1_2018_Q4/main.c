#include <stdio.h>

int main()
{
    int dias = 0, horas = 0, minutos = 0, incremento = 0;

    scanf("%d:%d %d", &horas, &minutos, &incremento);

    minutos = minutos + incremento;

    while (minutos >= 60)
    {
        minutos -= 60;
        horas += 1;
    }

    while (horas >= 24)
    {
        horas -= 24;
        dias += 1;
    }

    if (dias == 1)
    {
        printf("(1 dia)");
    }

    else if (dias > 1)
    {
        printf("(%d dias)", dias);
    }

    if (horas == 1)
    {
        printf("(1 hora)");
    }

    else if (horas > 1)
    {
        printf("(%d horas)", horas);
    }

    if (minutos == 1)
    {
        printf("(1 minuto)");
    }

    else if (minutos > 1)
    {
        printf("(%d minutos)", minutos);
    }

    return 0;
}