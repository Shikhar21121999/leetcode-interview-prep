#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node () {
        this -> val = 0;
        this -> left = NULL;
        this -> right = NULL;
        this -> next = NULL;
    }
};

bool isLeaf(Node *root) {
    return (root -> left == nullptr and root -> right == nullptr);
}

// get nextRightNode for the children of this root
Node* getNextRightNode(Node *parent) {
    Node *root = parent -> next;
    while(root and isLeaf(root)) {
        root = root -> next;
    }
    if (root == nullptr) {
        return root;
    }
    return root -> left ? root -> left : root -> right;
}

Node* connect(Node* root) {
    // base case
    if (root == nullptr or isLeaf(root)) {
        return root;
    }

    queue <Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        Node* nextRightNode = getNextRightNode(curr);
        if (curr -> left) {
            if (curr -> right) {
                curr -> left -> next = curr -> right;
            } else {
                curr -> left -> next = nextRightNode;
            }
            q.push(curr -> left);
        }
        if (curr -> right) {
            curr -> right -> next = nextRightNode;
            q.push(curr -> right);
        }
    }
    return root;
}

int main () {

}