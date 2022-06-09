#include <stdio.h>

int main()
{
    int n1 = 0, n2 = 0, total = 0;
    char c;

    scanf("%d %d %c", &n1, &n2, &c);

    if (c == '*')
    {
        total = n1 * n2;
        printf("RESP:%d", total);
    }

    else if (c == '/')
    {
        total = n1 / n2;
        printf("RESP:%d", total);
    }

    else if (c == '+')
    {
        total = n1 + n2;
        printf("RESP:%d", total);
    }

    else if (c == '-')
    {
        total = n1 - n2;
        printf("RESP:%d", total);
    }

    else
    {
        printf("Invalido");
    }

    return 0;
}