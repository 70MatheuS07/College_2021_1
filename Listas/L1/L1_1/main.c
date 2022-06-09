#include <stdio.h>
#include <math.h>

int main()
{
  float N1, N2, R1, R2, soma;

  scanf("%f %f", &N1, &N2);

  R1 = sqrt(N1);
  R2 = sqrt(N2);

  soma = R1 + R2;

  printf("%.2f", soma);

  return 0;
}