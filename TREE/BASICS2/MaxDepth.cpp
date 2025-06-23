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

int maxDepth(Node* root) {
    if (root == NULL) {
        return 0;  // ✅ Return 0 for NULL nodes
    }

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    cout << "Maximum depth of the tree: " << maxDepth(root) << endl;

    return 0;
}
