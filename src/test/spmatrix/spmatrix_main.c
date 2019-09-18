#include "../../include/spmatrix.h"

int main() {
  SpMatrix matrix;

  spMatrixInit(&matrix, 4, 4);
  spMatrixInsert(&matrix, 1, 1, 50);
  spMatrixInsert(&matrix, 2, 1, 10);
  spMatrixInsert(&matrix, 2, 3, 20);
  spMatrixInsert(&matrix, 4, 1, -30);
  spMatrixInsert(&matrix, 4, 3, -60);
  spMatrixInsert(&matrix, 4, 4, -5.0);

  spMatrixToString(&matrix);

  // spMatrixFree(&matrix);
}