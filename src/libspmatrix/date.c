#include "../include/date.h"

int dateToDayOfYear(int *dayOfYear, int day, int month, int year) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(isLeapYear(year)) daysInMonth[1] = 29;

  int i;
  int daysPassed = 0;
  for(i=0; i<month; i++) {
    daysPassed += daysInMonth[i];
  }
  *dayOfYear = daysPassed + day;
  return 0;
}

int dayOfYearToDate(int dayOfYear, int *day, int *month, int year) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(isLeapYear(year)) daysInMonth[1] = 29;

  int i;
  int totalDays = 0;
  for(i=0; i<12; i++) {
    if(dayOfYear <= totalDays + daysInMonth[i]) {
      *day = dayOfYear - totalDays;
      *month = i+1;
      break;
    }
    totalDays += daysInMonth[i];
  }

  return 0;
}

int verifyDate(int day, int month, int year) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(isLeapYear(year)) daysInMonth[1] = 29;
  if(!(0 < year && year <= 9999)) return 0;
  if(!(1 <= month && month <= 12)) return 0;
  if(!(1 <= day && day <= daysInMonth[month-1])) return 0;
  return 1;
}

int isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}