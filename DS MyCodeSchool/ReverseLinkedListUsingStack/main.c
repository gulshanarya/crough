#include<stdio.h>
#include<stdlib.h>

//Linked List implementation for reversing using stack
struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** pointerTohead, int x) {
    struct Node * temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *pointerTohead; //since head is already NULL for empty list
    *pointerTohead = temp;
}

void printNode(struct Node* head) {

    printf("List is");
    while(head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

// Stack - Linked List based implementation for reversing Linked List
struct stackNode {
    struct Node* node;
    struct stackNode* link;
};

//global Linked List stack and linked list
struct stackNode* top = NULL;
struct Node* head = NULL;


void Push(struct Node* node) {
    struct stackNode* temp = (struct stackNode*)malloc(sizeof(struct stackNode));
    temp->node = node;
    temp->link = top; //since top is already null for empty
    top = temp;
}

void Pop() {
    struct stackNode* temp;
    if(top == NULL) return;
    temp = top;
    top = top->link;
    free(temp);
}

//void Print() {
//    struct stackNode* temp = top;
//
//    while(temp != NULL) {
//        printf("%d ", temp->data);
//        temp = temp->link;
//    }
//}

int isEmpty() {
    if (top == NULL)
        return 1;
    else
        return 0;
}

struct Node* Top() {
    return top->node;
}

//end of stack implementation

//reversing Linked List using stack (O(n))
void Reverse() {
    struct Node* temp = head;
    while(temp != NULL) {
        Push(temp); //pushing in global stack top
        temp = temp->next;
    }
    temp = Top();
    head = temp;
    Pop();

    while(!isEmpty()) {
        temp->next = Top();
        Pop();
        temp = temp->next;
    }
    temp->next = NULL; //since NULL isn't in the bottom of stack
}

int main(){

    insert(&head, 45);
    insert(&head, 48);
    insert(&head, 49);

    printNode(head);
    Reverse();
    printNode(head);
    return 0;
}

