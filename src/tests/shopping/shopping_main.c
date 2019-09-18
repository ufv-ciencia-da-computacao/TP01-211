#include <stdio.h>
#include "../../include/shopping.h"


int main() {
  Shopping shop;
  int day, month, year, qttProducts, error;
  printf("(dia) (mes) (ano) (quantidade de produtos)\n");
  scanf("%d %d %d %d", &day, &month, &year, &qttProducts);
  error = shoppingInit(&shop, day, month, year, qttProducts);
  if(!error) {
    char str[128];
    shoppingToString(shop, str);
    printf("%s", str);
  } 
  return 0;
}
