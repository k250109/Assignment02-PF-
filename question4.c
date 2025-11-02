#include <stdio.h>

#define MAX_SIZE 100
int stack[MAX_SIZE] = {0};
int top = -1;
void push() {
  int i = top + 1;
  if (i >= MAX_SIZE) {
    printf("\nError: Stack overflow. Max stack size reached.\n");
    return;
  }
  int element;
  printf("Enter a value to add into stack: ");
  scanf("%d", &element);
  while (getchar() != '\n')
    ;
  stack[i] = element;
  top++;
}
void pop() {
  int i = top;
  if (i <= 0) {
    printf(
        "Error: Stack underflow. No elements available to pop in the stack\n");
    return;
  }
  top--;
  printf("\nRemoved Element %d => `%d` from the stack\n\n", i, stack[i]);
}
void peek() {
  printf("\nThe top most element in the stack is: `%d`\n\n", stack[top]);
}
void display() {
  printf("\n---Current Stack---\n\n");
  if (top < 0) {
    printf("Stack is empty...\n\n");
    return;
  }
  for (int i = 0; i <= top; i++) {
    printf("[%d] = %d\n", i, stack[i]);
  }
  printf("\n");
}
int main() {
  int choice;
  do {
    printf("\n--- Welcome to Stack Management System ---\n\n");
    printf("[1]. PUSH\n");
    printf("[2]. POP\n");
    printf("[3]. PEEK\n");
    printf("[4]. DISPLAY\n");
    printf("[5]. EXIT\n");
    printf("Enter which operation you want to perform (1-5): ");
    scanf("%d", &choice);
    while (getchar() != '\n');
    switch (choice) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      peek();
      break;
    case 4:
      display();
      break;
    case 5:
      printf("\nThank You for using this application!\n");
      break;
    default:
      printf("\nInvalid Choice! Please try again.\n");
      continue;
    }
  } while (choice != 5);
  return 0;
}