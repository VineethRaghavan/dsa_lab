#include <stdio.h>
#include <stdlib.h>
int main() {
  int a[100], a1[100], i, j, result, n, count = 0;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a1[i] = -1;
  }
  for (i = 0; i < n; i++) {
    result = a[i] % n;
    if (a1[result] == -1) {
      a1[result] = a[i];
      printf("Location: a1[%d], Value: %d\n", result, a1[result]);
    } else {
      j = result + 1;
      while (1) {
        if (a1[j] == -1) {
          a1[j] = a[i];
          printf("Location: a1[%d], Value: %d\n", j, a1[j]);
          break;
        }
        j = (j + 1) % n;
        if (count == n)
          break;
        count++;
      }
    }
    result = 0;
  }
  printf("Hash table using open addressing mode:\n");
  for (i = 0; i < n; i++) {
    if (a1[i] != -1)
      printf("%d ", a1[i]);
  }
  return 0;
}
