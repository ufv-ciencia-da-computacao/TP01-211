#include "./include/shopping.h"

#pragma region RegionGetters
Date shoppingGetDate(Shopping shop) {
  return shop.date;
}

int shoppingGetQttProducts(Shopping shop) {
  return shop.qttProducts;
}
#pragma endregion RegionGetters

#pragma region RegionSetters
int shoppingSetQttProducts(Shopping *shop, int qttProducts) {
  shop->qttProducts = qttProducts;
  return 0;
}

int shoppingSetDate(Shopping *shop, Date date) {
  shop->date = date;
  return 0;
}
#pragma endregion RegionSetters

int shoppingInit(Shopping *shop, Date date, int qttProducts) {
  shop->date = date;
  shop->qttProducts = qttProducts;
  return 0;
}

int shoppingToString(Shopping *shop, char str[]) {
  sprintf(str, "%.2d/%.2d/%.4d\t%d", dateGetDay(shop->date), dateGetMonth(shop->date), 
  dateGetYear(shop->date), shop->qttProducts);
  return 0;
}

int shoppingVerify(Shopping shop) {
  return (shop.qttProducts > 0) && dateVerify(shop.date);
}
