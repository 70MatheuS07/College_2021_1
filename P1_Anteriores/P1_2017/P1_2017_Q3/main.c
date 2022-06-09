#include <stdio.h>

int main()
{
    char c1, c2, c3, c4;
    int cont = 0;

    scanf("%c%c ", &c1, &c2);
    scanf("%c%c", &c3, &c4);

    if (c1 >= 'A' && c1 <= 'Z')
    {
        c1 = c1 + 32;
    }

    if (c2 >= 'A' && c2 <= 'Z')
    {
        c2 = c2 + 32;
    }

    if (c3 >= 'A' && c3 <= 'Z')
    {
        c3 = c3 + 32;
    }

    if (c4 >= 'A' && c4 <= 'Z')
    {
        c4 = c4 + 32;
    }

    if ((c1 >= '0' && c1 <= '9') || (c1 >= 'a' && c1 <= 'z') || (c1 >= 'A' && c1 <= 'Z'))
    {
        if ((c2 >= '0' && c2 <= '9') || (c2 >= 'a' && c2 <= 'z') || (c2 >= 'A' && c2 <= 'Z'))
        {
            if ((c3 >= '0' && c3 <= '9') || (c3 >= 'a' && c3 <= 'z') || (c3 >= 'A' && c3 <= 'Z'))
            {
                if ((c4 >= '0' && c4 <= '9') || (c4 >= 'a' && c4 <= 'z') || (c4 >= 'A' && c4 <= 'Z'))
                {

                    if (c1 == c3 && c2 == c4)
                    {
                        printf("IGUAIS");
                    }

                    else if (c1 != c3 && c2 == c4)
                    {
                        printf("DIFERENTES");
                    }

                    else if (c1 == c3 && c2 != c4)
                    {
                        printf("DIFERENTES");
                    }

                    else if (c1 != c3 && c2 != c4)
                    {
                        printf("DIFERENTES");
                    }
                }
                else
                {
                    cont++;
                }
            }
            else
            {
                cont++;
            }
        }
        else
        {
            cont++;
        }
    }
    else
    {
        cont++;
    }

    if (cont > 0)
    {
        printf("Invalido");
    }

    return 0;
}