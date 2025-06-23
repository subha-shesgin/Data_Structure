#include <iostream>
#include <vector>
#include <climits>  // for INT_MAX
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

Node* build(vector<int>& A, int& i, int bound) {
    if (i == A.size() || A[i] > bound) {
        return NULL;
    }
    Node* root = new Node(A[i++]);
    root->left = build(A, i, root->data);
    root->right = build(A, i, bound);
    return root;
}

Node* bstFromPreorder(vector<int>& A) {
    int i = 0;
    return build(A, i, INT_MAX);
}

// Postorder traversal for validation
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Node* root = bstFromPreorder(preorder);

    cout << "Postorder Traversal: ";
    postorder(root);  // Expected output: 1 7 5 12 10 8
    cout << endl;

    return 0;
}
