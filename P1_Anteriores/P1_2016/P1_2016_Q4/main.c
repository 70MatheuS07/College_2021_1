#include <stdio.h>

int main()
{

    int N1 = 0, N2 = 0, N3 = 0;
    int i = 1;
    int dezenaN1 = 0, dezenaN2 = 0, dezenaN3 = 0;
    int centenaN1 = 0, centenaN2 = 0, centenaN3 = 0;

    scanf("%d %d %d", &N1, &N2, &N3);

    dezenaN1 = N1 % 100;
    centenaN1 = (N1 % 1000) - dezenaN1;
    N1 = centenaN1 / 100;

    dezenaN2 = N2 % 100;
    centenaN2 = (N2 % 1000) - dezenaN2;
    N2 = centenaN2 / 100;

    dezenaN3 = N3 % 100;
    centenaN3 = (N3 % 1000) - dezenaN3;
    N3 = centenaN3 / 100;

    if (N1 != 0 && N2 != 0 && N3 != 0)
    {
        if (N1 < N2 && N1 < N3)
        {
            printf("N1");
        }

        else if (N2 < N1 && N2 < N3)
        {
            printf("N2");
        }

        else if (N3 < N1 && N3 < N2)
        {
            printf("N3");
        }

        else if (N1 == N2 && N1 < N3)
        {
            printf("N1");
        }

        else if (N1 == N2 && N3 < N1)
        {
            printf("N3");
        }

        else if (N1 == N3 && N1 < N2)
        {
            printf("N1");
        }

        else if (N1 == N3 && N2 < N1)
        {
            printf("N2");
        }

        else if (N2 == N3 && N2 < N1)
        {
            printf("N2");
        }

        else if (N2 == N3 && N1 < N2)
        {
            printf("N1");
        }

        else if (N1 == N2 && N1 == N3)
        {
            printf("N1");
        }
    }
    
    if (N1 == 0 && N2 < N3)
    {
        printf("N2");
    }

    else if (N1 == 0 && N3 < N2)
    {
        printf("N3");
    }

    else if (N2 == 0 && N1 < N3)
    {
        printf("N1");
    }

    else if (N2 == 0 && N3 < N1)
    {
        printf("N3");
    }

    else if (N3 == 0 && N1 < N2)
    {
        printf("N1");
    }

    else if (N3 == 0 && N2 < N1)
    {
        printf("N2");
    }

    else if (N1 == 0 && N2 == 0 && N3 == 0)
    {
        printf("Nenhum");
    }

    return 0;
}