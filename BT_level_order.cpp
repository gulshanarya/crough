//level order traversal (breadth-first)

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>

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


//traversing tree with levelorder
void LevelOrder(BstNode* root) {

    if(root == NULL) return; //base case

    queue<BstNode*> Q; //using c++ std queue
    Q.push(root); //one discovered node initially

    //while there is at lease one discovered node
    while(!Q.empty()) {
        BstNode* current = Q.front();
        cout<< current->data<<" ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();//deleting front element
    }
}

int main() {
    root = NULL; //empty tree if root is NULL

    root = Insert(root, 15);
    Insert(root, 25);
    LevelOrder(root);
    return 0;
}

