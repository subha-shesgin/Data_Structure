#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Fixed preorder function
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    cout << "Preorder Traversal: ";
    preorder(root);  // Expected output: 1 2 5 3
    cout << endl;

    return 0;
}
