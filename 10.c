#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *left;
  struct node *right;
  int RT;
};
typedef struct node *NODE;

NODE leftmost(NODE temp) {
  if (temp == 0)
    return 0;
  while (temp->left != 0)
    temp = temp->left;
  return temp;
}

void inorder(NODE head) {
  NODE temp = leftmost(head);
  if (head->left == 0) {
    printf("\n No nodes");
    return;
  }
  while (temp != head) {
    printf("%d=>", temp->data);
    if (temp->RT)
      temp = temp->right;
    else
      temp = leftmost(temp->right);
  }
}

NODE getnode(int item) {
  NODE newnode = (NODE)malloc(sizeof(struct node));
  newnode->left = newnode->right = 0;
  newnode->RT = 0;
  newnode->data = item;
  return newnode;
}
void insert_left(int item, NODE ptr) {
  NODE newnode = getnode(item);
  ptr->left = newnode;
  newnode->right = ptr;
  newnode->RT = 1;
}
void insert_right(int item, NODE ptr) {
  NODE newnode = getnode(item);
  newnode->right = ptr->right;
  newnode->RT = 1;
  ptr->right = newnode;
  ptr->RT = 0;
}

NODE create(int item, NODE head) {
  NODE curptr, ptr;
  if (head->left == 0) {
    insert_left(item, head);
    return (head);
  }
  curptr = head->left;
  while (curptr != head) {
    ptr = curptr;
    if (item < (curptr->data) && curptr->left != 0)
      curptr = curptr->left;
    else if (item > (curptr->data) && curptr->RT == 0)
      curptr = curptr->right;
    else
      break;
  }
  if (item < (curptr->data)) {
    insert_left(item, ptr);
    return (head);
  } else if (item > (curptr->data))
    insert_right(item, ptr);
  return (head);
}

int main() {
  int ch, i, n, item;
  NODE head;
  head = (NODE)malloc(sizeof(struct node));
  head->right = head;
  head->left = 0;
  head->RT = 0;
  while (1) {
    printf("\n1.Create tree\n2.Inorder\n3.Exit\n");
    printf("Enter the choice\n");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      free(head);
      head = (NODE)malloc(sizeof(struct node));
      head->right = head;
      head->left = 0;
      head->RT = 0;
      printf("Enter num of nodes to create\n");
      scanf("%d", &n);
      for (i = 0; i < n; i++) {
        printf("Enter %d data\n", i + 1);
        scanf("%d", &item);
        head = create(item, head);
      }
      break;
    case 2:
      inorder(head);
      break;
    case 3:
      exit(0);
    default:
      printf("Wrong choice\n");
      break;
    }
  }
  return 0;
}
