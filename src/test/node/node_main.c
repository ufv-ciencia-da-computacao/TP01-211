#include "../../include/node.h"

int main() {
  Node node;

  nodeInit(&node, -1, -1, 0);
  printf("Line: %d\nColumn: %d\nValue: %.2lf\n", nodeGetLine(&node), nodeGetColumn(&node), nodeGetItem(&node));
  
  printf("NODE - NEXT RIGHT:\n");
  printf("Line: %d\nColumn: %d\nValue: %.2lf\n", nodeGetLine(&node->next_right), nodeGetColumn(&node->next_right), nodeGetItem(&node->next_right));
  
  printf("NODE - NEXT BELOW:\n");
  printf("Line: %d\nColumn: %d\nValue: %.2lf\n", nodeGetLine(&node->next_below), nodeGetColumn(&node->next_below), nodeGetItem(&node->next_below));


  nodeFree(&node);

  return 0;
}