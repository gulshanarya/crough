#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
class BstNode {
    public:
        int data;
        BstNode *left;
        BstNode *right;
        BstNode(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

BstNode* Insert(BstNode* root, int data) {
    if(root == NULL) {
        root = new BstNode(data);
        return root;
    }

    if(data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }

    return root;
}

bool Search(BstNode* root, int data) {
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

void preOrder(BstNode* root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

BstNode* FindMin(BstNode* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

int FindHeight(BstNode* root) {
    if(root == NULL) return -1;
    return max(FindHeight(root->left),FindHeight(root->right))+1;
}

void LevelOrder(BstNode* root) {
    if(root == NULL) return;
    queue<BstNode*> nodeQue;
    nodeQue.push(root);
    while(!nodeQue.empty()) {
        BstNode* temp = nodeQue.front();
        nodeQue.pop();
        cout<<temp->data<<" ";
        if (temp->left != NULL) nodeQue.push(temp->left);
        if(temp->right != NULL) nodeQue.push(temp->right);
    }
}

bool IsSubtreeLesser(BstNode* root, int data) {
    if(root == NULL) return true;
    if(root->data < data && IsSubtreeLesser(root->left, data) && IsSubtreeLesser(root->right, data)) return true;
    else return false;
}

bool IsSubtreeGreater(BstNode* root, int data) {
    if(root == NULL) return true;
    if(root->data > data && IsSubtreeGreater(root->right, data) && IsSubtreeGreater(root->left, data)) return true;
    else return false;
}

bool IsBst(BstNode* root) {
    if(root == NULL) return true;
    if(IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBst(root->left) && IsBst(root->right)) {
        return true;
    }
    return false;
}

//alter
bool IsBstUtil(BstNode* root, int minValue, int maxValue) {
    if(root == NULL) return true;
    if(root->data > minValue && root->data < maxValue && IsBstUtil(root->left, minValue, root->data) && IsBstUtil(root->right, root->data, maxValue)) return true;
    else return false;
}

bool checkBst(BstNode* root) {
    return IsBstUtil(root, INT32_MIN, INT32_MAX);
}

bool chckBst(BstNode* root) {
    int temp = root->data;
    checkBst(root->left);
}

BstNode* Delete(BstNode* root, int data) {
    if(root == NULL) return NULL;
    if(data < root->data) {
        root->left = Delete(root->left, data);
    } else if(data > root->data) root->right = Delete(root->right, data);
    else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if(root->left == NULL) {
            BstNode* temp = root;
            root = root->right;
            delete temp;
        } else if(root->right == NULL) {
            BstNode* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            BstNode* minm = FindMin(root->right);
            root->data = minm->data;
            root->right = Delete(root->right, minm->data);
        }
    }
    return root;
}

BstNode* Find(BstNode* root, int data) {
    if(root == NULL) return NULL;
    else if(root->data == data) return root;
    else if(data <= root->data) return Find(root->left, data);
    else return Find(root->right, data);
}

BstNode* GetSuccessor(BstNode* root, int data) {
    BstNode* current = Find(root, data);

    if(current == NULL) return NULL;
    if(current->right != NULL) {
        return FindMin(current->right);
    }
    BstNode* succ = NULL;
    BstNode* ancesstor = root;
    while(ancesstor != current) {
        if(current->data <= ancesstor->data) {
            succ = ancesstor;
            ancesstor = ancesstor->left;
        } else {
            ancesstor = ancesstor->right;
        }
    }

    return succ;
}


int main() {
    BstNode* root = NULL;
    root = Insert(root, 45);
    root = Insert(root, 35);
    root = Insert(root, 25);
    root = Insert(root, 40);
    root = Insert(root, 55);
    root = Insert(root, 100);
    root = Insert(root, 105);

    //Delete(root, 35);
    GetSuccessor(root, 45)->data;
}

