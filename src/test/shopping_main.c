#include <stdio.h>
#include "../include/shopping.h"


int main() {
  
  Shopping shop;

  int day, month;
  scanf("%d %d", &day, &month);

  shoppingInit(&shop, day, month, 2020, 100);
  // printf("%d %d %d\n", shop.year, shop.dayOfYear, shop.qttProducts);
  char str[100];

  shoppingToString(&shop, str);

  //printf("data:     \tquantidade\n");
  printf("%s", str);

  return 0;
}
