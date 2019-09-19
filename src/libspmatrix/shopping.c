#include "../include/shopping.h"

static int verifyQttProducts(int qttProducts);

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
