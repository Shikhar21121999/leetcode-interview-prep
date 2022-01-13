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
    int maxDepth(TreeNode* root) {
        // base case
        if (root == nullptr) {
            return 0;
        }
        // recursive case
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};