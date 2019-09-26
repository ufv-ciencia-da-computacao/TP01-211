#include "libinterface/include/menu.h"
#include "libspmatrix/include/spmatrix.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef linux
  #include <stdio_ext.h>
#endif


int main() {

  SpMatrix matrix;
  int opt, exit = 0, init = 0;
  char arg[64];

  while (!exit) {
    
    #ifdef _WIN32
      system("cls");
    #else
      system("clear");
    #endif

    printf("\nMENU\n1- Cria matriz\n2- Mostra matriz\n3- Compras por cliente\n4- Compras por produto\n0- sair\nDigite o numero da opcao desejada: ");
    scanf("%d", &opt);
    printf("\n");

    switch (opt) {
    
    case 0: 
      exit = 1;
      break;

    case 1:
      if(init) spMatrixFree(&matrix);
      printf("\nDigite o nome do arquivo: ");
      scanf("%s", arg);
      if(initMatrixFromFile(&matrix, arg)) {
        printf("\nAlgo deu errado, por favor verifique o arquivo de entrada.\n");
        init = 0;
      } else {
        init = 1;
      }
      break;

    case 2:
      if(init) showMatrix(&matrix);
      break;

    case 3:
      if(init) showShopByClient(&matrix);
      break;

    case 4:
      if(init) showShopByProduct(&matrix);
      break;
    
    default:
      printf("\nDigite um valor valido!!!\n");
      break;
    }

    if(!exit) {
      printf("\nPressione ENTER para continuar...");
        #ifdef _WIN32
          fflush(stdin);
        #else
          __fpurge(stdin);
        #endif
      getchar();
    }
  }

  if(init) spMatrixFree(&matrix);

  return 0;
}
