#include "../../libspmatrix/include/node.h"

int main() {
  Node n;
  nodeInit(&n, -1, -1, NULL);
  nodeFree(&n);
  return 0;
}
