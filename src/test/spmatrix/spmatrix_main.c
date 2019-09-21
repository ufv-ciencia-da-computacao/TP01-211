#include "../../libspmatrix/include/spmatrix.h"

int main() {
  SpMatrix matrix;
  int err;
  err = spMatrixInit(&matrix, 4, 4);

  ShoppingList slist;
  shoppingListInit(&slist);
 
  err = spMatrixInsert(&matrix, 1, 1, slist);
  err = spMatrixInsert(&matrix, 2, 1, slist);
  err = spMatrixInsert(&matrix, 2, 3, slist);
  err = spMatrixInsert(&matrix, 4, 1, slist);
  err = spMatrixInsert(&matrix, 4, 3, slist);
  err = spMatrixInsert(&matrix, 4, 4, slist);

  // spMatrixToString(&matrix);

  err = spMatrixFree(&matrix);

  return 0;
}
