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
  while(iterator != NULL) {
    next = iterator->next;

    
    if(new->year > iterator->year) {
      if(next == NULL) {
        iterator->next = new;
        break;
      } else if(new->year < next->year) {
        new->next = next;
        iterator->next = new;
        break;
      }
    }

    if(new->year == iterator->year) {
      if(new->dayOfYear > iterator->dayOfYear) {
        if(next == NULL) {
          iterator->next = new;
          break;
        } else if(new->dayOfYear < next->dayOfYear) {
          new->next = next;
          iterator->next = new;
          break;
        }
      }

      if(new->dayOfYear == iterator->dayOfYear) {
        (iterator->shop).qttProducts += (new->shop).qttProducts;
        shoppingListFree(&new);
        break;
      }
    }

    if(new->year < iterator->year) {
      new->next = iterator;
      *slist = new;
      break;
    }

    prev = iterator;
    iterator = next;
  }

  return 0;
}

