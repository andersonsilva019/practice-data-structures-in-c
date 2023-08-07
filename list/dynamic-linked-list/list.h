// list.h
#include <stdbool.h>

typedef struct node_t node_t;

typedef struct student_t student_t;

typedef node_t* List;

List* create_list();

void free_list(List* li);

int size_list(List* li);

bool is_full_list(List* li);

bool is_empty_list(List* li);

bool insert_in_front_list(List* li, student_t* student);

bool insert_in_end_list(List* li, student_t* student);

void show_list(List* li);

bool insert_in_order_list(List* li, student_t* student);

bool remove_from_front_list(List* li);

bool remove_from_end_list(List* li);

bool remove_from_order_list(List* li, unsigned int code);