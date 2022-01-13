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
We just have to recurse the tree such that we get nodes in descending order
and maintain sum of nodes greater than itself
*/
class Solution {
public:
    int sumGreater = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if (root -> right != nullptr) {
            bstToGst(root -> right);
        }
        root -> val = root -> val + sumGreater;
        sumGreater = root -> val;
        if (root -> left != nullptr) {
            bstToGst(root -> left);
        }
        return root;
    }
};