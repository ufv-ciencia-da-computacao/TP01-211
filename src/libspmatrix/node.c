#include "./include/node.h"

#pragma region RegionGetters
int nodeGetLine(Node node) {
  return node->line;
}

int nodeGetColumn(Node node) {
  return node->col;
}

Item nodeGetItem(Node node) {
  return node->value;
}

Node nodeGetNextRight(Node node) {
  return node->next_right;
}

Node nodeGetNextBelow(Node node) {
  return node->next_below;
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

void nodeSetNextRight(Node *node, Node nextRight){
  (*node)->next_right = nextRight;
}

void nodeSetNextBelow(Node *node, Node nextBelow) {
  (*node)->next_below = nextBelow;
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
  
  if ((*node)->value != NULL) {
    shoppingListFree(&((*node)->value));
    (*node)->value = NULL;
  }  

  free((*node));
  *node = NULL;

  return 0;
}

int nodeValueConcat(Node *dest, Node orig) {
  shoppingListConcat(&((*dest)->value), orig->value);
  return 0;
}

int nodeItemEquals(Node a, Node b) {
  return (a->value == b->value) ? 1 : 0;
}

int nodeIsValid(Node a) {
  return (a->line > 0 && a->col > 0) ? 1 : 0;
}

