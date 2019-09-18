#include "../include/spmatrix.h"

static void spMatrixConstructLine(SpMatrix *spMatrix) {
  Node auxNode;
  Node iterator = spMatrix->head;

  for (int i = 2; i <= spMatrix->lin+1; i++) {
    nodeInit(&auxNode, (-1) * i, -1, 0);
    iterator->next_below = auxNode;
    iterator = iterator->next_below;
  }
  iterator->next_below = spMatrix->head;
}

static void spMatrixConstructColumn(SpMatrix *spMatrix) {
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
    } else {
      iterator = iterator->next_below; 
    }
  } while(iterator->line != -1);
}

static int spMatrixInsertCol(SpMatrix *spMatrix, Node *createdNode, int col) {
  Node iterator;
  Node prev, next;

  int ret = 1;

  Node auxFirstCol;
  spMatrixDiscoverFirstCol(spMatrix, &auxFirstCol, col);

  iterator = auxFirstCol;

  next = iterator->next_below;
  while(true) {

    if(iterator->line > (*createdNode)->line) {
      prev->next_below = (*createdNode);
      (*createdNode)->next_below = iterator;
      break;
    }
    
    if(iterator->line == (*createdNode)->line) {
      iterator->value = (*createdNode)->value;
      ret = 0;
      break;
    }

    if(next->line == auxFirstCol->line) {
      iterator->next_below = (*createdNode);
      (*createdNode)->next_below = next;
      break;
    }

    prev = iterator;
    iterator = next;
    next = iterator->next_below;
  }

  return ret;
}

static void spMatrixInsertLine(SpMatrix *spMatrix, Node *createdNode, int line) {
  Node iterator;
  Node prev, next;

  Node auxFirstLine;
  spMatrixDiscoverFirstLine(spMatrix, &auxFirstLine, line);
  
  iterator = auxFirstLine;
  next = iterator->next_right;

  while (true) {
    if(iterator->col > (*createdNode)->col) {
      prev->next_right = (*createdNode);
      (*createdNode)->next_right = iterator;
      break;
    }

    if (next->col == auxFirstLine->col) {
      iterator->next_right = (*createdNode);
      (*createdNode)->next_right = next;
      break;
    }

    prev = iterator;
    iterator = next;
    next = iterator->next_right;
  }
}

void spMatrixInit(SpMatrix *spMatrix, int lin, int col) {
  nodeInit(&spMatrix->head, -1, -1, 0);
  spMatrix->lin = lin;
  spMatrix->col = col;
  spMatrixConstructLine(spMatrix);
  spMatrixConstructColumn(spMatrix);
}

void spMatrixInsert(SpMatrix *spMatrix, int line, int col, Item value) {
  Node createdNode;
  nodeInit(&createdNode, line, col, value);

  if(!spMatrixInsertCol(spMatrix, &createdNode, col))  {
    nodeFree(&createdNode);
  }
  spMatrixInsertLine(spMatrix, &createdNode, line); 
}

void spMatrixToString(SpMatrix *spMatrix) {
  Node iterator = spMatrix->head->next_below;

  /*
    index para completar com 0's
  */
  int i=1 , j=1;
  
  do {
    iterator = iterator->next_right;
    
    if (iterator->col == -1) {
      iterator = iterator->next_below;
      iterator = iterator->next_right;
      printf("\n");
    }

    if (iterator->col >= 0 || iterator->line >= 0) {
      
      // for(i; i<iterator->col; i++) {
      //   for(j; j<iterator->line; j++) {
      //     /* print 0 ? QUASEE */
      //     printf("0.00\t");
      //   }
      // }
      printf("%.2lf\t", iterator->value);

    }
      
  } while (iterator->next_below->line != -1 || iterator->next_right->col != -1);
  
}

void spMatrixFree(SpMatrix *spMatrix) {
  //TODO must iterate in all node desallocating each.
}
