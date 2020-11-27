//Implementation of Queues
//insertion at the tail or rear of queue
//deletion at the other end front or head of queue

#include<stdlib.h>
#include<stdio.h>

int A[10];
int front, rear;
int arraySize = sizeof(A)/sizeof(A[0]);

int IsEmpty() {
    if(front == -1 && rear == -1) {
        return 1; //true
    } else {
        return 0; //false
    }
}

int IsFull() {

    if(rear == 10 && front == 0) {
        printf("Array is Full");
        return 1;
    }
    return 0;
}

int Front() {
    if(front != -1) //Queue is not empty
        return A[front];
}

void DeQueue() {
    if(IsEmpty()) {
        return;
    } else if(front == rear){
        front = rear = -1;
    } else {
        front = (front+1)%arraySize;
    }
}

void EnQueue(int x) {
    if((rear+1)%arraySize == front) {//array is full
        return;
    } else if(IsEmpty()) {
        front = 0, rear = 0;
    } else {
        rear =(rear+1)%arraySize; //since circular implementation
    }

    A[rear] = x;
}

int main() {

    front = -1, rear = -1; //Empty Queue

    EnQueue(5);
    EnQueue(10);
    DeQueue();
    DeQueue();
    EnQueue(15);
    EnQueue(25);
    DeQueue();
    DeQueue();
    printf("%d %d ", front, rear);
    for(int i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
