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

// Trim a binary search tree

TreeNode* trimBST(TreeNode* root, int low, int high) {
    // base case
    if (root == nullptr) return root;

    // recurse for subtrees
    TreeNode *ltree = trimBST(root -> left, low, high);
    TreeNode *rtree = trimBST(root -> right, low, high);

    // if root does not need to be trimmed
    if (root -> val >= low and root -> val <= high) {
        root -> left = ltree;
        root -> right = rtree;
        return root;
    }

    // if root is to be trimmed
    // return the sub-tree which is not null, if both null return null

    return (ltree == nullptr) ? rtree : ltree;
}