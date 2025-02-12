#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv)
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a + c > b && a + b > c && b + c > a) printf("YES");
	else printf("NO");

    return 0;
}