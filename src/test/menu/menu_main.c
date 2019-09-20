#include "../../libinterface/include/menu.h"

int main(int argc, char *argv[]) {

  SpMatrix spMatrix;

  int err;

  for (int i = 1; i < argc; i++) {
    err = initMatrixFromFile(&spMatrix, argv[i]);
    if (!err) {
      spMatrixToString(&spMatrix);
      spMatrixFree(&spMatrix); 
    }
  }
  
  return 0;
}