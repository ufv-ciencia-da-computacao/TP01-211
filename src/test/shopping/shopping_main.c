#include <stdio.h>
#include "../../include/shopping.h"

int main() {
  Shopping shop;
  int day, month, year, qttProducts;
  Date date;

  printf("(dia) (mes) (ano) (quantidade de produtos)\n");
  scanf("%d %d %d %d", &day, &month, &year, &qttProducts);
  
  dateInit(&date, day, month, year);
  shoppingInit(&shop, date, qttProducts);
  
  char str[128];
  shoppingToString(&shop, str);
  
  printf("%s\n", str);
  return 0;
}
