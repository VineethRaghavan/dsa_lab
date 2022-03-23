#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *lchild;
  struct node *rchild;
};
typedef struct node *N;
N getnode() {
  N temp;
  temp = (N)malloc(sizeof(struct node));
  temp->lchild = temp->rchild = NULL;
  printf("Enter the data: ");
  scanf("%d", &temp->data);
  return temp;
}

int is_lchild(N root) {
  int ch;
  printf("Create lchild of %d? YES-1 NO-0 : ", root->data);
  scanf("%d", &ch);
  return ch;
}
int is_rchild(N root) {
  int ch;
  printf("Create rchild of %d? YES-1 NO-0 : ", root->data);
  scanf("%d", &ch);
  return ch;
}

void create(N root) {
  if (is_lchild(root)) {
    root->lchild = getnode();
    create(root->lchild);
  }
  if (is_rchild(root)) {
    root->rchild = getnode();
    create(root->rchild);
  }
}
void inorder(N root) {
  if (root != NULL) {
    inorder(root->lchild);
    printf("%d=>", root->data);
    inorder(root->rchild);
  }
}
void preorder(N root) {
  if (root != NULL) {
    printf("%d=>", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
  }
}
void postorder(N root) {
  if (root != NULL) {
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d=>", root->data);
  }
}
int main() {
  N root = NULL;
  printf("Tree traversals\n");
  printf("Root node:\n");
  root = getnode();
  create(root);
  printf("\nPreorder traversal:\n");
  preorder(root);
  printf("\nInorder traversal:\n");
  inorder(root);
  printf("\nPostorder traversal:\n");
  postorder(root);
  return 0;
}
