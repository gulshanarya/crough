#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* root; //storing the address of the root node

BstNode* GetNewNode(int data) { //creating a new node
    BstNode* newNode = new BstNode(); //we can use malloc of C as well
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data) {
    if(root == NULL) {
        root = GetNewNode(data);
    } else if(data <= root->data) {
        root->left = Insert(root->left, data); //recursive call
    } else {
        root->right = Insert(root->right, data); //recursive call
    }
    return root;

}

bool Search(BstNode* root, int data) {
    if(root == NULL) return false;
    if(root->data == data) return true;
    else if(data < root->data) {
        //transverse left side
        return Search(root->left, data);
    } else {
        //transverse right side
        return Search(root->right, data);
    }
}

int main() {

    root = NULL; //empty tree if root is NULL

    root = Insert(root, 15);
    Insert(root, 25);
    Insert(root, 5);
    Insert(root, 65);

    // Ask user to enter a number.
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
    return 0;
}

