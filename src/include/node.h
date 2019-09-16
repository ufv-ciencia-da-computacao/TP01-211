#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct node_t * Node;
typedef double Item;
struct node_t {
  Node next_right;
  Node next_below;
  int line, col;
  Item value;
};

void nodeCreate(Node *node, int line, int col, Item value);

void nodeInit(Node *node);
void nodeConstructSpMatrixLine(Node *node, int line);
void nodeConstructSpMatrixColumn(Node *node, int col);
Node nodeDiscoverFirstCol(Node *node, int col);
Node nodeDiscoverFirstLine(Node *node, int line);
void nodeInsert(Node *node, int line, int col, Item value);
void nodeRemove(Node *node, int line, int col);
void nodeFree(Node *node);

#endif