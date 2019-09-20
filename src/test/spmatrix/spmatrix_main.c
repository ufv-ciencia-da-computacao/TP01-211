#include "../../include/spmatrix.h"

int main() {
  SpMatrix matrix;
  int err;
  err = spMatrixInit(&matrix, 4, 4);
 
  err = spMatrixInsert(&matrix, 1, 1, 50);
  err = spMatrixInsert(&matrix, 2, 1, 10);
  err = spMatrixInsert(&matrix, 2, 3, 20);
  err = spMatrixInsert(&matrix, 4, 1, -30);
  err = spMatrixInsert(&matrix, 4, 3, -60);
  err = spMatrixInsert(&matrix, 4, 4, -5.0);

  spMatrixToString(&matrix);

  err = spMatrixFree(&matrix);

  return 0;
}