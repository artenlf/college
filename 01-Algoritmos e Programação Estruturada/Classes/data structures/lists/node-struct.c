#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node* next;
};

struct List {
  struct Node* init;
  int length;
};

struct List* create() {
  struct List* new_list = (struct List*) malloc(sizeof(struct List));
  if (new_list != NULL) {
    new_list->init = NULL;
    new_list->length = 0;
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

void insert(struct List* list, int position, int item) {
  assert(list != NULL);
  assert(position >= 0 && position <= list->length);
  
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->info = item;
  
  if (position == 0) {
    new_node->next = list->init;
    list->init = new_node;
  } else {
    struct Node* aux = list->init;
    for (int i = 0; i < position - 1; i++) {
      aux = aux->next;
    }

    new_node->next = aux->next;
    aux->next = new_node;
  }

  list->length++;
}

int read(struct List* list, int position) {
  assert(list != NULL);
  assert(position >= 0 && position < list->length);
  
  struct Node* aux = list->init;
  for (int i = 0; i < position; i++) {
    aux = aux->next;
  }

  return aux->info;
}

void update(struct List* list, int position, int new_value) {
  assert(list != NULL);
  assert(position >= 0 && position < list->length);
  
  struct Node* aux = list->init;
  for (int i = 0; i < position; i++) {
    aux = aux->next;
  }

  aux->info = new_value;
}

int remove_item(struct List* list, int position) {
  assert(empty(list) == false);
  assert(position >= 0 && position < list->length);

  struct Node* previous = NULL;
  struct Node* aux = list->init;
  for(int i = 0; i < position; i++) {
    previous = aux;
    aux = aux->next;
  }

  if (previous == NULL) {
    list->init = aux->next;
  } else {
    previous->next = aux->next;
  }

  int item = aux->info;
  list->length--;
  free(aux);

  return item;
}

void print(struct List* list) {
  assert(list != NULL);
  printf("\nList: ");
  struct Node* aux = list->init;
  for(int i = 0; i < list->length; i++) {
    printf("%d ", aux->info);
    aux = aux->next;
  }
}

int length(struct List* list) {
  assert(list != NULL);
  return list->length;
}

int main() {
  struct List* my_list = create();
  if(empty(my_list) == true) {
    printf("\nA new empty list has been created!\n");
  } else {
    printf("\nOps! Something went wrong!\n");
  }

  insert(my_list, 0, 5);
  insert(my_list, 0, 3);
  insert(my_list, 2, 1);
  insert(my_list, 3, 7);
  insert(my_list, 1, 1);
  insert(my_list, 0, 6);
  insert(my_list, 5, 6);
  insert(my_list, 3, 4);
  insert(my_list, 4, 5);

  print(my_list);
  printf("\n%d", length(my_list));

  int value = read(my_list, 2);
  printf("\nValue at position 2: %d\n", value);
  
  update(my_list, 2, 10);
  print(my_list);
  
  int removed_value = remove_item(my_list, 2);
  printf("\nRemoved value from position 2: %d\n", removed_value);
  print(my_list);

  while (my_list->init != NULL) {
    struct Node* temp = my_list->init;
    my_list->init = my_list->init->next;
    free(temp);
  }
  free(my_list);

  return 0;
}
