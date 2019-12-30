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

    if(tmp->next != NULL) //not inserting at the end of list
        tmp->next->prev = tmp;

}

void DeletionAtBegin() {
    if(head == NULL) {
        printf("Underflow\n");
        return;
    }

    if(head->next == NULL) { //only one node in the list
        free(head);
        head = NULL;
        return;
    }

    struct Node* tmp = head;
    head = head->next;
    head->prev = NULL;

    free(tmp);
}

void DeletionAtEnd() {

    if(head == NULL) {
        printf("OVERFLOW\n");
        return;
    }

    if(head->next == NULL) { //if there is only one node
        free(head);
        head = NULL;
        return;
    }

    struct Node* tmp = head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->prev->next = NULL;
    free(tmp);
}

void DeleteNode(int data) { //deleting node with the specified data

    if(head == NULL) {
        printf("OVERFLOW\n");
        return;
    }

    if(head->next == NULL) { //if there is only one node
        if(data = head->data) {
            free(head);
            head = NULL;
            return;
        } else {
            printf("No any elements matched with %d!", data);
            return;
        }
    }

    struct Node* tmp = head;
    while(tmp->data != data) {
        tmp = tmp->next;
        if(tmp == NULL) {
            printf("No any elements matched with %d!\n", data);
            return;
        }
    }

    tmp->prev->next = tmp->next;
    if(tmp->next != NULL) { //not deleting the last node of list
        tmp->next->prev = tmp->prev;
    }

    free(tmp);
}

int Pos(int data) {

    if(head == NULL) {
        return -1;
    }
    int pos = 0;
    struct Node* tmp = head;
    while(tmp->data != data) {

        tmp = tmp->next;

        if(tmp == NULL) {//checking end of list
            return -1;
        }

        pos++;
    }

    return pos;
}

void printNode() {
    struct Node* tmp = head;

    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main() {


        printf("%d\n", Pos(20));
    InsertAtN(0, 3);
    InsertAtN(1, 10);
    InsertAtN(2, 20);
    InsertAtEnd(65);

    printNode();
    return 0;
}
