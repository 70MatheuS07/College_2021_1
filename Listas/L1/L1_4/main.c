#include <stdio.h>
#include <math.h>

int main()
{
#define PI 3.141592
    float R1, R2, Area1, Area2;

    scanf("%f", &R1);
    Area1 = PI * R1 * R1;

    Area2 = Area1 / 2;
    R2 = sqrt(Area2 / PI);

    printf("%.2f "
           "%.2f",
           Area1, R2);
    return 0;
}