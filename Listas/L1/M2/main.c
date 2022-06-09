#include <stdio.h>

int main()
{
  float N1, R1, R2;

  scanf("%f", &N1);

  R1 = (int)N1;

  R2 = N1 - R1;

  printf("INTEIRO:%.0f,", R1);

  printf("REAL:%.2f", R2);

  return 0;
}