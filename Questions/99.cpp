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

// brute force approach
// convert the bst to vector
// then perform swapping

void recoverTree(TreeNode* root) {
    // perform inorder traversal

    stack <TreeNode *> st;
    TreeNode *curr = root;
    TreeNode *prev = nullptr;

    while (!st.empty() or curr != nullptr)
    {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr -> left;
        } else {
            curr = st.top();
            st.pop();
            cout << curr -> val << " " << prev -> val << "\n";
            if (prev != nullptr and curr -> val <= prev -> val) {
                // fix
                swap(prev -> val, curr -> val);
                return;
            }
            prev = curr;
            curr = curr -> right;
        }
    }
    return;
}