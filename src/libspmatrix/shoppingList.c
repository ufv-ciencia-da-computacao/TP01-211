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
  ShoppingList prev = NULL;
  ShoppingList next = NULL;
  ShoppingList new;
  shoppingListCreate(&new, shop);

  if(*slist == NULL) {
    *slist = new;
    return 0;
  }

  while(iterator != NULL) {
    next = iterator->next;
    
    if(dateGetYear(shoppingGetDate(new->shop)) > dateGetYear(shoppingGetDate(iterator->shop))) {
      if(next == NULL) {
        iterator->next = new;
        break;
      } else if(dateGetYear(shoppingGetDate(new->shop)) < dateGetYear(shoppingGetDate(next->shop))) {
        new->next = next;
        iterator->next = new;
        break;
      }
    }

    if(dateGetYear(shoppingGetDate(new->shop)) == dateGetYear(shoppingGetDate(iterator->shop))) {
      if(dateToDayOfYear(shoppingGetDate(new->shop)) > dateToDayOfYear(shoppingGetDate(iterator->shop))) {
        if(next == NULL) {
          iterator->next = new;
          break;
        } else if(dateToDayOfYear(shoppingGetDate(new->shop)) < dateToDayOfYear(shoppingGetDate(next->shop))) {
          new->next = next;
          iterator->next = new;
          break;
        }
      }

      if(dateToDayOfYear(shoppingGetDate(new->shop)) == dateToDayOfYear(shoppingGetDate(iterator->shop))) {
        (iterator->shop).qttProducts += (new->shop).qttProducts;
        shoppingListFree(&new);
        break;
      }

      if(dateToDayOfYear(shoppingGetDate(new->shop)) < dateToDayOfYear(shoppingGetDate(iterator->shop))) {
        new->next = iterator;
        if(prev == NULL) {
          *slist = new;
        } else {
          prev->next = new;
        }
        break;
      }
    }

    if(dateGetYear(shoppingGetDate(new->shop)) < dateGetYear(shoppingGetDate(iterator->shop))) {
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
    shoppingToString(&(iterator->shop), shopStr);
    strcat(str, shopStr);
    strcat(str, "\n");
    iterator = iterator->next;
  }

  return 0;
}
