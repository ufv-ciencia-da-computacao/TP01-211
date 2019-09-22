#include "./include/date.h"

static int isLeapYear(Date date) {
  return (date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0);
}

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
  for(i=0; i<date.month; i++) {
    daysPassed += daysInMonth[i];
  }
  return daysPassed + date.day;
}

int dateFromDayOfYear(Date *date, int dayOfYear) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(isLeapYear(*date)) daysInMonth[1] = 29;

  int i;
  int totalDays = 0;
  for(i=0; i<12; i++) {
    if(dayOfYear <= totalDays + daysInMonth[i]) {
      date->day = dayOfYear - totalDays;
      date->month = i + 1;
      break;
    }
    totalDays += daysInMonth[i];
  }

  return 0;
}

int dateVerify(Date date) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(isLeapYear(date)) daysInMonth[1] = 29;
  if(!(1 <= date.year && date.year <= 9999)) return 0;
  if(!(1 <= date.month && date.month <= 12)) return 0;
  if(!(1 <= date.day && date.day <= daysInMonth[date.month-1])) return 0;
  return 1;
}

int dateToString(Date *date, char *str) {
  sprintf(str, "%.2d/%.2d/%.4d", date->day, date->month, date->year);
  return 0;
}
