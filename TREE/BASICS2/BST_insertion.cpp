#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// BST Insertion
Node* insertionBST(Node *root, int val) {
    if (root == NULL)
        return new Node(val);

    Node *cur = root;
    while (true) {
        if (val >= cur->data) {
            if (cur->right != NULL) {
                cur = cur->right;
            } else {
                cur->right = new Node(val);
                break;
            }
        } else {
            if (cur->left != NULL) {
                cur = cur->left;
            } else {
                cur->left = new Node(val);
                break;
            }
        }
    }
    return root;
}

// BST Search
Node* searchBST(Node* root, int val) {
    while (root != NULL && root->data != val) {
        if (val < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// Optional: maxDepth
int maxDepth(Node *root) {
    if (root == NULL)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Insert a new value into the BST
    root = insertionBST(root, 8);

    // Search for a value
    int val = 5;
    Node *result = searchBST(root, val);

    if (result != NULL)
        cout << "Node with value " << val << " found." << endl;
    else
        cout << "Node with value " << val << " not found." << endl;

    return 0;
}
