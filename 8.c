#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node *left;
  struct node *right;
};

typedef struct node *N;

N getnode(int item) {
  N temp = (N)malloc(sizeof(struct node));
  temp->left = temp->right = NULL;
  temp->item = item;
  return temp;
}

void inorder(N root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d->", root->item);
    inorder(root->right);
  }
}

N insert(N root, int item) {
  if (root == NULL)
    return getnode(item);

  if (item < root->item)
    root->left = insert(root->left, item);
  else
    root->right = insert(root->right, item);
  return root;
}

N minsuccessor(N root) {
  N temp = root;
  while (temp && temp->left)
    temp = temp->left;
  return temp;
}

N deletenode(N root, int item) {
  N temp;
  if (root == NULL)
    return root;

  if (item < root->item)
    root->left = deletenode(root->left, item);
  else if (item > root->item)
    root->right = deletenode(root->right, item);
  else {
    if (root->left == NULL) {
      temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      temp = root->left;
      free(root);
      return temp;
    }

    temp = minsuccessor(root->right);
    root->item = temp->item;
    root->right = deletenode(root->right, temp->item);
  }
  return root;
}

int main() {
  N root = NULL;
  char o;
  int i;
  printf("Binary search tree\n");
  printf("Enter the operation to be performed with the input (if any):\n"
         "a. Insert b. Delete c. Inorder traversal d. Exit\n");
  while (1) {
    scanf("%c", &o);
    switch (o) {
    case 'a':
      scanf("%d", &i);
      root = insert(root, i);
      break;
    case 'b':
      scanf("%d", &i);
      root = deletenode(root, i);
      break;
    case 'c':
      printf("Inorder traversal: ");
      inorder(root);
      printf("\n");
      break;
    case 'd':
      exit(0);
      break;
    }
  }
  return 0;
}
