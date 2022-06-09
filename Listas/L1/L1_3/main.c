#include <stdio.h>
#include <math.h>

int main() {
float N1,N2,N3,N4,R1,R2,cord1,cord2,soma;
scanf("%f""%f""%f""%f",&N1,&N2,&N3,&N4);
cord1=N1-N3;
cord2=N2-N4;
R1=fabs(cord1);
R2=fabs(cord2);
soma=(2*R1)+(2*R2);
printf("%.2f",soma);
return 0;
}