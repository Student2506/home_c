#include "temp_api.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

static int remove_duplicates(int *, int);
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

float average_temp_per_month(TempDate temps[], int length, int month, int year)
{
    int accum_temp = 0;
    int qty_month_in_array = 0;
    for (int i = 0; i < length; i++)
    {
        if (temps[i].year == year && temps[i].MM == month)
        {
            accum_temp += temps[i].temperature;
            qty_month_in_array++;
        }
    }

    return qty_month_in_array != 0 ? (float)accum_temp / qty_month_in_array : INFINITY;
}
int min_per_month(TempDate temps[], int length, int month, int year)
{
    int min = INT_MAX;
    for (int i = 0; i < length; i++)
    {
        if (temps[i].year == year && temps[i].MM == month)
        {
            min > temps[i].temperature ? min = temps[i].temperature : min;
        }
    }
    return min;
}
int max_per_month(TempDate temps[], int length, int month, int year)
{
    int max = INT_MIN;
    for (int i = 0; i < length; i++)
    {
        if (temps[i].year == year && temps[i].MM == month)
        {
            max < temps[i].temperature ? max = temps[i].temperature : max;
        }
    }
    return max;
}
void print_stat_by_year(TempDate stats[], int length)
{
    int from_year = INT_MAX, to_year = INT_MIN;
    int *years = malloc(length * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        years[i] = stats[i].year;
    }
    qsort(years, length, sizeof(int), compare);
    int new_length = remove_duplicates(years, length);

    for (int i = 0; i < new_length; i++)
    {
        if (years[i] < from_year)
            from_year = years[i];
        if (years[i] > to_year)
            to_year = years[i];
    }
    for (int year = from_year; year <= to_year; year++)
    {
        float accum_temp = 0.0f;
        int min_per_year = INT_MAX, max_per_year = INT_MIN;
        int month_qty_in_stats = 0;
        for (int month = 1; month <= 12; month++)
        {
            float current_temp = average_temp_per_month(stats, length, month, year);
            if (isfinite(current_temp))
            {
                accum_temp += current_temp;
                month_qty_in_stats++;
            }
            int min_per_month_value = min_per_month(stats, length, month, year);
            int max_per_month_value = max_per_month(stats, length, month, year);
            min_per_year > min_per_month_value ? min_per_year = min_per_month_value : min_per_year;
            max_per_year < max_per_month_value ? max_per_year = max_per_month_value : max_per_year;
        }
        printf("====================\n");
        if (month_qty_in_stats == 0)
            month_qty_in_stats = 1;
        printf("%d:\nAverage %.2f\nMin %d\nMax %d\n", year, accum_temp / (float)month_qty_in_stats, min_per_year, max_per_year);
        printf("Month quantity: %d\n", month_qty_in_stats);
    }
    free(years);
}

static int remove_duplicates(int *years, int length)
{
    int *out = malloc(length * sizeof(int));
    out[0] = years[0];
    int j = 0, i = 1;
    while (i < length)
    {
        if (years[i] != out[j])
            out[++j] = years[i];
        i++;
    }
    memcpy(years, out, (j + 1) * sizeof(int));
    free(out);
    return j + 1;
}