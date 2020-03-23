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


//depth-first traversal
void PreOrder(BstNode* root) {
    if(root == NULL) return; //base case
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(BstNode* root) {
    if(root == NULL) return; //base case
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

void PostOrder(BstNode* root) {
    if(root == NULL) return; //base case
    printf("%d ", root->data);
    PostOrder(root->left);
    PostOrder(root->right);
}

void inOrder(BstNode* root) {
    if(root == NULL) return; //base case
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

//this is not the best approach for checking BST
bool IsSubtreeLesser(BstNode* root, int value) {
    if(root == NULL) return true;

    if(root->data <= value && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value))
        return true;
    else return false;
}

bool IsSubtreeGreater(BstNode* root, int value) {
    if(root == NULL) return true;
    if(root->data > value && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value))
        return true;
    else return false;
}

bool IsBST(BstNode* root) { //comparing each node value to all the nodes in left and right using above two functions that is not efficient O(n^2)
    if(root == NULL) return true;
    if(IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBST(root->left) && IsBST(root->right)) {
        return true;
    } else return false;

}


//another way finding Is Binary Search tree using range of left and right subtree
//this is utility of IsBST2 for not passing the arguments minValue and maxValue
bool IsBstUtil(BstNode* root, int minValue, int maxValue) {
    if(root == NULL) return true;
    if(root->data >= minValue && root->data < maxValue && IsBstUtil(root->left, minValue, root->data) && IsBstUtil(root->right, root->data, maxValue)) {
        return true;
    } else return false;
}

//check IsBst best approach
bool IsBST2(BstNode* root) {
    return IsBstUtil(root, INT8_MIN, INT8_MAX);
}

int prevValue = INT8_MIN; //setting minimum value of sorted list
//check IsBst using Inorder which gives sorted elements
bool IsBST3(BstNode* root) {
    if(root == NULL) return true; //base case
    IsBST3(root->left);
    if(prevValue <= root->data) {
        prevValue = root->data;
    } else {
        return false;
    }
    IsBST3(root->right);
    return true;
}

int main() {
    root = NULL; //empty tree if root is NULL

    root = Insert(root, 15);
    Insert(root, 10);
    Insert(root, 20);

    Insert(root, 60);
    Insert(root, 30);
    LevelOrder(root);
    printf("\n");
    PreOrder(root);
    printf("\n");
    InOrder(root);

    //testing IsBST
    cout<<IsBST(root)<<endl;
    cout<<IsBST2(root)<<endl;
    cout<<IsBST3(root)<<endl;


    return 0;
}

