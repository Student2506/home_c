#include <stdio.h>

float cosinus(float);
int factorial(int);
float power(float, int);
float abs_value(float number);

int main(int argc, char **argv)
{
    int input;

    scanf("%d", &input);
    printf("%.3f", cosinus(input));
    return 0;
}

float cosinus(float number)
{
    const float pi = 3.1415926535;
    float rads = number * pi / 180.;
    float cos = 1.;

    float prev_cos = 1000.;
    int k = 2;
    int flag = 0;
    while (abs_value(prev_cos - cos) > 0.00001)
    {
        prev_cos = cos;
        if (flag == 0)
        {
            cos = cos - power(rads, k) / factorial(k);
            flag = 1;
        }
        else
        {
            cos = cos + power(rads, k) / factorial(k);
            flag = 0;
        }
        k += 2;
    }
    return cos;
}

float abs_value(float number)
{
    if (number < 0.) return -number;
    return number;
}

int factorial(int input)
{
    int accum = 1;
    for (int i = 1; i <= input; i++)
    {
        accum *= i;
    }
    return accum;
}
float power(float n, int p)
{
    float counter = 1.;
    for(int i = 0; i < p; i++) {
        counter *= n;
    }
    return counter;
}

