#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c, i = 0, result, j = 0, k = 0, l = 0;

    scanf("%d", &c);

    for (i = 0; i < c; i++)
    {
        scanf("%d", &result);

        int n[result], m[result];

        for (j = 0; j < result; j++)
        {
            scanf("%d", &n[j]);
        }

        scanf("\n");

        for (j = 0; j < result; j++)
        {
            m[j] = 0;

            for (k = 0; k < result; k++)
            {
                if (n[j] < n[k])
                {
                    m[j]++;
                }
            }
        }

        for (l = 0; l < result; l++)
        {
            printf("%d ", m[l]);
        }

        printf("\n");
    }
    
    return 0;
}