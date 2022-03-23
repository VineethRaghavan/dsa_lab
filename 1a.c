#include <stdio.h>

#define SIZE 20

int stack[SIZE], top = -1;

void push(int item) {
  if (top == SIZE - 1)
    printf("Stack overflow\n");
  else {
    stack[++top] = item;
  }
}

void pop() {
  if (top == -1)
    printf("Stack underflow\n");
  else
    printf("Item removed: %d\n", stack[top--]);
}

void peek() {
  if (top == -1)
    printf("Stack is empty\n");
  else
    printf("Top of stack is: %d\n", stack[top]);
}

int main() {
  int c, i;
  while (1) {
    printf("Enter the operation to perform:\n1. Push 2. Pop 3. Peek 4. Exit\n");
    scanf("%d", &c);
    switch (c) {
    case 1:
      printf("Enter the item to be pushed: ");
      scanf("%d", &i);
      push(i);
      break;
    case 2:
      pop();
      break;
    case 3:
      peek();
      break;
    case 4:
      return 0;
      break;
    default:
      printf("Wrong choice\n");
      break;
    }
  }
  return 0;
}
