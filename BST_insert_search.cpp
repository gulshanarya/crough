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

int FindMin(BstNode* root) { //here root is local to function
    if(root == NULL) {
        printf("Error: empty tree\n");
        return -1;
    }
    while(root->left != NULL) { //transversing lesser parts to find min
        root = root->left;
    }

    return root->data;
}

int FindMinR(BstNode* root) { //min using recursion  //here root is local to function
    if(root == NULL) {
        printf("Error: empty tree\n");
        return -1;
    } else if(root->left == NULL) {//base case
        return root->data;
    }

    //searching recursively in right subtree
    return FindMinR(root->left);
}

int FindMax(BstNode* root) { //here root is local to function

    if(root == NULL) {
        printf("Error: empty tree\n");
        return -1;
    }
    while(root->right != NULL) { //transversing greater parts to find max
        root = root->right;
    }

    return root->data;
}

int FindMaxR(BstNode* root) { //max using recursion //here root is local to function

    if(root == NULL) {
        printf("Error: empty tree\n");
        return -1;
    } else if(root->right == NULL) { //base case
        return root->data;
    }

    //searching recursively in right subtree
    return FindMaxR(root->right);
}

int FindHeight(BstNode* root) { //counting edges in finding height not nodes and O(n)
    if(root == NULL) { //base case
        return -1; //Height of an empty tree is -1 when root=NULL
        //return 0; if we consider nodes as height measure
    }
    return max(FindHeight(root->left), FindHeight(root->right))+1;
}

int main() {
    root = NULL; //empty tree if root is NULL

    root = Insert(root, 15);
    Insert(root, 25);
    Insert(root, 5);
    Insert(root, 65);
    Insert(root, 125);
    Insert(root, 3);
    Insert(root, 89);

    cout<<"Height: "<<FindHeight(root)<<endl;

    cout<<"Max value: "<<FindMax(root) <<endl;
    cout<<"Min value: "<<FindMin(root)<<endl;

    cout<<"Max value using Recursion: "<<FindMaxR(root) <<endl;
    cout<<"Min value using Recursion: "<<FindMinR(root) <<endl;

    // Ask user to enter a number.
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
    return 0;
}

