#include <stdio.h>

int main() {
  int a = 350;
  double b = 412.5;
  double c = 517.25;
  double sum;

  sum = a + b + c;

  printf("a =%4d\n", a);
  printf("b =%7.2f\n", b);
  printf("c =%7.2f\n", c);

  printf("Die Summe von a, b, und c ist %.2f\n", sum);
  return 0;
}

