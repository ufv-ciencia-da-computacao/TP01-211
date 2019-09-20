#include "./include/menu.h"

int initMatrixFromFile(SpMatrix *spMatrix, char *filename) {
  FILE *file = fopen(filename, "r+");

  if (file == NULL) return 1;

  int lineMAX, colMAX;
  int line, col;
  Item value;
  int countLines = 0;

  while (!feof(file)) {
    if (countLines == 0) {
      fscanf(file, "%d %d", lineMAX, colMAX);
      spMatrixInit(&spMatrix, lineMAX, colMAX);
    } else {
      fscanf(file, "%d, %d, %lf", line, col, value);
      spMatrixInsert(&spMatrix, line, col, value);
    }
    countLines++;
  }  

  fclose(file);
}