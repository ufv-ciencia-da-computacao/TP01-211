#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t * Node;
typedef double Item;
struct node_t {
  Node next_right;
  Node next_below;
  int line, col;
  Item value;
};

#pragma region RegionGetters
int nodeGetLine(Node *node);
int nodeGetColumn(Node *node);
Item nodeGetItem(Node *node);
#pragma endregion RegionGetters

#pragma region RegionSetters
void nodeSetLine(Node *node, int line);
void nodeSetCol(Node *node, int col);
void nodeSetItem(Node *node, Item value);
#pragma endregion RegionSetters

int nodeInit(Node *node, int line, int col, Item value);
int nodeFree(Node *node);

int nodeItemEquals(Node a, Node b);
int spMatrixItemIsValid(Node a);

#endif