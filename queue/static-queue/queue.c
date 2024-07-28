#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue(){
  Queue* q = (Queue*) malloc(sizeof(Queue));

  if(q != NULL){
    q->front = 0;
    q->rear = 0;
    q->size = 0;
  }

  return q;
}

void destroyQueue(Queue* q){
  free(q);
}

int size(Queue* q){
  if(q == NULL) return -1;

  return q->size;
}

int isEmpty(Queue* q){
  if(q == NULL) return -1;

  if(q->size == 0) return 1;

  return 0;
}

int isFull(Queue* q){
  if(q == NULL) return -1;

  if (q->size == MAX) return 1;

  return 0;
}

int enqueue(Queue* q, Student student){
  if(q == NULL) return 0;

  if(isFull(q)) return 0;

  q->data[q->rear] = student;

  q->rear = (q->rear + 1) % MAX;

  q->size++;

  return 1;
}

int dequeue(Queue* q, Student* student){
  if(q == NULL || isEmpty(q)) return 0;

  *student = q->data[q->front];

  q->front = (q->front + 1) % MAX;

  q->size--;

  return 1;
}