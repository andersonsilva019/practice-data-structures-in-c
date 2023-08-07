#include "student.h"
#include <stdlib.h>

struct student_t {
    unsigned int code;
    char* name;
    float n1, n2, n3;
};

student_t* student_init(unsigned int code, char* name, float n1, float n2, float n3){
    student_t* student = (student_t*) malloc(sizeof(student_t));

    if(student != NULL){
        student->code = code;
        student->name = name;
        student->n1 = n1;
        student->n2 = n2;
        student->n3 = n3;
    }

    return student;
}

char* student_get_name(student_t* student){
    if(student != NULL) return student->name;
}

unsigned int student_get_code(student_t* student){
    if(student != NULL) return student->code;
}