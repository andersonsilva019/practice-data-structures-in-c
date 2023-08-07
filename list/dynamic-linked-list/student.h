typedef struct student_t student_t;

student_t* student_init(unsigned int code, char* name, float n1, float n2, float n3);

char* student_get_name(student_t* student);

unsigned int student_get_code(student_t* student);


