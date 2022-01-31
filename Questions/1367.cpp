#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode () {
            this -> val = 0;
            this -> left = nullptr;
            this -> right = nullptr;
        }
        TreeNode (int data) {
            this -> val = data;
            this -> left = nullptr;
            this -> right = nullptr;
        } 
};

class ListNode {
    public:
    int val;
    ListNode *next;

    ListNode () {
        this -> val = 0;
        this -> next = nullptr;
    }
};


/*
Approach is to find node whose value equals root
and then check if a path can be found such that it matches
the list
*/

bool isConnectedPath (ListNode* head, TreeNode *root) {
    if (head == nullptr) return true;
    if (root == nullptr and head != nullptr) return false;

    if (head -> val == root -> val) {
        return (isConnectedPath(head -> next, root -> left) or isConnectedPath(head -> next, root -> right));
    }
    return false;
}

bool isSubPath(ListNode* head, TreeNode* root) {
    // base case
    if (head == nullptr) return true;

    if (root == nullptr and head != nullptr) return false;

    queue <TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr -> val == head -> val and isConnectedPath(head, curr)) {
            return true;
        } else {
            if (curr -> left != nullptr) {
                q.push(curr -> left);
            }
            if (curr -> right != nullptr) {
                q.push(curr -> right);
            }
        }
    }
    return false;
}