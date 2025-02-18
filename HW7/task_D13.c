#include <stdio.h>

void print_prime(int number);
int is_prime(int n, int delitel);

int main(int argc, char **argv)
{
    int first;
    scanf("%d", &first);
    if (first == 2){
        printf("%d", first);
        return 0;
    } else if (first < 2) {
        return 0;
    }

    print_prime(first);
    return 0;
}

void print_prime(int number)
{
    if (number < 2) return;
    for(int i = 2; i < number; i++)
    {
        if(number % i == 0)
        {
            printf("%d ", i);
            print_prime(number/i);
            if(is_prime(number/i, i))
            {
                printf("%d ", number/i);
            }
            break;
        }
    }
}

int is_prime(int n, int delitel)
{
    if (n <= 1) return 0;
    if (delitel * delitel > n) return 1;
    if (n % delitel == 0) return 0;
    else return is_prime(n, delitel + 1);
}

