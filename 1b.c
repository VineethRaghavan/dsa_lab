#include <stdio.h>

#define SIZE 20

int queue[SIZE], front = -1, rear = -1;

void enqueue(int item) {
  if (rear == SIZE - 1)
    printf("Queue full\n");
  else {
    if (front == -1)
      front++;
    queue[++rear] = item;
  }
}

void dequeue() {
  if (front == -1)
    printf("Queue empty\n");
  else {
    printf("Item removed: %d\n", queue[front++]);
    if (front > rear)
      rear = front = -1;
  }
}

void display() {
  int i;
  if (rear == -1)
    printf("Queue is empty\n");
  else {
    for (i = front; i <= rear; i++)
      printf("%d ", queue[i]);
    printf("\n");
  }
}
int main() {
  int c, i;
  while (1) {
    printf("Enter the operation to perform:\n1. Enqueue 2. Dequeue 3. "
           "Display 4. Exit\n");
    scanf("%d", &c);
    switch (c) {
    case 1:
      printf("Enter the item to be enqueued: ");
      scanf("%d", &i);
      enqueue(i);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
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
