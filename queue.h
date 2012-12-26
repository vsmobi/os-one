struct Node {
    int ls;
    int frs;
    int *arr;
    struct Node * next;
};

struct Queue {
    struct Node * head;
    struct Node * tail;
};

typedef struct Alte {
    int last;
    int *array;
    int first;
} Alter;


struct Queue *new_queue(void);
void push(struct Queue* q, int *arr, int frs, int ls);
struct Node *pop(struct Queue* q);
