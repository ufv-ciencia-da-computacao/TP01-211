#include "./include/node.h"

#pragma region RegionGetters
int nodeGetLine(Node *node) {
  return (*node)->line;
}

int nodeGetColumn(Node *node) {
  return (*node)->col;
}

Item nodeGetItem(Node *node) {
  return (*node)->value;
}
#pragma endregion RegionGetters

#pragma region RegionSetters
void nodeSetLine(Node *node, int line) {
  (*node)->line = line;
}

void nodeSetCol(Node *node, int col) {
  (*node)->col = col;
}

void nodeSetItem(Node *node, Item value) {
  (*node)->value = value;
}
#pragma endregion RegionSetters

int nodeInit(Node *node, int line, int col, Item value) {
  (*node) = (Node) malloc (sizeof(struct node_t));
  (*node)->line = line;
  (*node)->col = col;
  (*node)->next_right = *node;
  (*node)->next_below = *node;
  (*node)->value = value;

  return 0;
}

int nodeFree(Node *node) {
  if((*node) == NULL) {
    return 1;
  }
  free((*node));
  *node = NULL;

  return 1;
}

int nodeItemEquals(Node a, Node b) {
  return 1 ? a->value == b->value : 0;
}

int spMatrixItemIsValid(Node a) {
  return 1 ? (a->line > 0 && a->col > 0) : 0;
}

