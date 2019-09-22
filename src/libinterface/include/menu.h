#ifndef __MENU_H__
#define __MENU_H__

#include "../../libspmatrix/include/spmatrix.h"

int initMatrixFromFile(SpMatrix *spMatrix, char *filename);
int setOutput(char* filename, char* str);
int showMatrix(SpMatrix *spMatrix);
int showShopByClient(SpMatrix *spMatrix);
int showShopByProduct(SpMatrix *spMatrix);

#endif
