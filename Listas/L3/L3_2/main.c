#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main()
{

    float num1 = 0, num2 = 0, result = 0;
    char c;

    while (scanf("%f %f %c", &num1, &num2, &c) == 3)
    {

        if (c == '*')
        {
            result = Multiplicacao(num1, num2);
        }

        else if (c == '/')
        {
            result = Divisao(num1, num2);
        }

        else if (c == '+')
        {
            result = Soma(num1, num2);
        }

        else if (c == '-')
        {
            result = Subtracao(num1, num2);
        }
        
        break;
    }


    while (scanf(" %f %c", &num2, &c) == 2)
    {

        if (c == '*')
        {
            num1 = result;
            
            result = Multiplicacao(num1, num2);

        }

        else if (c == '/')
        {
            num1 = result;
            
            result = Divisao(num1, num2);

        }

        else if (c == '+')
        {
            num1 = result;
            
            result = Soma(num1, num2);

        }

        else if (c == '-')
        {
            num1 = result;
            
            result = Subtracao(num1, num2);

        }
    }

    printf("%.2f", result);

    return 0;
}

float Soma(float num1, float num2)
{
    float total;
    total = num1 + num2;
    return (total);
}

float Subtracao(float num1, float num2)
{
    float total;
    total = num1 - num2;
    return (total);
}

float Divisao(float num1, float num2)
{
    float total;
    total = num1 / num2;
    return (total);
}

float Multiplicacao(float num1, float num2)
{
    float total;
    total = num1 * num2;
    return (total);
}
