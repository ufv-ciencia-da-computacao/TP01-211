#include "./include/menu.h"

int initMatrixFromFile(SpMatrix *spMatrix, char *filename) {
  FILE *file = NULL;
  file = fopen(filename, "r+");

  if (file == NULL) {
    return 1;
  }

  Date date;
  int day, month, year;

  Shopping shop;
  int qttProducts;
  
  int lineMAX, colMAX;
  int line, col;
  
  ShoppingList slist;
  
  char detectEnd;
  int countLines = 0, countItems = 0;
  int err = 0;


  while (!feof(file)) {
    if (countLines == 0) {
      fscanf(file, "%d, %d", &lineMAX, &colMAX);
      err = spMatrixInit(spMatrix, lineMAX, colMAX);
      if(err) return 1;
      countLines = 1;
    } else {
      if(countItems == 0) {
        fscanf(file, "%d %d ", &line, &col);
        shoppingListInit(&slist);
        countItems = 1;
      } else {
        do {
          fscanf(file, "%d/%d/%d %d%c", &day, &month, &year, &qttProducts, &detectEnd);
          dateInit(&date, day, month, year);
          if(!dateVerify(date)) return 1;
          shoppingInit(&shop, date, qttProducts);
          if(!shoppingVerify(shop)) return 1;
          shoppingListInsert(&slist, shop);
        } while(detectEnd != '\n' && detectEnd != EOF && detectEnd != 0);
        countItems = 0;

        if (!spMatrixColOutOfBounds(spMatrix, col) && !spMatrixLinOutOfBounds(spMatrix, line)) {
          err = spMatrixInsert(spMatrix, line, col, slist);
          if(err) return 1;
        } else {
          return 1;
        }  
      } 
    }
  }  

  fclose(file);

  return 0;
}
