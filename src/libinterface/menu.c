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

  while (!feof(file)) {
    if (countLines == 0) {
      fscanf(file, "%d, %d", &lineMAX, &colMAX);
      if(spMatrixInit(spMatrix, lineMAX, colMAX)) return 1;
      countLines = 1;
    } else {
      if(countItems == 0) {
        fscanf(file, "%d %d ", &line, &col);
        if (spMatrixColOutOfBounds(spMatrix, col) || spMatrixLinOutOfBounds(spMatrix, line)) {
          spMatrixFree(spMatrix);
          return 1;
        }
        shoppingListInit(&slist);
        countItems = 1;
      } else {
        do {
          fscanf(file, "%d/%d/%d %d%c", &day, &month, &year, &qttProducts, &detectEnd);
          
          dateInit(&date, day, month, year);
          if(!dateVerify(date)) {
            shoppingListFree(&slist);
            spMatrixFree(spMatrix);
            return 1;
          }
          
          shoppingInit(&shop, date, qttProducts);
          if(!shoppingVerify(shop)) {
            shoppingListFree(&slist);
            spMatrixFree(spMatrix);
            return 1;
          }
          
          shoppingListInsert(&slist, shop);
        } while(detectEnd != '\n' && detectEnd != EOF && detectEnd != 0);
        countItems = 0;
        spMatrixInsert(spMatrix, line, col, slist);
      } 
    }
  }  

  fclose(file);

  return 0;
}

int setOutput(char* filename, char* str) {
  FILE *file;

  file = fopen(filename, "w");

  if (file == NULL) {
    return 1;
  }

  fprintf(file, "%s", str);

  fclose(file);
  
  return 0;
}

int showMatrix(SpMatrix *spMatrix) {
  char *spMatrixString;
  spMatrixToString(spMatrix, &spMatrixString);
  puts(spMatrixString);
  free(spMatrixString);
  return 0;
}

int showShopByClient(SpMatrix *spMatrix) {
  char *str;
  spMatrixQtdShoppingByClientToString(spMatrix, &str);
  puts(str);
  free(str);
  return 0;
}

int showShopByProduct(SpMatrix *spMatrix) {
  char *str;
  spMatrixQtdShoppingByProductToString(spMatrix, &str);
  puts(str);
  free(str);
  return 0;
}
