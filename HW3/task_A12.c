#include <stdio.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int input, temp;

	scanf("%d", &input);

	temp = input % 10;
	input /= 10;
	temp += input % 10;
	input /= 10;
	temp += input;

	printf("%d", temp);
    return 0;
}