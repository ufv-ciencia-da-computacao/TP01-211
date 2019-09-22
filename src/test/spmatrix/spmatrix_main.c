#include "../../libspmatrix/include/spmatrix.h"

int main() {
  SpMatrix matrix;
  int err;
  char *spMatrixString;

  ShoppingList slist, slist1;
  Shopping shop;
  Date date;

  shoppingListInit(&slist);
  shoppingListInit(&slist1);

  dateInit(&date, 10, 11, 2012);
  shoppingInit(&shop, date, 3);
  shoppingListInsert(&slist, shop);

  dateInit(&date, 12, 11, 2012);
  shoppingInit(&shop, date, 3);
  shoppingListInsert(&slist, shop);

  dateInit(&date, 12, 11, 2014);
  shoppingInit(&shop, date, 10);
  shoppingListInsert(&slist1, shop);

  err = spMatrixInit(&matrix, 4, 4);
 
  err = spMatrixInsert(&matrix, 1, 1, slist);
  err = spMatrixInsert(&matrix, 2, 2, slist1);

  spMatrixToString(&matrix, &spMatrixString);
  puts(spMatrixString);

  free(spMatrixString);
  
  char *str1;
  spMatrixQtdShoppingByProductToString(&matrix, &str1);
  printf("%s", str1);
  free(str1);

  err = spMatrixFree(&matrix);

  return 0;
}
