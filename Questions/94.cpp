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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // base case
        if (root == nullptr) return vi {};
        vi result;
        stack < TreeNode* > st;
        TreeNode* curr = root;
        st.push(curr);
        while (!st.empty() or curr != nullptr) {
            if (curr != nullptr) {
                st.push(curr -> left);
                curr = curr -> left;
            } else {
                curr = st.top();
                st.pop();
                result.push_back(curr -> val);
                st.push(curr -> right);
                curr = curr -> right;
            }
        }
        return result;
    }
};