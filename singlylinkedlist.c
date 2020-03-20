//compile cmd with warning and errors message: gcc source.c -Wall -o opt
//singly linked list implementation
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node {

    int data;
    struct Node* next;
};

struct Node* head = NULL;

void InsertAtBeginning(int data) {

    struct Node* tmp = malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = head;

    head = tmp;
}

void InsertAtEnd(int data) {
    struct Node* tmp = malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = NULL;

    if(head == NULL) {
        head = tmp;
        return;
    }


    struct Node* tmp2 = head;
    while(tmp2->next != NULL) {
        tmp2 = tmp2->next;
    }

    tmp2->next = tmp;
}

void DeletionAtBegin() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* tmp = head;
    head = head->next;

    free(tmp);
}

void DeletionAtEnd() {
    if(head == NULL) {
        printf("List is empty");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* tmp = head;

    while(tmp->next->next != NULL) {
        tmp = tmp->next;
    }

    struct Node* tmp2 = tmp->next; //last node for deletion
    tmp->next = NULL;

    free(tmp2);
}

void Remove(int pos) {

    if(head == NULL) {
        printf("List is empty!");
        return;
    }

    struct Node* tmp = head;
    if(pos == 0) {
        head = tmp->next;
        free(tmp);
        return;
    }

    while((pos--) != 1) {
        tmp = tmp->next;
        if(tmp->next == NULL) {
            printf("Out of Index.\n");
            return;
        }
    }

    struct Node* tmp2 = tmp->next->next;
    free(tmp->next);

    tmp->next = tmp2;
}

void PrintNode() {

    struct Node* tmp = head;
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}


void InsertAtN(int pos, int data) {

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    if(pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* tmp = head;
    while(--pos != 0) {
        tmp = tmp->next;
        if(tmp == NULL) {
            printf("Out of Index\n");
            return;
        }
    }

    newNode->next = tmp->next;
    tmp->next = newNode;

}

int main() {

//    InsertAtBeginning(6);
//    InsertAtBeginning(7);
//    InsertAtBeginning(8);
//    InsertAtEnd(5);
//    InsertAtEnd(6);
//    InsertAtEnd(7);
//    InsertAtEnd(8);
//    DeletionAtEnd();
//    DeletionAtEnd();
//    DeletionAtEnd();
//    DeletionAtEnd();
//    InsertAtEnd(5);
//    InsertAtEnd(8);


    InsertAtN(0, 5);
    InsertAtN(1, 8);
    InsertAtN(1, 9);

    PrintNode();
	return 0;
}
