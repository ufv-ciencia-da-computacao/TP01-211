#include "../include/shopping.h"

static int dateToDayOfYear(int *dayOfYear, int day, int month, int year);
static int dayOfYearToDate(int dayOfYear, int *day, int *month, int year);
static int verifyDate(int day, int month, int year);
static int isLeapYear(int year);
static int verifyQttProducts(int qttProducts);

static int dateToDayOfYear(int *dayOfYear, int day, int month, int year) {
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

static int dayOfYearToDate(int dayOfYear, int *day, int *month, int year) {
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

static int verifyDate(int day, int month, int year) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(isLeapYear(year)) daysInMonth[1] = 29;
  if(!(0 < year && year <= 9999)) return 0;
  if(!(1 <= month && month <= 12)) return 0;
  if(!(1 <= day && day <= daysInMonth[month-1])) return 0;
  return 1;
}

static int isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

static int verifyQttProducts(int qttProducts) {
  return (qttProducts > 0);
}

int shoppingInit(Shopping *shop, int day, int month,  int year, int qttProducts) {
  if(!verifyDate(day, month, year) || !verifyQttProducts(qttProducts)) {
    return 1;
  }
  dateToDayOfYear(&(shop->dayOfYear), day, month-1, year);
  shop->year = year;
  shop->qttProducts = qttProducts;
  return 0;
}

int shoppingToString(Shopping shop, char str[]) {
  int day;
  int month;
  dayOfYearToDate(shop.dayOfYear, &day, &month, shop.year);
  sprintf(str, "%.2d/%.2d/%.4d\t%d\n", day, month, shop.year, shop.qttProducts); 
  return 0;
}
