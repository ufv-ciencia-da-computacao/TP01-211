#include "../../libinterface/include/menu.h"
#define FILE_OUTPUT "./output/list/output.txt"

int main(int argc, char *argv[]) {

  SpMatrix spMatrix;
  char *strPrint;

  int err;
  int i;
  for (i = 1; i < argc; i++) {
    err = initMatrixFromFile(&spMatrix, argv[i]);
    if (!err) {
      spMatrixToString(&spMatrix, &strPrint);
      printf("%s", strPrint);
      // setOutput(FILE_OUTPUT, strPrint);      
      free(strPrint);
      spMatrixFree(&spMatrix); 
    } else {
      printf("\n\nAlgo deu errado, verifique o arquivo e tente novamente.\n\n");
    }
  }
  
  return 0;
}
