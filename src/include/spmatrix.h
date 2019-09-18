#ifndef __SP_MATRIX_H__
#define __SP_MATRIX_H__

#include "node.h"

typedef unsigned int uint;
typedef struct {
  Node head;
  uint lin, col; 
} SpMatrix;

void spMatrixInit(SpMatrix *spMatrix, int lin, int col);
void spMatrixInsert(SpMatrix *spMatrix, int line, int col, Item value);
void spMatrixToString(SpMatrix *spMatrix);
void spMatrixFree(SpMatrix *spMatrix);

#endif