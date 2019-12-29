#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void InsertAtBegin(int data) {
    struct Node* tmp = malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = head;
    tmp->prev = NULL;

    if(head != NULL)
        head->prev = tmp;

    head = tmp;
}

void InsertAtEnd(int data) {
    struct Node* tmp = malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = NULL;

    if(head == NULL) {
        tmp->prev = head;
        head = tmp;
        return;
    }

    struct Node* tmp2 = head;
    while(tmp2->next != NULL) {
        tmp2 = tmp2->next;
    }

    tmp->prev = tmp2;
    tmp2->next = tmp;
}

void InsertAtN(int pos, int data) {
    struct Node* tmp = malloc(sizeof(struct Node));
    tmp->data = data;

    if(pos == 0) {
        tmp->prev = NULL;
        tmp->next = head;
        head = tmp;
        return;
    }

    struct Node* tmp2 = head;
    for(int i = 0; i < pos-1; i++) {
        tmp2 = tmp2->next;
        if(tmp2 == NULL) {
            printf("Out of Index\n");
            return;
        }
    }

    tmp->prev = tmp2;
    tmp->next = tmp2->next;
    tmp2->next = tmp;

}

void printNode() {
    struct Node* tmp = head;

    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
int main() {


    InsertAtN(0, 3);
    InsertAtN(1, 10);
    InsertAtBegin(2);

    printNode();
    return 0;
}
