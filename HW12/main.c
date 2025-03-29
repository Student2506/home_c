#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "temp_api.h"

#define LIMIT 256

int main(int argc, char *argv[])
{

    char filename[LIMIT] = {'\0'};
    int result = 0;
    while ((result = getopt(argc, argv, "hf:m")) != -1)
    {
        opterr = 0;
        switch (result)
        {
        case 'h':
            printf("Usage: %s [options]\n", argv[0]);
            printf("-h This help text\n");
            printf("-f Input csv file for processing\n");
            printf("-m Month to show stats about\n");
            return 0;
        case 'f':
            strcpy(filename, optarg);
            break;
        case 'm':
            break;
        case '?':
            printf("Unknown argument: %s Try -h for help\n", argv[optind - 1]);
            return 1;
        }
    }
    if (strlen(filename) == 0)
    {
        printf("Filename is mandatory\n");
        return 1;
    }
    printf("Processing %s\n", filename);

    TempDate data[] = {
        {2010, 1, 1, 8, 0, 30},
        {2010, 1, 2, 8, 0, 28},
        {2010, 1, 3, 8, 0, 15},
        {2010, 1, 4, 8, 0, 16},
        {2010, 1, 5, 8, 0, 16},
        {2010, 2, 1, 8, 0, 30},
        {2010, 3, 2, 8, 0, 28},
        {2010, 4, 3, 8, 0, 15},
        {2010, 5, 4, 8, 0, 16},
        {2010, 6, 5, 8, 0, 16},
        {2010, 7, 1, 8, 0, 30},
        {2010, 8, 2, 8, 0, 28},
        {2010, 8, 3, 8, 0, 15},
        {2010, 9, 4, 8, 0, 16},
        {2010, 10, 5, 8, 0, 16},
        {2010, 11, 1, 8, 0, 30},
        {2010, 12, 2, 8, 0, 28},
        {2010, 3, 3, 8, 0, 15},
        {2010, 4, 4, 8, 0, 16},
        {2010, 5, 5, 8, 0, 16},
        {2010, 6, 1, 8, 0, 14},
        {2010, 7, 1, 8, 0, 14},
        {2010, 3, 1, 8, 0, 3},
        {2011, 1, 1, 8, 0, 3},
        {2011, 2, 1, 8, 0, 17},
        {2011, 3, 1, 8, 0, 30},
        {2011, 4, 1, 8, 0, 28},
        {2012, 1, 1, 8, 0, 30},
        {2012, 2, 1, 8, 0, 15},
        {2012, 2, 4, 8, 0, 30},
    };
    printf("%.2f\n", temp_per_month(data, 30, 1, 2010));
    printf("%d\n", max_per_month(data, 30, 1, 2010));
    printf("%d\n", min_per_month(data, 30, 1, 2010));
    print_stat_per_year(data, 30);
    return 0;
}