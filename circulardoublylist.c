#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void InsertAtBegin(int data) {

    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->data = data;

    if(head == NULL) {
        head = tmp;
        tmp->next = head;
        tmp->prev = head;
        return;
    }

//  old: it can be done directrly since head->prev is the last node
//    struct Node* tmp2 = head;
//    while(tmp2->next != head) { //traversing to point the last node to new head node
//        tmp2 = tmp2->next;
//    }

    tmp->next = head;
    tmp->prev = head->prev;

    head->prev = tmp;

    head = tmp;

    head->prev->next = head; //next of last node point to new head node
}

void InsertAtEnd(int data) {
    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->data = data;

    if(head == NULL) {
        head = tmp;
        tmp->next = head;
        tmp->prev = head;
        return;
    }

    tmp->next = head;
    tmp->prev = head->prev;//since head->prev points to the last node
    head->prev->next = tmp;
    head->prev = tmp;
}

void DeleteAtBegin() {
    if(head == NULL) {
        printf("UNDERFLOW\n");
        return;
    }

    if(head->next == head) { //only one node in list
        free(head);
        head = NULL;
        return;
    }

    head->prev->next = head->next; //head prev pointing to last node of list
    head->next->prev = head->prev;
    struct Node* tmp = head;
    head = head->next;

    free(tmp);
}

void DeleteAtEnd() {
    if(head == NULL) {
        printf("UNDERFLOW\n");
        return;
    }

    if(head->next == head) { //only one node in list
        free(head);
        head = NULL;
        return;
    }

    struct Node* tmp = head->prev; //last node of the list
    tmp->prev->next = head;
    head->prev = tmp->prev;

    free(tmp);
}

void PrintNode() {

    if(head == NULL) { //when there is no any node
        return;
    }

    struct Node* tmp = head;
    while(tmp->next != head) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

    printf("%d ", tmp->data); //last node data
}


int main() {

    InsertAtEnd(5);
    InsertAtEnd(10);
    InsertAtEnd(20);
    DeleteAtEnd();
    DeleteAtEnd();

    InsertAtEnd(15);
    DeleteAtEnd();
    InsertAtEnd(15);

    PrintNode();
    return 0;
}
