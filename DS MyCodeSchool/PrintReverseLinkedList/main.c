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

void reversePrint(struct Node* p) {
    if(p == NULL) return; //Exit condition
    //printf("%d ", p->data); //for printing in forward but iterative approach is better than recursive
    reversePrint(p->next);
    printf("%d ", p->data); //for printing in reverse
}

int main()
{
    head = NULL;

    insert(9, 1); //8, 9, 12, 11, 20, 13
    insert(11, 2);
    insert(13, 3);
    insert(8, 1);
    insert(20, 4);
    insert(12, 3);
    reversePrint(head);

    free(head);
    return 0;
}

