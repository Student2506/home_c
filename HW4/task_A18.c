#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv)
{
	int a, b;

	scanf("%d %d", &a, &b);
	if (a > b) printf("Above");
	else if (b > a) printf("Less");
	else printf("Equal");

    return 0;
}