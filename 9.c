#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char data;
  struct node *left;
  struct node *right;
};

typedef struct node *N;

float eval(N root) {
  float num;
  switch (root->data) {
  case '+':
    return eval(root->left) + eval(root->right);
    break;
  case '-':
    return eval(root->left) - eval(root->right);
    break;
  case '*':
    return eval(root->left) * eval(root->right);
    break;
  case '/':
    return eval(root->left) / eval(root->right);
    break;
  case '^':
    return pow(eval(root->left), eval(root->right));
    break;
  default:
    if (isalpha(root->data)) {
      printf("Enter the value of %c: ", root->data);
      scanf("%f", &num);
      return num;
    } else {
      return (root->data - '0');
      break;
    }
  }
}

N create_tree(char postfix[]) {
  int i = 0, j = 0;
  N temp = NULL, stack[20];

  for (i = 0; i < strlen(postfix); i++) {
    temp = (N)malloc(sizeof(struct node));
    temp->data = postfix[i];
    temp->left = temp->right = NULL;
    if (isalpha(postfix[i]))
      stack[j++] = temp;
    else {
      temp->right = stack[--j];
      temp->left = stack[--j];
      stack[j++] = temp;
    }
  }
  return stack[--j];
}

int main() {
  char postfix[20];
  float result;
  N root = NULL;
  printf("Enter the postfix expression:\n");
  scanf("%s", postfix);
  root = create_tree(postfix);
  result = eval(root);
  printf("Result = %f\n", result);
  return 0;
}
