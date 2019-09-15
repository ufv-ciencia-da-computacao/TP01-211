#ifndef __NODE_H__
#define __NODE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t * Node;

struct node_t {
  Node next_right;
  Node next_below;
  int line, col;
  double value;
};

static void nodeCreate(Node *node);

void nodeInit(Node *node);
void nodeConstructSpMatrixLine(Node *node, int line, int col);
void nodeConstructSpMatrixColumn(Node *node, int line, int col);
void nodeInsert(Node *node, int line, int col, double value);
void nodeRemove(Node *node, int line, int col);
void nodeFree(Node *node);

#endif