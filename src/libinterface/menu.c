#include "./include/menu.h"

int initMatrixFromFile(SpMatrix *spMatrix, char *filename) {
  FILE *file = fopen(filename, "r+");

  if (file == NULL) {
    printf("s");
    return 1;
  }

  int lineMAX, colMAX;
  int line, col;
  Item value;
  int countLines = 0;
  int err;

  while (!feof(file)) {
    if (countLines == 0) {
      fscanf(file, "%d, %d", &lineMAX, &colMAX);
      err = spMatrixInit(spMatrix, lineMAX, colMAX);
    } else {
      fscanf(file, "%d, %d, %lf", &line, &col, &value);
      if (!spMatrixColOutOfBounds(spMatrix, col) && !spMatrixLinOutOfBounds(spMatrix, line)) {
        err = spMatrixInsert(spMatrix, line, col, value);
      } else{ 
        // LOG file
      }      
    }
    countLines++;
  }  

  return 0;

  fclose(file);
}