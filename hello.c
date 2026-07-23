#include <stdio.h>
#include "Mylib.h"
int main() {
  int a=10;
  int *p;
  p=&a;
  *p=11;
  printf("gia tri cua p: %d",*p);
  return 0;
}