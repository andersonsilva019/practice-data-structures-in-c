#define MAX 100

typedef struct {
  int code;
  char name[100];
  float n1, n2, n3;
} Student;

typedef struct {
  int front, rear, size;
  Student data[MAX];
} Queue;

Queue* createQueue();

void destroyQueue(Queue* q);

int enqueue(Queue* q, Student student);

int dequeue(Queue* q, Student* student);

int isEmpty(Queue* q);

int isFull(Queue* q);

int size(Queue* q);