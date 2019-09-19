#ifndef __SP_MATRIX_H__
#define __SP_MATRIX_H__

#include "node.h"
#include <string.h>
#include <stdio.h>

typedef struct {
  Node head;
  int lin, col; 
} SpMatrix;

void spMatrixInit(SpMatrix *spMatrix, int lin, int col);
void spMatrixInsert(SpMatrix *spMatrix, int line, int col, Item value);
void spMatrixToString(SpMatrix *spMatrix /*, char str[]*/);
void spMatrixFree(SpMatrix *spMatrix);

#endif