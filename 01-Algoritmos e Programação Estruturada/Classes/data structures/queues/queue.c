#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct Node {
  int info;
  struct Node* next;
};

struct Queue {
  struct Node* init;
  struct Node* end;
  int length;
};

struct Queue* create() {
  struct Queue* new_queue = malloc(sizeof(struct Queue));

  if (new_queue != NULL) {
    new_queue->init = NULL;
    new_queue->end = NULL;
    new_queue->length = 0;
  }

  return new_queue;
}

void place_on_queue(struct Queue* queue, int item) {
  assert(queue != NULL);

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  if (new_node != NULL) {
    new_node->info = item;
    new_node->next = NULL;

    if (queue->end != NULL) {
      queue->end->next = new_node;
    } else {
      queue->init = new_node;
    }
    queue->end = new_node;
    queue->length++;
  }
}

int unqueue(struct Queue* queue) {
    assert(queue != NULL);    
    assert(queue->init != NULL);
    struct Node* aux = queue->init;
    int item = aux->info;
    queue->init = aux->next;
    if (queue->init == NULL) {
        queue->end = NULL;    
    }
    queue->length--; 
    free(aux);
    return item;    
}

bool empty_queue(struct Queue* queue) {
  assert(queue != NULL);

  return (queue->init == NULL);
}

int length (struct Queue* queue) {
  assert(queue != NULL);

  return queue->length;
}

int init(struct Queue* queue) {
  assert(queue != NULL);
  assert(queue->init != NULL);

  return queue->init->info;
}

void freeMemoryQueue(struct Queue* queue) {
  assert(queue != NULL);
  
  while(queue->init != NULL) {
    unqueue(queue);
  }
  
  free(queue);
}

int main() {
    struct Queue* my_queue = create();
    place_on_queue(my_queue, 1);
    place_on_queue(my_queue, 2);
    place_on_queue(my_queue, 3);
    printf("Queue length: %d ", length(my_queue));

    printf("\nMy queue: [%d ", unqueue(my_queue));
    printf("%d ", unqueue(my_queue));
    printf("%d]", unqueue(my_queue));

    printf("\nIs queue empty? (1 - Yes, 0 - No): %d ", empty_queue(my_queue));

    freeMemoryQueue(my_queue);


    return 0;
}