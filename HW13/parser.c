#include "parser.h"
#include "libintl.h"
#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW_LIMIT 80
#define DELIMTER ";"
#define RADIX 10

static bool is_date_correct(uint16_t, uint8_t, uint8_t, uint8_t, uint8_t);

int count_rows(char *filename) {
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, _("Can't open file %s. Check existance and permissions.\n"), filename);
    return -1;
  };
  uint32_t length = 0;
  char ch;
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n')
      length++;
  }
  fseek(fp, -1L, SEEK_END);
  if (fgetc(fp) != '\n')
    length++; // file has no newline at the end
  fclose(fp);
  return length;
}

void read_file(char *filename, TempDate array[], uint32_t *current_length) {

  FILE *fp = fopen(filename, "r");
  char *buffer = malloc(sizeof(char) * ROW_LIMIT);
  int fileLineCounter = 0;
  while (fgets(buffer, ROW_LIMIT, fp) != NULL) {
    fileLineCounter++;
    buffer[strcspn(buffer, "\n")] = 0;
    TempDate elem;
    char *pEnd = NULL;
    char *temp = strtok(buffer, DELIMTER);
    errno = 0;
    elem.year = strtol(temp, &pEnd, RADIX);
    if (temp == pEnd || errno == ERANGE || (errno != 0 && elem.year == 0)) {
      printf(_("Found error in row %d.\n"), fileLineCounter);
      continue;
    }
    temp = strtok(NULL, DELIMTER);
    errno = 0;
    elem.MM = strtol(temp, &pEnd, RADIX);
    if (temp == pEnd || errno == ERANGE || (errno != 0 && elem.MM == 0)) {
      printf(_("Found error in row %d.\n"), fileLineCounter);
      continue;
    }
    temp = strtok(NULL, DELIMTER);
    errno = 0;
    elem.dd = strtol(temp, &pEnd, RADIX);
    if (temp == pEnd || errno == ERANGE || (errno != 0 && elem.dd == 0)) {
      printf(_("Found error in row %d.\n"), fileLineCounter);
      continue;
    }
    temp = strtok(NULL, DELIMTER);
    errno = 0;
    elem.hh = strtol(temp, &pEnd, RADIX);
    if (temp == pEnd || errno == ERANGE || (errno != 0 && elem.hh == 0)) {
      printf(_("Found error in row %d.\n"), fileLineCounter);
      continue;
    }
    temp = strtok(NULL, DELIMTER);
    errno = 0;
    elem.mm = strtol(temp, &pEnd, RADIX);
    if (temp == pEnd || errno == ERANGE || (errno != 0 && elem.mm == 0)) {
      printf(_("Found error in row %d.\n"), fileLineCounter);
      continue;
    }
    temp = strtok(NULL, DELIMTER);
    errno = 0;
    elem.temperature = strtol(temp, &pEnd, RADIX);
    if (temp == pEnd || errno == ERANGE || (errno != 0 && elem.temperature == 0)) {
      printf(_("Found error in row %d.\n"), fileLineCounter);
      continue;
    }
    if (is_date_correct(elem.year, elem.MM, elem.dd, elem.hh, elem.mm))
      array[*current_length] = elem;
    else
      continue;
    (*current_length)++;
  }
  fclose(fp);
}

static bool is_date_correct(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute) {
  int normal_year[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int leap_year[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  bool isLeapYear = false;
  if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
    isLeapYear = true;
  if (isLeapYear) {
    if (day <= 0 || day > leap_year[month - 1])
      return false;
  } else {
    if (day <= 0 || day > normal_year[month - 1])
      return false;
  }
  if (month <= 0 || month > 12)
    return false;
  if (hour > 23)
    return false;
  if (minute > 59)
    return false;
  return true;
}
/*
    STRTOL check details
    if (nptr == endptr)
        printf (" number : %lu  invalid  (no digits found, 0 returned)\n", number);
    else if (errno == ERANGE && number == LONG_MIN)
        printf (" number : %lu  invalid  (underflow occurred)\n", number);
    else if (errno == ERANGE && number == LONG_MAX)
        printf (" number : %lu  invalid  (overflow occurred)\n", number);
    else if (errno == EINVAL)  // not in all c99 implementations - gcc OK
        printf(" number : %lu  invalid  (base contains unsupported value)\n", number);
    else if (errno != 0 && number == 0)
        printf(" number : %lu  invalid  (unspecified error occurred)\n", number);
    else if (errno == 0 && nptr && !*endptr)
        printf(" number : %lu    valid  (and represents all characters read)\n", number);
    else if (errno == 0 && nptr && *endptr != 0)
        printf(" number : %lu    valid  (but additional characters remain)\n", number);
*/