#ifndef __SHOPPING_LIST_H__
#define __SHOPPING_LIST_H__

#include "shopping.h"
#include <stdio.h>
#include <string.h>

typedef struct shoppingList_t * ShoppingList;
struct shoppingList_t {
  Shopping shop;
  ShoppingList next;
};

int shoppingListInit(ShoppingList *slist);
int shoppingListInsert(ShoppingList *slist, Shopping shop);
int shoppingListToString(ShoppingList *slist, char str[]);
int shoppingListFree(ShoppingList *slist);
#endif
