#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct Node {
  int info;

  struct Node* next;
};

struct Stack {
  struct Node* top;

  int length;
};

struct Stack* create() {
  struct Stack* new_stack = (struct Stack*)malloc(sizeof(struct Stack));
  if (new_stack != NULL) {
    new_stack->top = NULL;
    new_stack->length = 0;
  }

  return new_stack;
}

void push(struct Stack* stack, int item) {
  assert(stack != NULL);
  
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  
  if (new_node != NULL) {
    new_node->info = item;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->length++;
  }
}

int pop(struct Stack* stack) {
  assert(stack != NULL);
  assert(stack->top != NULL);

  struct Node* aux = stack->top;
  
  int item = aux->info;
  stack->top = aux->next;
  stack->length--;
  
  free(aux);
  
  return item;
}

int top(struct Stack* stack) {
  assert(stack != NULL);
  assert(stack->top != NULL);

  struct Node* top = stack->top;

  return top->info;
}

int length(struct Stack* stack) {
  assert(stack != NULL);

  return stack->length;
}

int empty(struct Stack* stack) {
  assert(stack != NULL);

  return (stack->top == NULL);
}

int freeMemoryStack(struct Stack* stack) {
  assert(stack != NULL);

  while (empty(stack) == false) {
    pop(stack);
  }
  
  free(stack);
}

int main() {
  struct Stack* my_stack = create();
  
  printf("Is the Stack empty? 1. Yes; 2. No %d\n", empty(my_stack));

  printf("Pushing 1 into the Stack... \n");
  push(my_stack, 1);
  printf("Pushing 2 into the Stack... \n");
  push(my_stack, 2);
  printf("Pushing 3 into the Stack... \n");
  push(my_stack, 3);

  printf("Is the Stack empty? 1. Yes; 2. No %d\n", empty(my_stack));

  printf("Top = %d\n", top(my_stack));
  printf("Length = %d\n", length(my_stack));

  printf("poping items from the Stack: ");
  printf("%d ", pop(my_stack));
  printf("%d ", pop(my_stack));
  printf("%d ", pop(my_stack));

  freeMemoryStack(my_stack);

  return 0;
}
