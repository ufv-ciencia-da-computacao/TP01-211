#include <stdio.h>
#include <stdbool.h>
#include "../../include/shoppingList.h"
#include "../../include/date.h"

int main() {

  ShoppingList slist;
  shoppingListInit(&slist);
  
  Shopping shop;
  Date date;
  int day, month, year, qttProducts;
  char str[512];

  while(true) {
    printf("dia mes ano qttProducts\n");
    scanf("%d %d %d %d", &day, &month, &year, &qttProducts);
    dateInit(&date, day, month, year);

    shoppingInit(&shop, date, qttProducts);
    shoppingListInsert(&slist, shop);
    shoppingListToString(&slist, str);

    printf("\nLista completa: \n");
    printf("%s\n", str);
  }

  return 0;

}
