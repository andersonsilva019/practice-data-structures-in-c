#define MAX 100

typedef struct {
  int code;
  char name[30];
  float n1, n2, n3;
} Student;

typedef struct{
  int size;
  Student data[MAX];
} List;

List* create_list();

void free_list(List* list);

int list_size(List* list);

int list_is_full(List* list);

int list_is_empty(List* list);

int list_find_by_index(List* list, int index, Student* student);

int list_find_by_code(List* list, int code, Student* student);

int list_insert_in_front(List* list, Student student);

int list_insert_in_end(List* list, Student student);

int list_insert_in_order(List* list, Student student);

int list_remove(List* list, int code);

int list_remove_from_end(List* list);

int list_remove_from_front(List* list);

int list_remove_improved(List* list, int code);

void list_print(List* list);
