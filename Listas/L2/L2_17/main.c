#include <stdio.h>

int main()
{

    int num = 0, loop = 0, n1 = 0, n2 = 0;
    char c;

    scanf("%d", &num);

    if (num == 1 || num == 2)
    {

        n1 = num;
    }

    if (num > 2 || num < 1)
    {

        printf("Operacao invalida.");
        return 0;
    }

    num = 0;

    scanf("%d", &num);

    n2 = num;

    while (n2 > 25)
    {
        loop = (n2 - 26);
        n2 = loop;
    }

    while (n2 < -25)
    {
        loop = (n2 + 26);
        n2 = loop;
    }

    getchar();

    while (scanf("%c", &c) == 1)
    {

        if (c >= 0 && c <= 31)
        {
            printf("%c", c);
        }

        if (c >= 'a' && c <= 'z')
        {

            if (n1 == 1)
            {
                c = (c + n2);

                if (c > 'z')
                {
                    c = (c - 26);
                    printf("%c", c);
                }
                else
                {
                    printf("%c", c);
                }
            }

            else if (n1 == 2)
            {
                c = (c - n2);

                if (c < 'a')
                {
                    c = (c + 26);
                    printf("%c", c);
                }
                else
                {
                    printf("%c", c);
                }
            }
        }

        else if (c == ' ')
        {
            printf(" ");
        }

        else if (c == '.')
        {
            printf(".");
            break;
        }
        else
        {
            printf("%c", c);
        }
    }

    return 0;
}