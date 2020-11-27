#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head;

void insert(int data, int n) {

    struct Node* trav = head;

    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;

    if(head == NULL || n == 1) {
        temp->next = head;
        head = temp;
        return;
    } else {
        while(n-2 > 0) {
            trav = trav->next;
            n -= 1;
        }

        temp->next = trav->next;
        trav->next = temp;
    }

}

void printNode() {
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void deleteNode(int n) {
    struct Node* temp1 = head;
    if(n == 1) {
        head = head->next; //head now points to the 2nd node
        free(temp1);
        return;
    }
    //only if n != 1
    for(int i = 0; i<n-2; i++) {
        temp1 = temp1->next; //temp1 points to the (n-1)th position
    }

    struct Node* temp2 = temp1->next; //temp2 points to the (n)th position
    temp1->next = temp2->next; //(n+1)th node
    free(temp2);
}

void reverse() {
    struct Node* prev = NULL; //previous node
    struct Node* current = head; //traversing
    struct Node* next = head; //storing next next node temporary for traversing
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

};
int main()
{
    head = NULL;

    insert(9, 1); //8, 9, 12, 11, 20, 13
    insert(11, 2);
    insert(13, 3);
    insert(8, 1);
    insert(20, 4);
    insert(12, 3);
    reverse();
    printNode();
    free(head);
    return 0;
}

