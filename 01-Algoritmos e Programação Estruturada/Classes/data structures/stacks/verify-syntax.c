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

void freeMemoryStack(struct Stack* stack) {
  assert(stack != NULL);
  while (!empty(stack)) {
    pop(stack);
  }
  free(stack);
}

bool combine(char char1, char char2) {
  switch (char1) {
    case ')' : return char2 == '(';
    case '}' : return char2 == '{';
    case ']' : return char2 == '[';
    default: return false;
  }
}

bool validate(char expect[], int length) {
  struct Stack* stack = create();
  for (int i = 0; i < length; i++) {
    char c = expect[i];
    switch (c) {
      case '(' :
      case '{' :
      case '[' : push(stack, c); break;
      case ')' :
      case '}' :
      case ']' : {
        if (empty(stack) || !combine(c, pop(stack))) {
          freeMemoryStack(stack);
          return false;
        }
      } break;
    }
  }
  
  bool is_valid = empty(stack);
  freeMemoryStack(stack);

  return is_valid;
}

int main() {
  char expect[] = "{ ( [] ) }";
  printf("1. Everything is fine; 0. There's a syntax error: %d\n", validate(expect, 10)); // Added line break and corrected length

  return 0;
}