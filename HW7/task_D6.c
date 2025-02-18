#include <stdio.h>

void reverse_string(char* current);

int main(int argc, char **argv)
{
    char input[40];
    fgets(input, 40, stdin);
    reverse_string(input);
    return 0;
}

void reverse_string(char* current)
{
    if (*current == '.') {
        return;
    }
    reverse_string(current + 1);
    printf("%c", current[0]);
}
