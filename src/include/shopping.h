#ifndef __SHOPPING_H__
#define __SHOPPING_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct shopping_t {
  int dayOfYear;
  int year;
  int qttProducts;
} Shopping;

int shoppingInit(Shopping *shop, int day, int month,  int year, int qttProducts);
int shoppingToString(Shopping *shop, char string[]);

#endif
