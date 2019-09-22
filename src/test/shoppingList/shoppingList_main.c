#include <stdio.h>
#include <stdbool.h>
#include "../../libspmatrix/include/shoppingList.h"

int main() {
  ShoppingList slist;
  shoppingListInit(&slist);

  ShoppingList slist1;
  shoppingListInit(&slist1);
  
  Shopping shop;
  Date date;
  char str[512];

  dateInit(&date, 10, 11, 2012);
  shoppingInit(&shop, date, 3);
  shoppingListInsert(&slist, shop);

  dateInit(&date, 10, 10, 2011);
  shoppingInit(&shop, date, 4);
  shoppingListInsert(&slist1, shop);
  dateInit(&date, 10, 12, 2012);
  shoppingInit(&shop, date, 5);
  shoppingListInsert(&slist1, shop);

  printf("slist: \n");
  shoppingListToString(&slist, str);
  printf("%s\n\n", str);

  printf("slist1: \n");
  shoppingListToString(&slist1, str);
  printf("%s\n\n", str);

  shoppingListConcat(&slist, slist1);
  shoppingListFree(&slist1);

  shoppingListToString(&slist, str);
  printf("items after concat: %d\n\n%s\n\n", shoppingListCountProducts(&slist), str);
  shoppingListFree(&slist);

  return 0;

}
