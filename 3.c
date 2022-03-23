#include <stdio.h>
#include <string.h>

#define MAX 20

char stack[MAX];
int top = -1;

//--------------------------------------------------------
////--------------------------------------------------------
void reverse(char array[]) {
  int i, n;
  char t;
  n = strlen(array);
  for (i = 0; i < n / 2; i++) {
    t = array[i];
    array[i] = array[n - i - 1];
    array[n - i - 1] = t;
  }
}
//--------------------------------
char pop() { return stack[top--]; }
//----------------------------------
void push(char symbol) { stack[++top] = symbol; }
//------------------------------------------
int prcd(char symbol) {
  switch (symbol) {
  case '+':
  case '-':
    return 2;
    break;
  case '*':
  case '/':
    return 4;
    break;
  case '^':
    return 6;
    break;
  case '#':
  case '(':
  case ')':
    return 1;
    break;
  default:
    return -1;
    break;
  }
}
//-------------------------------------------------
int isOperator(char symbol) {
  switch (symbol) {
  case '+':
  case '-':
  case '*':
  case '/':
  case '^':
  case '(':
  case ')':
    return 1;
    break;
  default:
    return 0;
    // returns 0 if the symbol is other than given above
  }
}

void infixtoprefix(char infix[], char prefix[]) {
  int i, j = 0;
  char symbol;
  for (i = 0; i < strlen(infix); i++) {
    symbol = infix[i];
    if (!isOperator(symbol)) {
      prefix[j++] = symbol;
    } else if (symbol == ')') {
      push(symbol);
    } else if (symbol == '(') {
      while (stack[top] != ')')
        prefix[j++] = pop();
      pop();
    } else if (prcd(symbol) > prcd(stack[top])) {
      push(symbol);
    } else {
      while (prcd(symbol) <= prcd(stack[top]))
        prefix[j++] = pop();
      push(symbol);
    }
  }
  while (stack[top] != '#')
    prefix[j++] = pop();
  prefix[j] = '\0';
}

int main() {
  char infix[30], prefix[30];
  stack[++top] = '#';
  printf("Enter infix operation: ");
  fgets(infix, 30, stdin);
  reverse(infix);
  infixtoprefix(infix, prefix);
  reverse(prefix);
  fputs(prefix, stdout);
  return 0;
}
