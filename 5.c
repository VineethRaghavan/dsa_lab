#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} * N;

void display(N head) {
  N temp = head;
  if (temp == NULL)
    printf("Linked list is now empty\n");
  else {
    while (temp->next != NULL) {
      printf("%d->", temp->data);
      temp = temp->next;
    }
    printf("%d\n", temp->data);
  }
}

N getnode(int data) {
  N newnode = (N)malloc(sizeof(N));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

void insert_front(N *head, int data) {
  N newnode = getnode(data);
  newnode->next = *head;
  *head = newnode;
  display(*head);
}

void delete_front(N *head) {
  N del = NULL;
  if (*head != NULL) {
    del = *head;
    *head = (*head)->next;
    free(del);
  }
  display(*head);
}

void insert_end(N *head, int data) {
  N newnode = getnode(data);
  N temp = *head;
  if (temp == NULL)
    temp = newnode;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = newnode;
  display(*head);
}

void delete_end(N *head) {
  N temp = *head;
  if (*head != NULL) {
    temp = *head;
    if (temp->next == NULL)
      *head = NULL;
    else {
      while (temp->next->next != NULL)
        temp = temp->next;
      free(temp->next);
      temp->next = NULL;
    }
  }
  display(*head);
}
int main() {
  N head = NULL;
  char o;
  int i, p;
  printf("Enter the type of queue:\n 1. Input restricted dequeue 2. Output "
         "restricted dequeue\n");
  scanf("%d", &i);
  if (i == 1) {
    printf("Enter the operation to be performed with the input (if any):\na. "
           "Insert front b. Delete front c. Delete end d. Exit\n");
    while (1) {
      scanf("%c", &o);
      switch (o) {
      case 'a':
        scanf("%d", &i);
        insert_front(&head, i);
        break;
      case 'b':
        delete_front(&head);
        break;
      case 'c':
        delete_end(&head);
        break;
      case 'd':
        free(head);
        exit(0);
        break;
      }
    }
  } else {
    printf("Enter the operation to be performed with the input (if any):\n"
           "a. Insert front b. Insert end c. Delete front d. Exit\n");
    while (1) {
      scanf("%c", &o);
      switch (o) {
      case 'a':
        scanf("%d", &i);
        insert_front(&head, i);
        break;
      case 'b':
        scanf("%d", &i);
        insert_end(&head, i);
        break;
      case 'c':
        delete_front(&head);
        break;
      case 'd':
        free(head);
        exit(0);
        break;
      }
    }
  }
  return 0;
}
