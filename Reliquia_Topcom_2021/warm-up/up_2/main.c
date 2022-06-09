#include <stdio.h>
#include <math.h>

int main()
{
    int N1, N2;
    float M1;
    
    scanf("%d %d ", &N1, &N2);
    M1 = (N1 + N2) / 2.0;

    if (M1 < 5)
    {
        printf("%.1f - Reprovado", M1);
    }

    else if (M1 >= 7)
    {
        printf("%.1f - Aprovado", M1);
    }

    else if (M1 >= 5 && M1 < 7)
    {
        printf("%.1f - De Recuperacao", M1);
    }

    return 0;
}