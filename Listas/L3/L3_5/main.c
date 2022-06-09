#include <stdio.h>

int Propriedade(int num);

int main()
{
    int n = 0, m = 0, i = 0, result = 0, num = 0;

    scanf("%d %d", &n, &m);

    num = n + 1;
    i = m - 1;

    for (num; num <= i; num++)
    {
        result = Propriedade(num);

        if (n < result && m > result)
        {
            num = result;
            printf("%d\n", result);
        }
        else
        {
            break;
        }
    }
    return 0;
}

int Propriedade(int num)
{
    int ab = 1, cd = 1, ef = 1;

    while (num < 9999)
    {

        ab = (num / 100);
        cd = (num - (ab * 100));
        ef = (ab + cd);

        if ((ef * ef) == num)
        {
            return (num);
        }
        num++;
    }

    return 0;
}