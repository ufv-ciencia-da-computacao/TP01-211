#include "../include/shopping.h"

Date shoppingGetDate(Shopping shop) {
  return shop.date;
}

int shoppingSetDate(Shopping *shop, Date date) {
  shop->date = date;
  return 0;
}

int shoppingInit(Shopping *shop, Date date, int qttProducts) {
  shop->date = date;
  shop->qttProducts = qttProducts;
  return 0;
}

int shoppingToString(Shopping *shop, char str[]) {
  sprintf(str, "%.2d/%.2d/%.4d\t%d\n", dateGetDay(shop->date), dateGetMonth(shop->date), 
  dateGetYear(shop->date), shop->qttProducts);
  return 0;
}
