#ifndef __DATE_H__
#define __DATE_H__

typedef struct date_t {
  int day;
  int month;
  int year;
} Date;

int dateToDayOfYear(int *dayOfYear, int day, int month, int year);
int dayOfYearToDate(int dayOfYear, int *day, int *month, int year);
int verifyDate(int day, int month, int year);
int isLeapYear(int year);

#endif