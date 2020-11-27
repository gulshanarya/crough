
#include<stdlib.h>
#include <stdarg.h>
#include<stdio.h>
#include "list.h"

void append(float elm) {
    //appending at the beginning of list
    Node* temp1 = malloc(sizeof(Node));
    temp1->data = elm;
    temp1->next = head;
    head = temp1;
    return;
//    Node* temp2 = head;
//    while(temp2->next != NULL) {
//        temp2 = temp2->next;
//    }
//
//    temp2->next = temp1;
}

float get() {
    if(head == NULL) {
        return '\0';
    }
    return head->data; //getting node of beginning of list O(1)
}

void rem() {
    if(head == NULL) {
        return;
    }
    struct Node* temp = head; //removing at the beginning of list O(1)
    head = head->next;
    free(temp);
}

List list(int num, ...) {
    Node* temp = malloc(sizeof(Node));
    List list;

    //method on list
    list.append = append;
    list.get = get;
    list.rem = rem;

    if(num == 0) {
        return list; //empty list
    } else {
        return list;
        //#error Only 0 allowed as argument in list
        //below func will add later
    }
    //below func will add later not working

    //one arg num must required
    temp->data = num;
    temp->next = NULL;
    head = temp;

    va_list valist;
    va_start(valist, num);

    Node* temp2 = head;
    for(int i = 0; i< num; i++) {

        temp = malloc(sizeof(Node));
        temp->data = va_arg(valist, int);
        temp->next = NULL;

        temp2->next = temp;
        temp2 = temp;
    }

    va_end(valist);
    return list;
}
