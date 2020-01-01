#include<stdio.h>
#include<stdlib.h>
int stack[10];
int top = -1; //empty stack
int n  = 10; //size of stack

void Push(int data) {
    if(top == 10) {
        printf("OVERFLOW\n");
        return;
    }

    stack[++top] = data;
}

int Pop() {
    if(top == -1) {
        printf("UNDERFLOW\n");
        return 0;
    }

    return stack[top--]; //return top value and decrease top
}

int Peek() {
    if(top == -1) {
        printf("UNDERFLOW\n");
        return 0;
    }

    return stack[top];
}

void PrintStack() { //print top to bottom
    int tmp = top;
    while(tmp != -1) {
        printf("%d ", stack[tmp]);
        tmp--;
    }
}

int main() {

    Push(45);
    Push(50);
    Pop();
    Push(55);
    PrintStack();
    printf("\n%d ", Peek());
    return 0;
}
