#include <stdio.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int temp, min, max;
	min = INT_MAX;
	max = INT_MIN;

	for (int i=0; i < 5;i++) {
		scanf("%d", &temp);
		if (min > temp) min = temp;
		if (max < temp) max = temp;
	}
	printf("%d", min + max);
    return 0;
}