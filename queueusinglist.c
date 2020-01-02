#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node* next;
};

//NULL represents empty queue
struct Node* front = NULL;
struct Node* rear = NULL;

void Insert(int data) {

    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));

    if(tmp == NULL)  {
        printf("OVERFLOW\n");
        return;
    }

    tmp->data = data;
    tmp->next = NULL;

    if(front == NULL) { //empty queue
        front = rear = tmp;
        return;
    }

    rear->next = tmp;
    rear = tmp;

}

void Dequeue() {
    if(front == NULL) {
        printf("UNDERFLOW\n");
        return;
    }

    struct Node* tmp = front;
    if(front == rear) { //only one node
        front = rear = NULL;
    } else {
        front = front->next;
    }

    free(tmp);
}

int Front() {
    if(front == NULL) {
        printf("Empty queue");
        return 0;
    }

    return front->data;
}

void PrintNode() {
    struct Node* tmp = front;
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
int main() {
    Insert(45);
    Insert(60);
    Dequeue();
    Insert(80);
    Insert(85);

    PrintNode();
    printf("\n%d", Front());
    return 0;
}
