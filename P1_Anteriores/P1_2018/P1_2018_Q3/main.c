#include <stdio.h>

int main()
{
    char c1, c2, c3;
    char c4, c5, c6;

    scanf("%c %c %c ", &c1, &c2, &c3);
    scanf("%c %c %c", &c4, &c5, &c6);

    if (c1 >= '0' && c1 <= '9' && c4 >= '0' && c4 <= '9')
    {
        if (c2 >= 'a' && c2 <= 'z' && c5 >= 'a' && c5 <= 'z')
        {
            if (c3 >= 'a' && c3 <= 'z' || c3 >= 'A' && c3 <= 'Z' && c6 >= 'a' && c6 <= 'z' || c6 >= 'A' && c6 <= 'Z')
            {
                if (c1 == c4)
                {
                    printf("I");
                }
                else
                {
                    printf("D");
                }

                if (c2 == c5)
                {
                    printf("I");
                }
                else
                {
                    printf("D");
                }

                if (c3 == c6)
                {
                    printf("I\n");
                }

                else if (c3 < c6)
                {
                    if (c6 - c3 == 32)
                    {
                        printf("C\n");
                    }
                    else
                    {
                        printf("D\n");
                    }
                }

                else if (c3 > c6)
                {
                    if (c3 - c6 == 32)
                    {
                        printf("C\n");
                    }
                    else
                    {
                        printf("D\n");
                    }
                }
            }
            else
            {
                printf("Codigo invalido!\n");
            }
        }
        else
        {
            printf("Codigo invalido!\n");
        }
    }
    else
    {
        printf("Codigo invalido!\n");
    }

    return 0;
}