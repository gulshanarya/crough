/* #### stack Implementation using linked list #### */
#include<stdlib.h>
#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* head = NULL;

void Push(int data) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));

    if(tmp == NULL) { //heap is full
        printf("Out Of Space!");
        return;
    }

    tmp->data = data;
    tmp->next = head;
    head = tmp;
}

int Pop() {
    if(head == NULL) {
        printf("UNDERFLOW\n");
        return 0;
    }

    struct Node* tmp = head;
    head = head->next;

    int data = tmp->data; //popped data
    free(tmp);
    return data;
}

void PrintNode() {
    struct Node* tmp = head;
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main() {

    Push(45);
    Push(70);
    Pop();
    Push(80);
    Push(90);
    PrintNode();
    return 0;
}
