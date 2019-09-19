#include <stdio.h>
#include <stdbool.h>
#include "../../include/date.h"

int main() {

  Date d;
  int day, month, year;

  while(true) {
    printf("\ndia mes ano\n");
    scanf("%d %d %d", &day, &month, &year);
  }

  return 0;
}
