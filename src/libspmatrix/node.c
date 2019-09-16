#include "include/node.h"

void nodeCreate(Node *node, int line, int col, Item value) {
  (*node) = (Node) malloc (sizeof(Node));
  (*node)->line = line;
  (*node)->col = col;
  (*node)->next_right = &node;
  (*node)->next_below = &node;
  (*node)->value = value;
}

void nodeInit(Node *node) {
  *node = NULL;
}

void nodeConstructSpMatrixLine(Node *node, int line) {
  Node auxNode;
  Node iterator = (*node);

  for (int i = 2; i <= line+1; i++) {
    nodeCreate(&auxNode, (-1) * line, -1, 0);
    iterator->next_below = auxNode;
    iterator = iterator->next_below;
  }
  iterator->next_below = node;
}

void nodeConstructSpMatrixColumn(Node *node, int col) {
  Node auxNode;
  Node iterator = (*node);
  for (int i = 2; i <= col+1; i++) {
    nodeCreate(&auxNode, -1, (-1) * col, 0);
    iterator->next_right = auxNode;
    iterator = iterator->next_right;
  }  
  iterator->next_right = node;
}

Node nodeDiscoverFirstCol(Node *node, int col) {
  Node iterator = (*node);
  Node auxFirstCol;

  do {
    if (abs(iterator->col)-1 == col) {
      auxFirstCol = iterator;
      break;
    } else {
      iterator = iterator->next_right; 
    }
  } while (iterator->next_right->col != -1 && iterator->next_right->line != -1);

  return auxFirstCol;
}

Node nodeDiscoverFirstLine(Node *node, int line) {
  Node iterator = (*node);
  Node auxFirstLine;

  do {
    if (abs(iterator->line) == line) {
      auxFirstLine = iterator;
      break;
    } else {
      iterator = iterator->next_below; 
    }
  } while(iterator->next_below->col != -1 && iterator->next_below->line != -1);

  return auxFirstLine;
}

void nodeInsert(Node *node, int line, int col, Item value) {
  Node iterator;
  Node prev, next;

  Node auxFirstCol = nodeDiscoverFirstCol(node, col);
  Node auxFirstLine = nodeDiscoverFirstLine(node, line);

  Node createdNode;
  nodeCreate(&createdNode, line, col, value);

  iterator = auxFirstCol;
  next = iterator->next_below;
  while(true) {

    if(iterator->line > createdNode->line) {
      prev->next_below = createdNode;
      createdNode->next_below = iterator;
      break;
    }
    
    if(iterator->line == createdNode->line) {
      iterator->value = createdNode->value;
      nodeFree(&createdNode);
      break;
    }

    if(next->line == auxFirstCol->line) {
      iterator->next_below = createdNode;
      createdNode->next_below = next;
      break;
    }

    prev = iterator;
    iterator = next;
    next = iterator->next_below;
  }
    
}

void nodeRemove(Node *node, int line, int col);
void nodeFree(Node *node) {
  if((*node) == NULL) {
    return 0;
  }
  free((*node));
}
