#include "../include/shoppingList.h"

static int shoppingListCreate(ShoppingList *slist, Shopping shop) {
  (*slist) = (ShoppingList) malloc(sizeof(struct shoppingList_t));
  (*slist)->shop = shop;
  (*slist)->next = NULL;
  return 0;
}

static int shoppingListFree(ShoppingList *slist) {
  if(*slist == NULL) {
    return 1;
  }
  free(*slist);
  *slist = NULL;
  return 0;
}

int shoppingListInit(ShoppingList *slist) {
  *slist = NULL;
}

int shoppingListInsert(ShoppingList *slist, Shopping shop) {
  ShoppingList iterator = *slist;
  ShoppingList prev, next;
  ShoppingList new;
  shoppingListCreate(&new, shop);

  if(*slist == NULL) {
    *slist = new;
    return 0;
  }

  while(iterator != NULL) {
    next = iterator->next;
    
    if((new->shop).year > (iterator->shop).year) {
      if(next == NULL) {
        iterator->next = new;
        break;
      } else if((new->shop).year < (next->shop).year) {
        new->next = next;
        iterator->next = new;
        break;
      }
    }

    if((new->shop).year == (iterator->shop).year) {
      if((new->shop).dayOfYear > (iterator->shop).dayOfYear) {
        if(next == NULL) {
          iterator->next = new;
          break;
        } else if((new->shop).dayOfYear < (next->shop).dayOfYear) {
          new->next = next;
          iterator->next = new;
          break;
        }
      }

      if((new->shop).dayOfYear == (iterator->shop).dayOfYear) {
        (iterator->shop).qttProducts += (new->shop).qttProducts;
        shoppingListFree(&new);
        break;
      }

      if((new->shop).dayOfYear < (iterator->shop).dayOfYear) {
        new->next = iterator;
        prev->next = new;
        break;
      }
    }

    if((new->shop).year < (iterator->shop).year) {
      new->next = iterator;
      *slist = new;
      break;
    }

    prev = iterator;
    iterator = next;
  }

  return 0;
}

int shoppingListToString(ShoppingList *slist, char str[]) {
  ShoppingList iterator = *slist;

  sprintf(str, "");

  char shopStr[128];

  while(iterator != NULL) {
    shoppingToString(iterator->shop, shopStr);
    strcat(str, shopStr);
    iterator = iterator->next;
  }

  return 0;
}
