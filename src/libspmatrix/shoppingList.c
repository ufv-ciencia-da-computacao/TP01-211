#include "./include/shoppingList.h"

static int shoppingListCreate(ShoppingList *slist, Shopping shop) {
  (*slist) = (ShoppingList) malloc(sizeof(struct shoppingList_t));
  (*slist)->shop = shop;
  (*slist)->next = NULL;
  return 0;
}

int shoppingListFree(ShoppingList *slist) {
  ShoppingList iterator = *slist;
  ShoppingList prev; 

  while (iterator != NULL) {
    prev = iterator;
    iterator = iterator->next; 
    free(prev);  
  }

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
        shoppingSetQttProducts( &(iterator->shop), 
                                shoppingGetQttProducts(iterator->shop) + 
                                shoppingGetQttProducts(new->shop)
                              );
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

int shoppingListConcat(ShoppingList *dest, ShoppingList orig) {
  ShoppingList iterator = orig;

  while (iterator != NULL) {
    shoppingListInsert(dest, iterator->shop);
    iterator = iterator->next;
  }

  return 0;
}

int shoppingListCountProducts(ShoppingList slist) {
  int qtt = 0;
  ShoppingList iterator = slist;
  while(iterator != NULL) {
    qtt += shoppingGetQttProducts(iterator->shop);
    iterator = iterator->next;
  }

  return qtt;
}

int shoppingListSize(ShoppingList slist) {
  int total = 0;
  ShoppingList iterator = slist;
  while (iterator != NULL) { 
    total++;
    iterator = iterator->next;
  }
  return total;
}

int shoppingListToString(ShoppingList *slist, char *str) {
  ShoppingList iterator = *slist;
  sprintf(str, "");

  char shopStr[SHOPPING_MAX_STR_LEN];

  while(iterator != NULL) {
    shoppingToString(&(iterator->shop), shopStr);
    strcat(str, shopStr);
    strcat(str, "\n");
    iterator = iterator->next;
  }

  return 0;
}
