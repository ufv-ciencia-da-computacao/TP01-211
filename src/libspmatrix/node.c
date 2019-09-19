#include "../include/node.h"

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

void nodeInit(Node *node, int line, int col, Item value) {
  (*node) = (Node) malloc (sizeof(struct node_t));
  (*node)->line = line;
  (*node)->col = col;
  (*node)->next_right = *node;
  (*node)->next_below = *node;
  (*node)->value = value;
}

void nodeFree(Node *node) {
  if((*node) == NULL) {
    return;
  }
  free((*node));
  *node = NULL;
}
