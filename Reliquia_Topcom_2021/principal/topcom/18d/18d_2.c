#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    int K;
    int calculo = 0;
    int i;
    int num = 3, soma=0;

    scanf("%d\n", &T);

    if (T >= 1 && T <= 103)
    {
        for (i = 0; i < T; i++)
        {
            scanf("%d\n", &K);
            soma =0;
            if (K >= 0 && K <= 106)
            {   
                /*soma = K*2+soma;
                if(K==0) soma++;
                printf("%d\n", soma);*/
                if (K == 0)
                {
                    printf("1\n");
                }

                else if (K == 1)
                {
                    printf("2\n");
                }

                else if (K == 3)
                {
                    printf("3\n");
                }

                else if (K > 3)
                {
                    while (calculo < K)
                    {
                        num++;

                        calculo = num * (num - 3);
                        calculo = calculo / 2;
                        calculo += num;
                    }

                    printf("%d\n", num);
                }

                num = 4;
                calculo = 0;
                
            }
        }
    }

    return 0;
}