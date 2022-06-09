#include <stdio.h>

int main()
{

    int n, m, den, loop;

    scanf("%d %d", &n, &m);

    printf("RESP:");

    n = n + 1;
    m = m - 1;
    den = 1;

    for (n; n <= m; n++)
    {
        while (den <= n)
        {
            if (n % den == 0)
            {
                loop++;
            }
            den++;
        }

        if (loop == 2)
        {
            printf("%d ", n);
        }
        
        den = 1;
        loop = 0;
    }

    return 0;
}