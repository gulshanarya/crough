// Stack - Linked List based implementation.

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;

void Push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top; //since top is already null for empty
    top = temp;
}

void Pop() {
    struct Node* temp;
    if(top == NULL) return;
    temp = top;
    top = top->link;
    free(temp);
}

void Print() {
    struct Node* temp = top;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

int isEmpty() {
    if (top == NULL)
        return 1;
    else
        return 0;
}

int Top() {
    return top->data;
}

int main() {
  // Code to test the implementation.
	Push(2);
	Push(5);
	Push(10);
	Push(12);
	Pop();
	Pop();
	Print();
}
