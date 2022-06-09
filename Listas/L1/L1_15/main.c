#include <stdio.h>

int main()
{
  int n, oi;
  n = n >= 0 && n <= 99999;

  scanf("%d %d", &n, &oi);

  if (oi == 1 && n % 2 == 0)
  {
    printf("PAR");
  }
  else if (oi == 1 && n % 2 != 0)
  {
    printf("IMPAR");
  }
  else if (oi == 2)
  {
    n = n % 100;
    n = n / 10;
    if (n % 2 == 0)
    {
      printf("PAR");
    }
    else
    {
      printf("IMPAR");
    }
  }
  else if (oi == 3)
  {
    n = n % 1000;
    n = n / 100;
    if (n % 2 == 0)
    {
      printf("PAR");
    }
    else
    {
      printf("IMPAR");
    }
  }
  else if (oi == 4)
  {
    n = n % 10000;
    n = n / 1000;
    if (n % 2 == 0)
    {
      printf("PAR");
    }
    else
    {
      printf("IMPAR");
    }
  }
  else if (oi == 5)
  {
    n = n % 100000;
    n = n / 10000;
    if (n % 2 == 0)
    {
      printf("PAR");
    }
    else
    {
      printf("IMPAR");
    }
  }

  return 0;
}