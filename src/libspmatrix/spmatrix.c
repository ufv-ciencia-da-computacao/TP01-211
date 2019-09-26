#include "./include/spmatrix.h"

static void spMatrixConstructColumn(SpMatrix *spMatrix) {
  Node auxNode;
  Node iterator = spMatrix->head;
  int i;
  for (i = 2; i <= spMatrix->lin+1; i++) {
    nodeInit(&auxNode, (-1) * i, -1, NULL);
    nodeSetNextBelow(&iterator, auxNode);
    iterator = nodeGetNextBelow(iterator);
  }
  nodeSetNextBelow(&iterator, spMatrix->head);
}

static void spMatrixConstructLine(SpMatrix *spMatrix) {
  Node auxNode;
  Node iterator = spMatrix->head;
  int i;
  for (i = 2; i <= spMatrix->col+1; i++) {
    nodeInit(&auxNode, -1, (-1) * i, NULL);
    nodeSetNextRight(&iterator, auxNode);
    iterator = nodeGetNextRight(iterator);
  }  
  nodeSetNextRight(&iterator, spMatrix->head);
}

static void spMatrixDiscoverFirstCol(SpMatrix *spMatrix, Node *firstCol, int col) {
  Node iterator = spMatrix->head;
  
  do {
    if (abs(nodeGetColumn(iterator))-1 == col) {
      (*firstCol) = iterator;
      break;
    }
    iterator = nodeGetNextRight(iterator); 
  } while (nodeGetColumn(iterator) != -1);
}

static void spMatrixDiscoverFirstLine(SpMatrix *spMatrix, Node *firstLine, int line) {
  Node iterator = spMatrix->head;

  do {
    if (abs(nodeGetLine(iterator))-1 == line) {
      (*firstLine) = iterator;
      break;
    }
    iterator = nodeGetNextBelow(iterator); 
  } while(nodeGetLine(iterator) != -1);
}

static void spMatrixInsertCol(SpMatrix *spMatrix, Node *createdNode, int col) {
  Node iterator;
  Node prev, next;

  Node auxFirstCol;
  spMatrixDiscoverFirstCol(spMatrix, &auxFirstCol, col);

  iterator = auxFirstCol;

  while(true) {
    next = nodeGetNextBelow(iterator);

    if(nodeGetLine(iterator) > nodeGetLine(*createdNode)) {
      nodeSetNextBelow(&prev, *createdNode);
      nodeSetNextBelow(createdNode, iterator);
      break;
    }
    
    if(nodeGetLine(iterator) == nodeGetLine(*createdNode)) {
      nodeValueConcat(&iterator, *createdNode);
      nodeFree(createdNode);
      (*createdNode) = iterator;
      break;
    }

    if(nodeGetLine(next) == nodeGetLine(auxFirstCol)) {
      nodeSetNextBelow(&iterator, *createdNode);
      nodeSetNextBelow(createdNode, next);
      break;
    }

    prev = iterator;
    iterator = next;
  }
}

static void spMatrixInsertLine(SpMatrix *spMatrix, Node *createdNode, int line) {
  Node iterator;
  Node prev, next;

  Node auxFirstLine;
  spMatrixDiscoverFirstLine(spMatrix, &auxFirstLine, line);
  
  iterator = auxFirstLine;

  while (true) {
    next = nodeGetNextRight(iterator);
    if(nodeGetColumn(iterator) > nodeGetColumn(*createdNode)) {
      nodeSetNextRight(&prev, *createdNode);
      nodeSetNextRight(createdNode, iterator);
      break;
    }

    if(nodeGetColumn(iterator) == nodeGetColumn(*createdNode)) {
      /*
        Process already done on spMatrixInsertCol, cannot free node twice.
      */
      break;
    }

    if (nodeGetColumn(next) == nodeGetColumn(auxFirstLine)) {
      nodeSetNextRight(&iterator, *createdNode);
      nodeSetNextRight(createdNode, next);
      break;
    }

    prev = iterator;
    iterator = next;
  }
}

static int spMatrixSize(SpMatrix *spMatrix) {
  Node iterator = spMatrix->head;
  iterator = nodeGetNextBelow(iterator);
  iterator = nodeGetNextRight(iterator);

  int spMatrixSize=0;

  do {
    if (nodeGetLine(iterator) < 0) {
      iterator = nodeGetNextBelow(iterator);
    }

    Item slist = nodeGetItem(iterator);
    spMatrixSize += shoppingListSize(&slist);

    iterator = nodeGetNextRight(iterator);

  } while (nodeGetNextBelow(iterator) != spMatrix->head);
  
  
  return spMatrixSize;
} 

static int spMatrixQtdShoppingByProduct(SpMatrix *spMatrix, int **vector) {
  Node iterator = spMatrix->head;
  iterator = nodeGetNextRight(iterator);
  Node firstCol;

  *vector = (int*) malloc((spMatrix->col+1) * sizeof(int));

  int i = 0;
  (*vector)[i] = 0;
  
  do {
    if (iterator->line < 0) {
      firstCol = iterator;
    }
    
    iterator = nodeGetNextBelow(iterator);
  
    if (iterator == firstCol) {
      iterator = nodeGetNextRight(iterator);
      i++;
      (*vector)[i] = 0;
    } else {
      Item sList = nodeGetItem(iterator);
      (*vector)[i] += shoppingListCountProducts(&sList);
    }
    
  } while (iterator != spMatrix->head);

}

static int spMatrixQtdShoppingByClient(SpMatrix *spMatrix, int **vector) {
  Node iterator = spMatrix->head;
  iterator = nodeGetNextBelow(iterator);
  Node firstLine;

  *vector = (int*) malloc((spMatrix->lin+1) * sizeof(int));
  int i = 0;
  (*vector)[i] = 0;
  do {
    if (nodeGetLine(iterator) < 0) {
      firstLine = iterator;
    }
    
    iterator = nodeGetNextRight(iterator);
  
    if (iterator == firstLine) {
      iterator = nodeGetNextBelow(iterator);
      i++;
      (*vector)[i] = 0;
    } else {
      Item sList = nodeGetItem(iterator);
      (*vector)[i] += shoppingListSize(&sList);
    }
    
  } while (iterator != spMatrix->head);
}

int spMatrixQtdShoppingByClientToString(SpMatrix *spMatrix, char **strArg) {
  int *vector;
  int i;
  spMatrixQtdShoppingByClient(spMatrix, &vector);  

  *strArg = (char*) malloc (spMatrix->lin * DESCRIPTION_SIZE * sizeof(char));
  (*strArg)[0] = '\0';
  char strTemp[DESCRIPTION_SIZE];
  for (i = 0; i < spMatrix->lin; i++) {
    sprintf(strTemp, "Cliente %d comprou %d vezes\n", i+1, vector[i]);
    strcat(*strArg, strTemp);
  }

  free(vector);
}

int spMatrixQtdShoppingByProductToString(SpMatrix *spMatrix, char **str) {
  int *vector;
  int i;
  spMatrixQtdShoppingByProduct(spMatrix, &vector);

  *str = (char*) malloc (spMatrix->col * DESCRIPTION_SIZE * sizeof(char));
  (*str)[0] = '\0';
  char strTemp[DESCRIPTION_SIZE];

  for (i = 0; i < spMatrix->col; i++) {
    sprintf(strTemp, "Produto %d foi comprado %d vezes\n", i+1, vector[i]);
    strcat(*str, strTemp);
  }
  free(vector);
}

int spMatrixInit(SpMatrix *spMatrix, int lin, int col) {
  if(lin <= 0 || col <= 0) {
    return 1;
  }
  nodeInit(&spMatrix->head, -1, -1, 0);
  spMatrix->lin = lin;
  spMatrix->col = col;
  spMatrixConstructLine(spMatrix);
  spMatrixConstructColumn(spMatrix);
  
  return 0;
}

int spMatrixInsert(SpMatrix *spMatrix, int line, int col, Item value) {
  Node createdNode;
  nodeInit(&createdNode, line, col, value);

  spMatrixInsertCol(spMatrix, &createdNode, col);
  spMatrixInsertLine(spMatrix, &createdNode, line); 

  return 0;
}

void spMatrixToString(SpMatrix *spMatrix, char** spMatrixStr) {
  Node iterator = spMatrix->head;

  *spMatrixStr = (char *) malloc ((spMatrixSize(spMatrix) * SHOPPING_MAX_STR_LEN) + (DESCRIPTION_SIZE * sizeof(char)));
  (*spMatrixStr)[0] = '\0';

  int i, j, bought = 0;
  for(i=1; i <= spMatrix->lin; i++) {
    iterator = nodeGetNextBelow(iterator);
    iterator = nodeGetNextRight(iterator);

    if (nodeGetNextRight(iterator) != iterator) {
      char descriptionCliente[DESCRIPTION_SIZE];
      sprintf(descriptionCliente, "Cliente: %d\n", nodeGetLine(iterator));
      strcat(*spMatrixStr, descriptionCliente);
      bought = 1;
    } /*else {
      char descriptionCliente[DESCRIPTION_SIZE];
      sprintf(descriptionCliente, "Cliente: %d\n", abs(nodeGetLine(iterator))-1);
      strcat(*spMatrixStr, descriptionCliente);
      strcat(*spMatrixStr, "Nao ha registro de Compras\n\n");
    }*/

    for(j=1; j <= spMatrix->col; j++) {
      if(nodeGetColumn(iterator) == j && nodeGetLine(iterator) == i) {
        Item slist = nodeGetItem(iterator);
        char *strTempListDescription = (char *) malloc ((shoppingListSize(&slist) * sizeof(Shopping)) * (DESCRIPTION_SIZE * sizeof(char)));
        strTempListDescription[0] = '\0';
        char *strTempList = (char *) malloc(shoppingListSize(&slist) * sizeof(Shopping));
        strTempList[0] = '\0';
        shoppingListToString(&slist, strTempList);

        char description[DESCRIPTION_SIZE] = "";
        sprintf(description, "Compra(s) do Produto: %d\n", nodeGetColumn(iterator));
        strcat(strTempListDescription, description);
        strcat(strTempListDescription, strTempList);
        strcat(strTempListDescription, "\n");

        strcat(*spMatrixStr, strTempListDescription);

        free(strTempList);
        free(strTempListDescription);      
        iterator = nodeGetNextRight(iterator);
      }
    }

    if(bought) strcat(*spMatrixStr, "\n");
    bought = 0;
  }
}

int spMatrixFree(SpMatrix *spMatrix) {
  if(spMatrix == NULL) {
    return 1;
  }
  Node prev; 
  Node firstCol, firstLine;
  Node iterator;
  int i;
  for (i = spMatrix->col; i > 0; i--) {
    spMatrixDiscoverFirstCol(spMatrix, &firstCol, i); 
    iterator = nodeGetNextBelow(firstCol);
    while (iterator != firstCol) {
      prev = iterator;
      iterator = nodeGetNextBelow(iterator);

      nodeFree(&prev);
    } 
    nodeFree(&firstCol);
  }

  for (i = spMatrix->lin; i > 0; i--) {
    spMatrixDiscoverFirstLine(spMatrix, &firstLine, i);
    nodeFree(&firstLine);
  }
  nodeFree(&spMatrix->head);

  return 0;
}

int spMatrixLinOutOfBounds(SpMatrix *spMatrix, int line) {
  return (spMatrix->lin < line || line <= 0) ? 1 : 0;
}

int spMatrixColOutOfBounds(SpMatrix *spMatrix, int col) {
    return (spMatrix->col < col || col <= 0) ? 1 : 0;
}
