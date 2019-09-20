#ifndef __SPMATRIX_H__
#define __SPMATRIX_H__

#include "node.h"
#include <string.h>
#include <stdio.h>

typedef struct spmatrix_t {
  Node head;
  int lin, col; 
} SpMatrix;

int spMatrixInit(SpMatrix *spMatrix, int lin, int col);
int spMatrixInsert(SpMatrix *spMatrix, int line, int col, Item value);
void spMatrixToString(SpMatrix *spMatrix /*, char str[]*/);
int spMatrixFree(SpMatrix *spMatrix);

int spMatrixLinOutOfBounds(SpMatrix *spMatrix, int line);
int spMatrixColOutOfBounds(SpMatrix *spMatrix, int col);

#endif