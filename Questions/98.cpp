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

/*
Approach is to do inorder traversal and see if we get ascending order
*/

bool isValidBST(TreeNode* root) {
    // perform inorder traversal

    stack <TreeNode *> st;
    TreeNode *curr = root;
    int prev;
    bool first = true;

    while (!st.empty() or curr != nullptr)
    {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr -> left;
        } else {
            curr = st.top();
            st.pop();
            cout << curr -> val << " " << prev << "\n";
            if (!first and curr -> val <= prev) {
                return false;
            } else {
                if (first) {
                    first = false;
                }
                prev = curr -> val;
            }
            curr = curr -> right;
        }
    }
    return true;
}