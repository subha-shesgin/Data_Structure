#include <bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq){
        this->ch = ch;
        this->freq = freq;
        left = right = NULL;
    }
};

//Comparison for priority queue
struct Compare{
    bool operator()(Node *a, Node *b){
        return a->freq > b->freq; //Min-Heap
    }
};

//Generate Huffman Code
void generateCodes(Node *root, string code, unordered_map<char, string> &huffmanCode){
    if(!root) return; // if root is not null return aka if node exists

    if(!root->left && !root->right){ // if both left and right child does not exist
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

//Build Huffman Tree and return root
Node* buildHuffmanTree(const string &text){
    unordered_map<char, int> freq;
    for(char ch: text){
        freq[ch]++; //Find the frequency of each character
    }

    //Declares a priority queue that stores pointers to Node objects, 
    //and uses a custom comparison logic defined in a Compare struct.
    //vector<Node*>: The underlying container is a vector of Node*. 
    //(Priority queues are built on top of containers like vectors.)

    //works like a min-heap
    priority_queue<Node *, vector<Node *>, Compare> pq; 

    for(auto pair: freq){
        pq.push(new Node(pair.first, pair.second)); //Dynamically creates a new node
                                                    //Stores the character and its frequency from freq map
    }

    while(pq.size() > 1){
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    return pq.top();
}

//Encode a string using Hiffman Tree
string encode(const string &text, unordered_map<char, string> &huffmanCode){
    string encoded = "";
    for(char ch: text){
        encoded += huffmanCode[ch];
    }
    return encoded;
}

//Decode encoded string using Huffman Tree
string decode(const string &encodedStr, Node *root){
    string result = "";
    Node *curr = root;
    for(char bit: encodedStr){
        if(bit == '0') curr = curr->left;
        else curr = curr->right;

        if(!curr->left && !curr->right){ // when both children are null
            result += curr->ch;
            curr = root;
        }
    }
    return result;

}

int main(){

    string text = "huffman coding example";

    unordered_map<char, string> huffmanCode;
    Node *root = buildHuffmanTree(text);

    generateCodes(root, "", huffmanCode);

    cout << "Huffman Code:\n";
    for(auto pair: huffmanCode){
        cout << pair.first << " : " << pair.second << "\n";
    }

    string encoded = encode(text, huffmanCode);
    cout << "Encoded: " << encoded << "\n";

    string decoded = decode(encoded, root);
    cout << "Decoded: " << decoded << "\n";
    
    return 0;
}