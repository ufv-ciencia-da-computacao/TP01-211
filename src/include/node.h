#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t * Node;
typedef double Item;
struct node_t {
  Node next_right;
  Node next_below;
  int line, col;
  Item value;
};

void nodeCreate(Node *node, int line, int col, double value);

void nodeInit(Node *node);
void nodeConstructSpMatrixLine(Node *node, int line, int col);
void nodeConstructSpMatrixColumn(Node *node, int line, int col);
void nodeInsert(Node *node, int line, int col, double value);
void nodeRemove(Node *node, int line, int col);
void nodeFree(Node *node);

#endif