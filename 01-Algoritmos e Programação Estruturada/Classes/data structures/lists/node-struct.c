#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct Node {
  int info;

  struct Node* next;
};

struct List {
  struct Node* init;
  
  int size;
};

struct List* create() {
  struct List* new_list = (struct List*) malloc(sizeof(struct List));
  if (new_list != NULL) {
    new_list->init = NULL;
    new_list->size = 0;
  }

  return new_list;
}

bool empty(struct List* list) {
  assert(list != NULL);
  if(list->init == NULL) {
    return true;
  } else {
    return false;
  }
}

int main() {
  struct List* my_list = create();
  if(empty(my_list) == true) {
    printf("\nA new empty list has been created!\n");
  } else {
    printf("\nOps! Something went wrong!\n");
  }

  return 0;
}