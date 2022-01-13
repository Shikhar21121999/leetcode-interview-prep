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
Insert into a binary search tree
*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if at leaf node insert
        if (root -> left == nullptr && root -> right == nullptr) {
            if (val < root -> val) {
                root -> left = new TreeNode(val);
            } else {
                root -> right = new TreeNode(val);
            }
            return root;
        }

        // else traverse to the next node
        if (val < root -> val) {
            if ( root -> left != nullptr) {
                insertIntoBST(root -> left, val);
            } else {
                root -> left = new TreeNode(val);
                return root;
            }
        }
        if (val > root -> val ) {
            if (root -> right != nullptr) {
                insertIntoBST(root -> right, val);
            } else {
                root -> right = new TreeNode(val);
                return root;
            }
        }
        return root;
    }
};