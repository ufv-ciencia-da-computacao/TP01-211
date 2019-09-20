#include "../include/spmatrix.h"

static void spMatrixConstructColumn(SpMatrix *spMatrix) {
  Node auxNode;
  Node iterator = spMatrix->head;

  for (int i = 2; i <= spMatrix->lin+1; i++) {
    nodeInit(&auxNode, (-1) * i, -1, 0);
    iterator->next_below = auxNode;
    iterator = iterator->next_below;
  }
  iterator->next_below = spMatrix->head;
}

static void spMatrixConstructLine(SpMatrix *spMatrix) {
  Node auxNode;
  Node iterator = spMatrix->head;
  for (int i = 2; i <= spMatrix->col+1; i++) {
    nodeInit(&auxNode, -1, (-1) * i, 0);
    iterator->next_right = auxNode;
    iterator = iterator->next_right;
  }  
  iterator->next_right = spMatrix->head;
}

static void spMatrixDiscoverFirstCol(SpMatrix *spMatrix, Node *firstCol, int col) {
  Node iterator = spMatrix->head;
  
  do {
    if (abs(iterator->col)-1 == col) {
      (*firstCol) = iterator;
      break;
    }
    iterator = iterator->next_right; 
  } while (iterator->col != -1);
}

static void spMatrixDiscoverFirstLine(SpMatrix *spMatrix, Node *firstLine, int line) {
  Node iterator = spMatrix->head;

  do {
    if (abs(iterator->line)-1 == line) {
      (*firstLine) = iterator;
      break;
    }
    iterator = iterator->next_below; 
  } while(iterator->line != -1);
}

static void spMatrixInsertCol(SpMatrix *spMatrix, Node *createdNode, int col) {
  Node iterator;
  Node prev, next;

  Node auxFirstCol;
  spMatrixDiscoverFirstCol(spMatrix, &auxFirstCol, col);

  iterator = auxFirstCol;

  while(true) {
    next = iterator->next_below;

    if(iterator->line > (*createdNode)->line) {
      prev->next_below = (*createdNode);
      (*createdNode)->next_below = iterator;
      break;
    }
    
    if(iterator->line == (*createdNode)->line) {
      iterator->value = (*createdNode)->value;
      nodeFree(createdNode);
      (*createdNode) = iterator;
      break;
    }

    if(next->line == auxFirstCol->line) {
      iterator->next_below = (*createdNode);
      (*createdNode)->next_below = next;
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
    next = iterator->next_right;

    if(iterator->col > (*createdNode)->col) {
      prev->next_right = (*createdNode);
      (*createdNode)->next_right = iterator;
      break;
    }

    if(iterator->col == (*createdNode)->col) {
      /*
        Process already done on spMatrixInsertCol, cannot free node twice.
      */
      break;
    }

    if (next->col == auxFirstLine->col) {
      iterator->next_right = (*createdNode);
      (*createdNode)->next_right = next;
      break;
    }

    prev = iterator;
    iterator = next;
  }
}

int spMatrixInit(SpMatrix *spMatrix, int lin, int col) {
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

void spMatrixToString(SpMatrix *spMatrix/*, char str[]*/) {
  Node iterator = spMatrix->head;
  // str[0] = '\0';
  // char strTemp[32];
  int i, j;
  for(i=1; i <= spMatrix->lin; i++) {
    iterator = iterator->next_below;
    iterator = iterator->next_right;
    for(j=1; j <= spMatrix->col; j++) {
      if(iterator->col == j && iterator->line == i) {
          // sprintf(strTemp, "%.2lf\t", iterator->value);
          // strcat(str, strTemp);          
          printf("%.2lf\t", iterator->value);
          iterator = iterator->next_right;
      } else {
        // strcat(str, "0.00\t");
        printf("0.00\t");
      }
    }
    //// strcat(str, "\n");
    printf("\n");
  }  

  return 0;      
}

int spMatrixFree(SpMatrix *spMatrix) {
  Node prev;
  Node elem; 
  Node firstCol, firstLine;
  Node iterator;
  
  for (int i = spMatrix->col; i > 0; i--) {
    spMatrixDiscoverFirstCol(spMatrix, &firstCol, i); 
    iterator = firstCol->next_below;
    while (iterator != firstCol) {
      prev = iterator;
      iterator = iterator->next_below;
      nodeFree(&prev);
    } 
    nodeFree(&firstCol);
  }

  for (int i = spMatrix->lin; i > 0; i--) {
    spMatrixDiscoverFirstLine(spMatrix, &firstLine, i);
    nodeFree(&firstLine);
  }
  nodeFree(&spMatrix->head);

  return 0;
}

int spMatrixLinOutOfBounds(SpMatrix *spMatrix, int line) {
  return 1 ? spMatrix->lin < line : 0;
}

int spMatrixColOutOfBounds(SpMatrix *spMatrix, int col) {
    return 1 ? spMatrix->col < col : 0;
}