#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1001

int main(int argc, char **argv)
{
    FILE *fp = fopen("input.txt", "r");
    char freq[26] = { 0 };
    char word[LIMIT];
    fgets(word, LIMIT, fp);
    int length = strlen(word);

    for(int i = 0; i < length; i++)
    {
        if(word[i] != ' ') freq[word[i] - 'a']++;
    }
    char center = '0';
    for(int i = 0; i < 26; i++)
    {
        if(freq[i] % 2 == 1) {
            center = 'a' + i;
            break;
        }
    }
    int available_letters = 0;
    for(int i = 0; i < 26; i++) {
        if (freq[i] >= 2) available_letters += freq[i] / 2;
    }
    int new_length = available_letters * 2;
    if(center != '0') new_length = available_letters * 2 + 1;

    int j = 0;
    int i = 0;
    while(j < available_letters)
    {
        while(freq[i] < 2) i++;
        freq[i] -= 2;
        j++;
    }
    int accum = 0;
    for(int i = 0; i < 26; i++)
    {
        accum += freq[i];
    }
    if(accum <= 1) printf("YES");
    else printf("NO");
    fclose(fp);
    return 0;
}
