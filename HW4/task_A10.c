#include <stdio.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int temp, min;
	min = INT_MAX;

	for (int i=0; i < 5;i++) {
		scanf("%d", &temp);
		if (min > temp) min = temp;
	}
	printf("%d", min);
    return 0;
}