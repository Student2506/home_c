#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv)
{
	int input, temp;

	scanf("%d", &input);
	temp = INT_MIN;
	for (int i = 0; i<3; i++) {
		temp = (input % 10 > temp) ? input % 10 : temp;
		input /= 10;
	}

	printf("%d", temp);
    return 0;
}