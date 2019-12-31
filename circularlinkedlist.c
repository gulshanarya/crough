#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
void InsertAtBegin(int data) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));

    tmp->data = data;
    if(head == NULL) {
        head = tmp;
        tmp->next = head;
        return;
    }

    struct Node* tmp2 = head;
    while(tmp2->next != head) {
        tmp2 = tmp2->next;
    }

    tmp->next = head;
    head = tmp; //head pointing to new Node
    tmp2->next = head; //next of last node pointing to new head

}

void InsertAtEnd(int data) {

    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = data;

    if(head == NULL) {
        head = tmp;
        tmp->next = head;
        return;
    }

    struct Node* tmp2 = head;
    while(tmp2->next != head) {
        tmp2 = tmp2->next;
    }

    tmp->next = head; //next of new node pointing to head
    tmp2->next = tmp; //next of old last node pointing to new Node
}

void DeletionAtBegin() {
    if(head == NULL) {
        printf("UNDERFLOW!");
        return;
    }

    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* tmp = head;
    while(tmp->next != head) {
        tmp = tmp->next;
    }

    tmp->next = head->next; //next of last node pointing to new head
    free(head);
    head = tmp->next; //new head Node

}

int Pos(int data) {

    if(head == NULL) { //when there is no any node
        printf("Empty List\n");
        return -1;
    }

    int pos = 0;
    struct Node* tmp = head;

    do {
        if(tmp->data == data)
            return pos;
        tmp = tmp->next;
        pos++;
    } while(tmp != head);

    return -1;
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

    InsertAtEnd(100);
    InsertAtEnd(200);
    InsertAtEnd(300);

    printf("%d\n", Pos(100));
    PrintNode();

    return 0;
}
