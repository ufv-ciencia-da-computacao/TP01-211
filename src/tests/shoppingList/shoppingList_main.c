#include <stdio.h>
#include <stdbool.h>
#include "../../include/shoppingList.h"

int main() {

  ShoppingList slist;
  shoppingListInit(&slist);
  
  Shopping shop;
  int day, month, year, qttProducts;
  char str[512];

  while(true) {
    printf("dia mes ano qttProducts\n");
    scanf("%d %d %d %d", &day, &month, &year, &qttProducts);

    shoppingInit(&shop, day, month, year, qttProducts);
    shoppingListInsert(&slist, shop);
    shoppingListToString(&slist, str);

    printf("\nLista completa: \n");
    printf("%s\n", str);
  }

  return 0;

}
