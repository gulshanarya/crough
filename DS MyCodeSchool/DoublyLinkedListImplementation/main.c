/* Doubly Linked List implementation */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* getNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
};
void insertAtHead(int x) {
    struct Node* newNode = getNewNode(x);

    if(head == NULL) {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(int x) {
    struct Node* temp = head;
    struct Node* newNode = getNewNode(x);

    if(head == NULL) { //empty list
        head = newNode;
        return;
    }

    while(temp->next != NULL) temp = temp->next; // Go To last Node

    newNode->prev = temp;
    temp->next = newNode;
}

void printNode() {
    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reversePrint() {
    struct Node* temp = head;

    if(temp == NULL) { //empty list
        return;
    }

    while(temp->next != NULL) { //going to last node
        temp=temp->next;
    }

    printf("\nReversing...\n");
    //traversing backward using prev pointer
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main()
{
    head = NULL;
    insertAtHead(45);
    insertAtHead(67);
    insertAtHead(68);
    insertAtTail(34);
    insertAtTail(20);
    printNode();
    reversePrint();
    free(head);
    return 0;
}

