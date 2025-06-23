#include <bits/stdc++.h>
using namespace std;

//AVL Tree Node
struct Node{
    int key;
    Node *left, *right;
    int height;

    Node(int val){
        key = val;
        left = right = NULL;
        height = 1; // New node is initially added at leaf
    }
};

//Get height of a node
int height(Node *node){
    if(!node) return 0; 
    return node->height;
}

// Get balance factor
int getBalance(Node *node){
    if(!node) return 0;
    return height(node->left) - height(node->right); 
}

// Update height
void updateHeight(Node *node){
    node->height = 1 + max(height(node->left), height(node->right));
}

// Right rotate (for Left-Left case)
Node* rightRotate(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;

    //Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x; // new root
}

Node* leftRotate(Node *y){
    Node *x = y->right;
    Node *T2 = x->left;

    // Perform rotation
    x->left = y;
    y->right= T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x; // new root
}

// Insert node into AVL Tree
Node* insert(Node *root, int key){
    // Normal BST insertion
    if(!root) return new Node(key);
    if(key < root->key){
        root->left = insert(root->left, key);
    }
    else if(key > root->key){
        root->right = insert(root->right, key);
    }
    else{ //Duplicates not allowed
        return root;
    }

    // Update height of this ancestor node
    updateHeight(root);

    // Get balance factor
    int balance = getBalance(root);

    // Balance cases
    // Left Left
    if(balance > 1 && key < root->left->key){     
        return rightRotate(root);
    }

    // Right Right
    if(balance < -1 && key > root->right->key){
        return leftRotate(root);
    }

    // Left Right
    if(balance > 1 && key > root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // unchanged
}

void preorder(Node *root){
    if(!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    Node *root = NULL;

    vector<int> values = {10, 20, 30, 40, 50, 25};
    for(int val: values){
        root = insert(root, val);
    }

    cout << "Preorder of AVL Tree: ";
    preorder(root);
    cout << endl;
    
    return 0;
}