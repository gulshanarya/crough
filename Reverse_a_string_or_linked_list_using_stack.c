//implementation of reverse linked list and string using stack

#include <iostream>
#include<string>
#include<stack>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

//Linked List insertion at beginning
void InsertAtBeginning(int data) {

    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = head;

    head = tmp;
}

//reversing string using stack
void Reverse(string &name) {
    stack<char> S;
    for(int i = 0; i<name.length(); i++) {
        S.push(name[i]);
    }

    for(int i = 0; i<name.length(); i++) {
        name[i] = S.top();
        S.pop();
    }
}

//reversing LinkedList using stack
void ReverseList() {
    if(head == NULL) return;

    struct Node* tmp = head;

    //stack for storing List Node addresses
    stack<struct Node*> S;

    while(tmp != NULL) {
        S.push(tmp);
        tmp = tmp->next;
    }


    head = S.top();
    S.pop();
    tmp = head;
    while(!S.empty()) {
        tmp->next = S.top();
        S.pop();
        tmp = tmp->next;
    }

    tmp->next = NULL;//setting reversed next of Last Node Null
}

//printing linked list data
void PrintNode() {

    struct Node* tmp = head;
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main() {

//reversing string
    string name = "\ngulshan";
    Reverse(name);
    cout<<name;

//reversing linked list using stack
    InsertAtBeginning(45);
    InsertAtBeginning(65);
    InsertAtBeginning(75);
   PrintNode();
    ReverseList();
   PrintNode();
  return 0;
}

