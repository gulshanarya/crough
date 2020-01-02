#include<stdlib.h>
#include<stdio.h>

int queue[10];
int front = -1,rear = -1; //it represents empty queue
int len = sizeof(queue)/sizeof(int); //length of queue
//next = (rear+1)%len; //next data in circular array
//Note: prev pos = (rear+len-1)%len here: adding len have no effects just to be sure pos is +ve when rear = 0

int IsEmpty() {
    if(front == -1&&rear == -1) return 1; else return 0;
}

int IsFull() {
    if((rear+1)%len == front) return 1; else return 0;
}

void Insert(int data) {
    if(IsFull()) {
        printf("OVERFLOW\n");
        return;
    }
    else if(IsEmpty()) {
        front = rear = 0;
    } else{
        rear = (rear+1)%len;
    }
    queue[rear] = data;
}

int Front() { // 0 represents empty queue
    if(rear == -1) {
        printf("Empty queue\n");
        return 0;
    }

    return queue[front];
}

void Dequeue() {
    if(IsEmpty()) {
        printf("UNDERFLOW\n");
    } else if(front == rear) {
        front = rear = -1; //it represents empty queue
    } else front = (front+1)%len;
}

void Print() {
    if(rear == -1) {
        printf("Empty queue");
        return;
    }

    int tmp = front;
    while(tmp != rear) {
        printf("%d ", queue[tmp]);
        tmp = (tmp+1)%len;
    }

    printf("%d ", queue[tmp]);
}

int main() {
    Insert(45);

    Dequeue();
    Insert(110);
    Insert(120);
    Print();
    printf("\n%d", Front());
    return 0;
}
