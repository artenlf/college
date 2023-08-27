#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

struct Node {
  int info;
  struct Node* next;
  struct Node* prev;
};

struct List {
  struct Node* init;
  struct Node* end;
  int length;
};

struct List* create() {
  struct List* new_list = (struct List*) malloc(sizeof(struct List));
  if (new_list != NULL) {
    new_list->init = NULL;
    new_list->end = NULL;
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
    new_node->prev = list->end;
    new_node->next = list->init;
    list->init = new_node;
    if (list->end == NULL) {
      list->end = new_node;
    }
  } else if (position == list->length) {
    new_node->prev = list->end;
    new_node->next = NULL;
    list->end->next = new_node;
    list->end = new_node;
  } else {
    struct Node* aux = list->init;
    for (int i = 0; i < position - 1; i++) {
      aux = aux->next;
    }

    new_node->prev = aux;
    new_node->next = aux->next;
    aux->next = new_node;
  }

  list->length++;
}

int length(struct List* list) {
  assert(list != NULL);
  return list->length;
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

int read(struct List* list, int position) {
  assert(list != NULL);
  assert(position >= 0 && position < list->length);
  
  struct Node* aux;

  if (position == 0) {
    aux = list->init;
  } else if (position == list->length -1) {
    aux = list->end;
  } else {
    aux = list->init;
    for (int i = 0; i < position; i++) {
      aux = aux->next;
    }
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

  struct Node* aux = NULL;

  if (position == 0) {
    aux = list->init;
    list->init = aux->next;
    if (list->init == NULL) {
      list->end = NULL;
    } else {
      list->init->prev = NULL;
    } 
  } else if (position == list->length - 1) {
    aux = list->end;
    list->end = aux->prev;
    list->end->next = NULL;
  } else {
    struct Node* previousNode = NULL;
    aux = list->init;

    for (int i = 0; i < position; i++) {
      previousNode->next = aux->next;
      aux->next->prev = previousNode;
    }

    int item = aux->info;
    list->length--;
    
    free(aux);

    return item;
  }
}

bool containsItem(struct List* list, int item) {
    assert(list != NULL);
    struct Node* currentNode = list->init;
  
    while (currentNode != NULL) {
        if (currentNode->info == item) {
            return true;
        }

        currentNode = currentNode->next;
    }

    return false;
}

int findIndexOfMinValue(struct List* list) {
    assert(list != NULL);
    struct Node* currentNode = list->init;

    int minPosition = 0, min = currentNode->info;
    for (int i = 0; i < list->length; i++) {
        if (currentNode->info < min) {
            minPosition = i;
            min = currentNode->info;
        }

        currentNode = currentNode->next;
    }

    return minPosition;
}

void freeMemoryList(struct List* list) {
  while(empty(list) == false) {
    remove_item(list, 0);
  }
  free(list);
}

struct Enemy {
    const char* name;
    int distanceFromPlayer;
};

int main() {
  struct Enemy enemy1, enemy2, enemy3;
  enemy1.name = "Darth Vader";
  enemy1.distanceFromPlayer = 10;

  enemy2.name = "Joker";
  enemy2.distanceFromPlayer = 3;

  enemy3.name = "Bowser";
  enemy3.distanceFromPlayer = 15;

  struct Enemy enemies[3] = {enemy1, enemy2, enemy3};

  struct List* distance_list = create();

  insert(distance_list, 0, enemy1.distanceFromPlayer);
  insert(distance_list, 0, enemy2.distanceFromPlayer);
  insert(distance_list, 0, enemy3.distanceFromPlayer);

  int closestEnemyPosition = findIndexOfMinValue(distance_list);

  printf("\nThe closest enemy to the player is: %s\n", enemies[closestEnemyPosition].name);


  return 0;
}