#include <stdio.h>

int main()
{
    char letra1, letra2, letra3, letra4;
    int cont = 0;

    scanf("%c%c%c%c", &letra1, &letra2, &letra3, &letra4);

    if (letra1 >= 'A' && letra1 <= 'Z')
    {
        cont++;
    }

    else
    {
        cont = 10;
    }

    if (letra2 >= '0' && letra2 <= '9')
    {
        cont++;
    }
    else
    {
        cont = 10;
    }

    if (letra3 == 'A' || letra3 == 'E' || letra3 == 'I' || letra3 == 'O' || letra3 == 'U')
    {
        cont++;
    }

    else if (letra3 == 'a' || letra3 == 'e' || letra3 == 'i' || letra3 == 'o' || letra3 == 'u')
    {
        letra3 = letra3 - 32;
        cont++;
    }
    else
    {
        cont = 10;
    }

    if (letra4 >= 'a' && letra4 <= 'z' && letra4 != 'a' && letra4 != 'e' && letra4 != 'i' && letra4 != 'o' && letra4 != 'u')
    {
        letra4 = letra4 - 32;
        cont++;
    }
    else
    {
        cont = 10;
    }

    if (cont == 4)
    {
        printf("%c%c%c%c", letra1, letra2, letra3, letra4);
    }
    else
    {
        printf("Invalido");
    }

    return 0;
}