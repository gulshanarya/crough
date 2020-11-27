#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct Node {
    float data;
    struct Node* next;
} Node;

struct Node* head;

typedef struct List {
    void (*append)(float elm);
    char (*get)();
    void (*rem)();
    int (*isEmpty)();

} List;

List list(int, ...);

#endif // LIST_H_INCLUDED
