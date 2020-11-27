#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    struct Node* head = NULL; //Empty List

    printf("How many numbers? \n");
    int n,i,x;

    scanf("%d",&n);

    for(i = 0; i < n; i++) {
        printf("Enter the number \n");
        scanf("%d", &x);
        insert(&head, x);
        printNode(head);
    }

    return 0;
}

