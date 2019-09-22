#include <stdio.h>
#include <stdbool.h>
#include "../../libspmatrix/include/date.h"

int main() {

  Date d;
  int day, month, year;
  
  printf("\ndia mes ano\n");
  scanf("%d %d %d", &day, &month, &year);

  dateInit(&d, day, month, year);

  if(dateVerify(d)) printf("\nDATA valida\n"); else printf("\nDATA invalida\n");

  return 0;
}
