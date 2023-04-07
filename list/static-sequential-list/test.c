#include <stdio.h>
#include <assert.h>
#include "list.h"

void main(){
  Student student1 = { 0, "Joao", 10, 10, 10 };
  Student student2 = { 2, "Maria", 10, 10, 10 };
  Student student3 = { 3, "Pedro", 10, 10, 10 };
  Student student4 = { 1, "Pedro", 10, 10, 10 };
  Student student5;
  Student student6;

  List *list = create_list();

  if(list_insert_in_front(list, student1) == 1){
    printf("Estudante com matricula %d foi adicionado no inicio da lista. \n", student1.code);
  }

  if(list_insert_in_front(list, student2) == 1){
    printf("Estudante com matricula %d foi adicionado no inicio da lista. \n", student2.code);
  }

  if(list_insert_in_end(list, student3) == 1){
    printf("Estudante com matricula %d foi adicionado no final da lista. \n", student3.code);
  }

  if(list_insert_in_order(list, student4) == 1){
    printf("Estudante com matricula %d foi adicionado em sua posição. \n", student4.code);
  }
  
  list_print(list);

  list_remove_from_front(list);

  printf("-------\n");

  list_print(list);

  list_remove(list, 0);

  printf("-------\n");

  list_print(list);

  //list_remove_from_end(list);

  printf("-------\n");

  list_print(list);

  list_find_by_index(list, 0, &student5);

  list_find_by_code(list, 3, &student6);

  printf("%s\n", student5.name);
  printf("%s\n", student6.name);
}