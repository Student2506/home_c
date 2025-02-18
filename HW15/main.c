#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv)
{
    int x1, y1, x2, y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    float delta_y = y2 - y1;
    float delta_x = x2 - x1;
    float m = delta_y/delta_x;

    // y = mx + b
    // b = y - mx
    float b = y1 - m * x1;
    printf("%.2f %.2f", m, b);

    return 0;
}
