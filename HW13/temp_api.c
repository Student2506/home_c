#include "temp_api.h"
#include "libintl.h"
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_temp_by_month(int, float, int, int);
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

double average_temp_per_month(sqlite3 *db, int month, int year) {
  char *query = "SELECT AVG(TEMPERATURE) FROM TempDate WHERE MONTH = ?1 AND YEAR = ?2;";
  double result;
  int rc;
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error sqlite3_prepare_v2 in average_temp_per_month %d\n", rc);
    return 0.0;
  }
  rc = sqlite3_bind_int(stmt, 1, month);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error sqlite3_bind_int 1 in average_temp_per_month %d\n", rc);
    return 0.0;
  }
  rc = sqlite3_bind_int(stmt, 2, year);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error sqlite3_bind_int 2 in average_temp_per_month %d\n", rc);
    return 0.0;
  }
  rc = sqlite3_step(stmt);
  if (rc == SQLITE_ROW) {
    result = sqlite3_column_double(stmt, 0);
    sqlite3_finalize(stmt);
    return result;
  }
  sqlite3_finalize(stmt);
  return 0.0;
}
int min_per_month(sqlite3 *db, int month, int year) {
  char *query = "SELECT MIN(TEMPERATURE) FROM TempDate WHERE MONTH = ?1 AND YEAR = ?2;";
  int result;
  int rc;
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error sqlite3_prepare_v2 in min_per_month %d\n", rc);
    return 0.0;
  }
  rc = sqlite3_bind_int(stmt, 1, month);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error sqlite3_bind_int 1 in min_per_month %d\n", rc);
    return 0.0;
  }
  rc = sqlite3_bind_int(stmt, 2, year);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error sqlite3_bind_int 2 in min_per_month %d\n", rc);
    return 0.0;
  }
  rc = sqlite3_step(stmt);
  if (rc == SQLITE_ROW) {
    result = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    return result;
  }
  sqlite3_finalize(stmt);
  return INT_MIN;
}
int max_per_month(sqlite3 *db, int month, int year) {
  char *query = "SELECT MAX(TEMPERATURE) FROM TempDate WHERE MONTH = ?1 AND YEAR = ?2;";
  int result;
  int rc;
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error sqlite3_prepare_v2 in max_per_month %d\n", rc);
    return 0.0;
  }
  rc = sqlite3_bind_int(stmt, 1, month);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error sqlite3_bind_int 1 in max_per_month %d\n", rc);
    return 0.0;
  }
  rc = sqlite3_bind_int(stmt, 2, year);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error sqlite3_bind_int 2 in max_per_month %d\n", rc);
    return 0.0;
  }
  rc = sqlite3_step(stmt);
  if (rc == SQLITE_ROW) {
    result = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    return result;
  }
  sqlite3_finalize(stmt);
  return INT_MAX;
}

void print_stat_per_year(sqlite3 *db) {
  char *query = "SELECT DISTINCT YEAR FROM TempDate;";
  int rc, year;
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
  if (rc != SQLITE_OK) {
    printf("Error\n");
    return;
  }
  rc = sqlite3_step(stmt);
  if (rc == SQLITE_ROW) {
    year = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
  } else {
    sqlite3_finalize(stmt);
    return;
  }
  printf(_("Statistical data for the %dth year\n"), year);
  float accum_temp = 0.0f;
  int min_per_year = INT_MAX, max_per_year = INT_MIN;
  int month_qty_in_stats = 0;
  for (int month = 1; month <= 12; month++) {
    float average_temp = average_temp_per_month(db, month, year);
    if (isfinite(average_temp)) {
      accum_temp += average_temp;
      month_qty_in_stats++;
    }
    int min_per_month_value = min_per_month(db, month, year);
    int max_per_month_value = max_per_month(db, month, year);
    min_per_year > min_per_month_value ? min_per_year = min_per_month_value : min_per_year;
    max_per_year < max_per_month_value ? max_per_year = max_per_month_value : max_per_year;
    print_temp_by_month(month, average_temp, min_per_month_value, max_per_month_value);
  }
  if (month_qty_in_stats == 0)
    month_qty_in_stats = 1;
  printf(ngettext("For year:\nAverage: %.2f degree Celsius\n", "For year:\nAverage: %.2f degrees Celsius\n",
                  accum_temp / month_qty_in_stats),
         accum_temp / (float)month_qty_in_stats);
  printf(ngettext("Minimal: %d degree Celsius\n", "Minimal: %d degrees Celsius\n", min_per_year), min_per_year);
  printf(ngettext("Maximal: %d degree Celsius\n\n", "Maximal: %d degrees Celsius\n\n", max_per_year), max_per_year);
}

void print_stats_per_month(sqlite3 *db, int year, int month) {
  float average_temp = average_temp_per_month(db, month, year);
  int min_per_month_value = min_per_month(db, month, year);
  int max_per_month_value = max_per_month(db, month, year);
  print_temp_by_month(month, average_temp, min_per_month_value, max_per_month_value);
}

void print_temp_by_month(int month_number, float average, int min_temp, int max_temp) {
  char *month[] = {_("January"), _("February"), _("March"),     _("April"),   _("May"),      _("June"),
                   _("July"),    _("August"),   _("September"), _("October"), _("November"), _("December")};
  if (!isfinite(average)) {
    printf(_("Temperature for the %s is absent.\n"), month[month_number - 1]);
    return;
  }
  printf(_("Temperature for %s:\n"), month[month_number - 1]);
  printf(ngettext("Average: %.2f degree Celsius\n", "Average: %.2f degrees Celsius\n", (int)average), average);
  printf(ngettext("Minimal: %d degree Celsius\n", "Minimal: %d degrees Celsius\n", min_temp), min_temp);
  printf(ngettext("Maximal: %d degree Celsius\n\n", "Maximal: %d degrees Celsius\n\n", max_temp), max_temp);
}
