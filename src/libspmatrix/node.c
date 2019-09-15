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

void nodeConstructSpMatrixLine(Node *node, int line, int col) {
  Node auxNode;
  Node iterator = *node;

  for (int i = 1; i <= line; i++) {
    nodeCreate(&auxNode, (-1) * line, -1, 0);
    iterator->next_below = &auxNode;
    iterator->next_right = &auxNode;
    iterator = iterator->next_below;
    nodeFree(auxNode);
  }
  iterator->next_below = node;
}

void nodeConstructSpMatrixColumn(Node *node, int line, int col) {
  Node auxNode;
  Node iterator = *node;
  for (int i = 1; i <= col; i++) {
    nodeCreate(&auxNode, -1, (-1) * col, 0);
    iterator->next_right = &auxNode;
    iterator->next_below = &auxNode;
    iterator = iterator->next_right;
    nodeFree(auxNode);
  }  
  iterator->next_right = node;
}

Node nodeDiscoverFirstCol(Node *node, int col) {
  Node iterator = *node;
  Node auxFirstCol;

  do {
    if (abs(iterator->col) == col) {
      auxFirstCol = iterator;
      break;
    } else {
      iterator = iterator->next_right; 
    }
  } while (iterator->next_right->col != -1 && iterator->next_right->line != -1);

  return auxFirstCol;
}

Node nodeDiscoverFirstLine(Node *node, int line) {
  Node iterator = *node;
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

  Node auxFirstCol = nodeDiscoverFirstCol(node, col);
  Node auxFirstLine = nodeDiscoverFirstLine(node, line);

  Node createdNode;
  nodeCreate(&createdNode, line, col, value);

  iterator = auxFirstCol;
  // traverse matrix TODO
    
}

void nodeRemove(Node *node, int line, int col);
void nodeFree(Node *node) {
  if((*node) == NULL) {
    return 0;
  }

  free((*node)->next_below);
  free((*node)->next_right);
  free((*node));
}