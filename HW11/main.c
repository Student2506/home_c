#include <stdio.h>
#include "temp_api.h"

int main(void)
{
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
    printf("%.2f\n", average_temp_per_month(data, 30, 1, 2010));
    printf("%d\n", max_per_month(data, 30, 1, 2010));
    printf("%d\n", min_per_month(data, 30, 1, 2010));
    print_stat_by_year(data, 30);
    return 0;
}