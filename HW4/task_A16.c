#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv)
{
	int input, temp;

	int result = 1;

	temp = INT_MIN;
	for (int i = 0; i<3; i++) {
		scanf("%d", &input);
		if (temp < input) temp = input;
		else {
			result = 0;
			break;
		}

	}
	if (result == 1)
		printf("YES");
	else
		printf("NO");
    return 0;
}