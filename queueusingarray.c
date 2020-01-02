#include<stdlib.h>
#include<stdio.h>
#define defVal -1

int queue[10];
int front = -1,rear = -1; //it represents empty queue
int len = sizeof(queue)/sizeof(int); //length of queue

int IsEmpty() {
    if(front == -1&&rear == -1) return 1; else return 0;
}

int IsFull() {
    if(rear == (len-1)) return 1; else return 0;
}

void Insert(int data) {
    if(IsFull()) {
        printf("OVERFLOW\n");
        return;
    }
    else if(IsEmpty()) {
        front = rear = 0;
    } else{
        rear++;
    }
    queue[rear] = data;
}

void Dequeue() {
    if(IsEmpty()) {
        printf("UNDERFLOW\n");
    } else if(front == rear) {
        front = rear = -1; //it represents empty queue
    } else front++;
}

void Print() {
    if(rear == -1) {
        printf("Empty queue");
        return;
    }
    for(int i = front; i<= rear; i++) printf("%d ", queue[i]);
}

int main() {

    Insert(45);
    Insert(60);
    Insert(100);
    Dequeue();
    Print();
    return 0;
}
