#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./shoppingList.h"

typedef struct node_t * Node;
typedef ShoppingList Item;
struct node_t {
  Node next_right;
  Node next_below;
  int line, col;
  Item value;
};

#pragma region RegionGetters
int nodeGetLine(Node node);
int nodeGetColumn(Node node);
Item nodeGetItem(Node node);
Node nodeGetNextRight(Node node);
Node nodeGetNextBelow(Node node);
#pragma endregion RegionGetters

#pragma region RegionSetters
void nodeSetLine(Node *node, int line);
void nodeSetCol(Node *node, int col);
void nodeSetItem(Node *node, Item value);
void nodeSetNextRight(Node *node, Node nextRight);
void nodeSetNextBelow(Node *node, Node nextBelow);
#pragma endregion RegionSetters

int nodeInit(Node *node, int line, int col, Item value);
int nodeFree(Node *node);
int nodeValueConcat(Node *dest, Node orig);
int nodeItemEquals(Node a, Node b);
int nodeIsValid(Node a);

#endif
