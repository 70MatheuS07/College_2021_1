#include <stdio.h>

int main()
{
    int x1 = 0, x2 = 0, x3 = 0;
    int y1 = 0, y2 = 0, y3 = 0;
    int a = 0, b = 0, x = 0, y = 0;
    int cont = 0;

    scanf("%d %d %d %d %d %d %d %d ", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);

    if ((a * x1) + b == y1)
    {
        cont++;
    }

    if ((a * x2) + b == y2)
    {
        cont++;
    }

    if ((a * x3) + b == y3)
    {
        cont++;
    }

    if (cont > 0)
    {
        if (cont == 1)
        {
            printf("Um");
        }

        else if (cont == 2)
        {
            printf("Dois");
        }

        else if (cont == 3)
        {
            printf("Todos");
        }
    }
    else
    {
        printf("Nenhum");
    }

    return 0;
}