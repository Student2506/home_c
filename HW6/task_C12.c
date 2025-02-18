#include <stdio.h>
#include <limits.h>


float cosinus(int);
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

float cosinus(int number)
{
    const float pi = 3.1415926535;
    float rads = number * pi / 180;
    float sin = rads;

    float prev_sin = 1000.;
    int k = 3;
    int flag = 0;
    while (abs_value(prev_sin - sin) > 0.00001)
    {
        prev_sin = sin;
        if (flag == 0)
        {
            sin = sin - power(rads, k) / factorial(k);
            flag = 1;
        }
        else
        {
            sin = sin + power(rads, k) / factorial(k);
            flag = 0;
        }
        k += 2;
    }
    return sin;
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

float abs_value(float number)
{
    if (number < 0.) return -number;
    return number;
}

