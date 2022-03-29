#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node *N;

void display(N head) {
  if (head == NULL) {
    printf("Linked list is now empty\n");
    return;
  }
  N temp = head;
  while (temp->next != head) {
    printf("%d=>", temp->data);
    temp = temp->next;
  }
  printf("%d\n", temp->data);
}

N getnode(int data) {
  N newnode = (N)malloc(sizeof(N));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

void insert_front(N *head, int data) {
  N newnode = getnode(data);
  N temp = *head;
  if (*head == NULL) {
    *head = newnode;
    newnode->next = *head;
  } else {
    while (temp->next != *head)
      temp = temp->next;
    temp->next = newnode;
    newnode->next = *head;
    *head = newnode;
  }
  display(*head);
}

void delete_front(N *head) {
  N temp = *head;
  if (*head != NULL) {
    if ((*head)->next == *head) {
      *head = NULL;
    } else {
      while (temp->next != *head)
        temp = temp->next;
      *head = temp->next->next;
      free(temp->next);
      temp->next = *head;
    }
  }
  display(*head);
}

void insert_end(N *head, int data) {
  N newnode = getnode(data);
  N temp = *head;
  if (*head == NULL) {
    *head = newnode;
    newnode->next = *head;
  } else {
    while (temp->next != *head)
      temp = temp->next;
    temp->next = newnode;
    newnode->next = *head;
  }
  display(*head);
}
void delete_end(N *head) {
  N temp = *head;
  if (*head != NULL) {
    if ((*head)->next == *head) {
      *head = NULL;
    } else {
      while (temp->next->next != *head)
        temp = temp->next;
      free(temp->next);
      temp->next = *head;
    }
  }
  display(*head);
}

void insert_pos(N *head, int data, int pos) {
  int i;
  N temp = *head;
  N newnode = getnode(data);
  for (i = 2; i < pos; i++)
    temp = temp->next;
  newnode->next = temp->next;
  temp->next = newnode;
  display(*head);
}

void delete_pos(N *head, int pos) {
  N temp = *head;
  N del = NULL;
  int i;
  if (*head != NULL) {
    for (i = 2; i < pos; i++)
      temp = temp->next;
    del = temp->next;
    temp->next = temp->next->next;
    free(del);
  }
  display(*head);
}

int main() {
  N head = NULL;
  char o;
  int i, p;
  printf("Enter the operation to be performed with the input (if any):\na. "
         "Insert front b. Insert end c. Insert at pos d. Delete "
         "front e. Delete end f. Delete at pos g. Exit\n");
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
      scanf("%d", &i);
      printf("Enter position: ");
      scanf("%d", &p);
      insert_pos(&head, i, p);
      break;
    case 'd':
      delete_front(&head);
      break;
    case 'e':
      delete_end(&head);
      break;
    case 'f':
      printf("Enter position: ");
      scanf("%d", &p);
      delete_pos(&head, p);
      break;
    case 'g':
      free(head);
      exit(0);
      break;
    }
  }
  return 0;
}
