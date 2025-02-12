#include <stdio.h>

int main(int argc, char **argv)
{
	int temp, max;


	for (int i=0; i < 5;i++) {
		scanf("%d", &temp);
		if (max < temp) max = temp;
	}
	printf("%d", max);
    return 0;
}