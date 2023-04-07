#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* create_list(){
  List *list = (List*) malloc(sizeof(List));

  if(list == NULL) list->size = 0;

  return list;
}

void free_list(List *list){
  if(list != NULL){
    free(list);
  }
}

int list_is_full(List *list){
  if(list == NULL) return -1;
  return (list->size == MAX);
}

int list_is_empty(List *list){
  if(list == NULL) return -1;
  return (list->size == 0);
}

int list_size(List *list){
  if(list == NULL) return -1;
  return (list->size);
}

int list_insert_in_end(List* list, Student student){
  if(list == NULL) return 0;

  if(list->size == MAX) return 0;

  list->data[list->size] = student;

  list->size++;

  return 1;
}

int list_insert_in_front(List* list, Student student){
  if(list == NULL) return 0;
  if(list->size == MAX) return 0;

  for(int i = list->size - 1; i >= 0; i--){
    list->data[i + 1] = list->data[i];
  }

  list->data[0] = student;
  list->size++;

  return 1;
}

int list_insert_in_order(List* list, Student student){
  if(list == NULL) return 0;

  if(list->size == MAX) return 0;

  int i = 0;

  while (i < list->size && list->data[i].code < student.code) 
    i++;

  for(int j = list->size -1; j >= i; j--){
    list->data[j + 1] = list->data[j];
  }

  list->data[i] = student;
  list->size++;

  return 1;
}

int list_remove_from_front(List* list){
  if(list == NULL) return 0;

  if(list->size == 0) return 0;

  for(int i = 0; i < (list->size - 1); i++){
    list->data[i] = list->data[i + 1];
  }

  list->size--;

  return 1;
}

int list_remove_from_end(List *list){
  if(list == NULL) return 0;

  if(list->size == 0) return 0;

  list->size--;

  return 1;
}

int list_remove(List *list, int code){
  if(list == NULL) return 0;

  if(list->size == 0) return 0;

  int i = 0;

  while(i < list->size&& list->data[i].code != code){
    i++;
  }

  if(i == list->size) return 0;

  for(int j = i; j < list->size-1; j++){
    list->data[j] = list->data[j + 1];
  }

  list->size--;

  return 1;
}


int list_remove_improved(List* list, int code){
  if(list == NULL) return 0;

  if(list->size == 0) return 0;

  int i = 0;

  while(i < list->size&& list->data[i].code != code){
    i++;
  }

  if(i == list->size) return 0;

  list->data[i] = list->data[list->size-1];

  list->size--;

  return 1;
}

int list_find_by_index(List* list, int index, Student* student){
  if(list == NULL) return 0;

  if(index < 0 || index >= list->size) return 0;

  *student = list->data[index];

  return 1;
}

int list_find_by_code(List* list, int code, Student* student){
  if(list == NULL) return 0;

  int i = 0;

  while (i < list->size && list->data[i].code != code){
    i++;
  }

  if(i == list->size) return 0;

  *student = list->data[i];

  return 1;

}

void list_print(List* list){
  if(list == NULL) return;
  for(int i = 0; i < list->size; i++) printf("%d\n", list->data[i].code);
}
