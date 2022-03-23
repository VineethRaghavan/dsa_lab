#include <stdio.h>

void tower(int n, char s, char t, char d) {
  if (n > 0) {
    tower(n - 1, s, d, t);
    printf("Move %d from %c to %c\n", n, s, d);
    tower(n - 1, t, s, d);
  }
}

int main() {
  int i;
  printf("Enter the number of disks: ");
  scanf("%d", &i);
  tower(i, 's', 't', 'd');
  return 0;
}
