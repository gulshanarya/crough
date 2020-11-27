#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Node {
    float data;
    struct Node* next;
} Node;

struct Node* head;

typedef struct List {
    void (*append)(float elm);
    float (*get)();
    void (*rem)();
} List;

List list(int, ...);

#endif // LIST_H_INCLUDED
