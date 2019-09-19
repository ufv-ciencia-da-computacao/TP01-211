#ifndef __SHOPPING_H__
#define __SHOPPING_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "date.h"

typedef struct shopping_t {
  Date date;
  int qttProducts;
} Shopping;

#pragma region RegionGetters
Date shoppingGetDate(Shopping shop);
int shoppingGetQttProducts(Shopping shop);
#pragma endregion RegionGetters

#pragma region RegionSetters
int shoppingSetDate(Shopping *shop, Date date);
int shoppingSetQttProducts(Shopping *shop, int qttProducts);
#pragma endregion RegionSetters

int shoppingInit(Shopping *shop, Date date, int qttProducts);
int shoppingToString(Shopping *shop, char str[]);
int shoppingVerify(Shopping shop);

#endif
