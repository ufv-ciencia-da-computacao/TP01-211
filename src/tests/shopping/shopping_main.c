#include <stdio.h>
#include "../../include/shopping.h"


int main() {
  Shopping shop;
  int day, month;
  scanf("%d %d", &day, &month);
  shoppingInit(&shop, day, month, 2020, 100);
  char str[128];
  shoppingToString(shop, str);
  printf("%s", str);
  return 0;
}
