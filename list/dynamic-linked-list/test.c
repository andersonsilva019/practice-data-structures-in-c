#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "student.h"

int main(){
    List* list = create_list();

    student_t* student1 = student_init(1, "Student 1", 10, 10, 10);
    student_t* student2 = student_init(2, "Student 2", 10, 10, 10);
    student_t* student3 = student_init(3, "Student 3", 10, 10, 10);
    student_t* student4 = student_init(4, "Student 4", 10, 10, 10);

    insert_in_front_list(list, student2);
    insert_in_front_list(list, student1);
    insert_in_end_list(list, student4);
    insert_in_order_list(list, student3);
    remove_from_front_list(list);

    if(list != NULL) printf("List created successfully! \n");

    printf("Size of the list: %d \n", size_list(list));

    show_list(list);

    free_list(list);
    
}