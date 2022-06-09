#include <stdio.h>
#include <math.h>

int main()
{
    char T1;
    float X, R;
    scanf("%f %c", &X, &T1);

    if ((T1 == 'f') || (T1 == 'F'))
    {
        R = (X - 32) / 1.8;
        printf("%.2f (C)", R);
    }
    else if ((T1 == 'c') || (T1 == 'C'))
    {
        R = (X * 1.8) + 32;
        printf("%.2f (F)", R);
    }

    return 0;
}