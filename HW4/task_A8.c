#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, c, temp;
	scanf("%d %d %d", &a, &b, &c);
	if (a > b)
	{
		if (a > c) temp = a;
		else temp = c;
	}
	else
	{
		if (b > c) temp = b;
		else temp = c;
	}
	printf("%d", temp);
    return 0;
}