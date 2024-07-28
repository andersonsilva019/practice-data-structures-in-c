#include <stdio.h>
#include "queue.h"

int main(){

  Queue* queue = createQueue();

  Student student1 = { 1, "Joao", 10, 10, 10 };
  Student student2 = { 2, "Maria", 10, 10, 10 };
  Student student3 = { 3, "Pedro", 10, 10, 10 };
  Student student4 = { 4, "Otávio", 10, 10, 10 };

  if(enqueue(queue, student2)){
    printf("Estudante com matricula %d foi inserido. \n", student2.code);
  }

  if(enqueue(queue, student1)){
    printf("Estudante com matricula %d foi inserido. \n", student1.code);
  }

  if(enqueue(queue, student3)){
    printf("Estudante com matricula %d foi inserido. \n", student3.code);
  }

  if(enqueue(queue, student4)){
    printf("Estudante com matricula %d foi inserido. \n", student4.code);
  }
  
  printf("Tamanho da fila: %d\n", size(queue));

  if(dequeue(queue, &student1)){
    printf("Estudante com matricula %d foi removido. \n", student1.code);
  }


  if(dequeue(queue, &student2)){
    printf("Estudante com matricula %d foi removido. \n", student2.code);
  }

  if(dequeue(queue, &student3)){
    printf("Estudante com matricula %d foi removido. \n", student3.code);
  }

  if(dequeue(queue, &student4)){
    printf("Estudante com matricula %d foi removido. \n", student4.code);
  }

  printf("Tamanho da fila: %d\n", size(queue));

  destroyQueue(queue);
  return 0;
}