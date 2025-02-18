#include <stdio.h>

int globalVar = 5;

int main(int argc, char **argv)
{
    unsigned int u = 50;
    int i = -500;
    int answer = (int) i / u;
    printf("%d", answer);
    return 0;
}