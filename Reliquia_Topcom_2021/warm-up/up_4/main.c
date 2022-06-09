#include <stdio.h>

int main()
{

    int n, loop;

    scanf("%d", &n);

    if (((n % 2 != 0) && (n % 3 != 0) && (n % 5 != 0)) || (n == 2) || (n == 3) || (n == 5))
    {

        printf("Primo");
    }
    else
    {

        printf("Nao primo");
    }

    return 0;
}