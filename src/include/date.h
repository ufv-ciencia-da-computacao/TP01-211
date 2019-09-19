#ifndef __DATE_H__
#define __DATE_H__

typedef struct date_t {
  int day;
  int month;
  int year;
} Date;

#pragma region RegionGetters
int dateGetDay(Date date);
int dateGetMonth(Date date);
int dateGetYear(Date date);
#pragma endregion RegionGetters

#pragma region RegionSetters
void dateSetDay(Date *date, int day);
void dateSetMonth(Date *date, int month);
void dateSetYear(Date *date, int year);
#pragma endregion RegionSetters

int dateInit(Date *date, int day, int month, int year);
int dateToDayOfYear(Date date);
int dayOfYearToDate(Date *date, int dayOfYear);
int verifyDate(Date date);
int isLeapYear(Date date);

#endif
