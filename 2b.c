#include <stdio.h>

void insertion_sort(int arr[], int n) {
  int last, j;
  if (n <= 1)
    return;
  insertion_sort(arr, n - 1);

  last = arr[n - 1];
  j = n - 2;

  while (j >= 0 && arr[j] > last) {
    arr[j + 1] = arr[j];
    j--;
  }

  arr[j + 1] = last;
}

int main() {
  int i, n, arr[10];
  printf("Enter the number of elements to insert: ");
  scanf("%d", &n);
  printf("\nEnter the elements:\n");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  insertion_sort(arr, n);
  printf("\nThe elements after sorting are:\n");
  for (i = 0; i < n; i++)
    printf("%d", arr[i]);
  return 0;
}
