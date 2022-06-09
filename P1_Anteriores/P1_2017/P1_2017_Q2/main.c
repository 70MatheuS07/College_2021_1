#include <stdio.h>

int main()
{

    int n1 = 0, n2 = 0;
    int mulheres = 0, homens = 0;

    scanf("%d %d", &n1, &n2);

    if (n1 < 1)
    {
        printf("Invalido");
    }

    else if (n1 > 10)
    {
        printf("Invalido");
    }

    else if (n2 < 1)
    {
        printf("Invalido");
    }

    else if (n2 > 10)
    {
        printf("Invalido");
    }

    

    else if (n1 == n2 && n1 >= 1 && n1 <= 5)
    {
        printf("Um homem");
    }

    else if (n1 == n2 && n1 >= 6 && n1 <= 10)
    {
        printf("Uma mulher");
    }

    else if ((n1 != n2 && n1 >= 1 && n1 <= 5 && n2 >= 6 && n2 <= 10) || (n1 != n2 && n2 >= 1 && n2 <= 5 && n1 >= 6 && n1 <= 10))
    {
        printf("Um casal");
    }

    else if (n1 != n2 && n1 >= 1 && n1 <= 5 && n2 >= 1 && n2 <= 5)
    {
        printf("Par de homens");
    }

    else if (n1 != n2 && n1 >= 6 && n1 <= 10 && n2 >= 5 && n2 <= 10)
    {
        printf("Par de mulheres");
    }

    return 0;
}