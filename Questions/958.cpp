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
In a complete binary tree, there should never be a row such that
a node is missing and after that a node is present
that is in a level all the nodes should be present one after the other
*/
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr or (root -> left == nullptr and root ->left == nullptr)) return true;
        queue <TreeNode*> q;
        q.push(root);

        bool preNull = false;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == nullptr) {
                preNull = true;
            } else {
                if (preNull) {
                    return false;
                } else {
                    q.push(curr -> left);
                    q.push(curr -> right);
                }
            }
        }
        return true;
    }
};