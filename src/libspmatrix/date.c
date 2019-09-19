#include "../include/date.h"

#pragma region RegionGetters
int dateGetDay(Date date) {
  return date.day;
}

int dateGetMonth(Date date) {
  return date.month;
}

int dateGetYear(Date date) {
  return date.year;
}
#pragma endregion RegionGetters

#pragma region RegionSetters
void dateSetDay(Date *date, int day) {
  date->day = day;
}

void dateSetMonth(Date *date, int month) {
  date->month = month;
}

void dateSetYear(Date *date, int year) {
  date->year = year;
}
#pragma endregion RegionSetters

int dateInit(Date *date, int day, int month, int year) {
  date->day = day;
  date->month = month;
  date->year = year;
}

int dateToDayOfYear(Date date) { 
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(isLeapYear(date)) daysInMonth[1] = 29;

  int i;
  int daysPassed = 0;
  for(i=0; i<dateGetMonth(date); i++) {
    daysPassed += daysInMonth[i];
  }
  return daysPassed + dateGetDay(date);
}

int dayOfYearToDate(Date *date, int dayOfYear) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(isLeapYear(*date)) daysInMonth[1] = 29;

  int i;
  int totalDays = 0;
  for(i=0; i<12; i++) {
    if(dayOfYear <= totalDays + daysInMonth[i]) {
      dateSetDay(date, dayOfYear - totalDays);
      dateSetMonth(date, i+1);
      break;
    }
    totalDays += daysInMonth[i];
  }

  return 0;
}

int verifyDate(Date date) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(isLeapYear(date)) daysInMonth[1] = 29;
  if(!(1 <= dateGetYear(date) && dateGetYear(date) <= 9999)) return 0;
  if(!(1 <= dateGetMonth(date) && dateGetMonth(date) <= 12)) return 0;
  if(!(1 <= dateGetDay(date) && dateGetDay(date) <= daysInMonth[dateGetMonth(date)-1])) return 0;
  return 1;
}

int isLeapYear(Date date) {
  return (dateGetYear(date) % 4 == 0 && dateGetYear(date) % 100 != 0 || dateGetYear(date) % 400 == 0);
}
