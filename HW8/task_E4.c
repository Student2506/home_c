#include <stdio.h>
#include <limits.h>

#define LIMIT 10

int main(int argc, char **argv)
{
    int numbers[LIMIT] = {-1};
    int maximum = INT_MIN;
    int maximum_prev = INT_MIN;
    for (int i = 0; i < LIMIT; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < LIMIT; i++)
    {
        if (maximum <= numbers[i])
        {
            maximum_prev = maximum;
            maximum = numbers[i];
        }
        if (numbers[i] > maximum_prev && numbers[i] != maximum)
            maximum_prev = numbers[i];
    }

    printf("%d", maximum + maximum_prev);
    return 0;
}
