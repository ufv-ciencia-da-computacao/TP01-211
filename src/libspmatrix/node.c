#include "include/node.h"

static void nodeCreate(Node *node, int line, int col, double value) {
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
    iterator = iterator->next_below;
    nodeFree(auxNode);
  }
  iterator->next_below = node;
}

void nodeConstructSpMatrixColumn(Node *node, int line, int col) {
  Node auxNode;
  Node iterator = *node;
  for (int i = 1; i <= col; i++) {
    nodeCreate(&node, -1, (-1) * col, 0);
    iterator->next_right = &auxNode;
    iterator = iterator->next_right;
    nodeFree(auxNode);
  }  
  iterator->next_right = node;
}

void nodeInsert(Node *node, int line, int col, double value);
void nodeRemove(Node *node, int line, int col);
void nodeFree(Node *node) {
  if((*node) == NULL) {
    return 0;
  }

  free((*node)->next_below);
  free((*node)->next_right);
  free((*node));
}