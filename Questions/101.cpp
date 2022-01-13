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
    bool isSymmetric(TreeNode* root) {
        // base case
        if (root == nullptr) {
            return true;
        }

        // we perform level order traversal for left and right subtree (reverse)
        // to check if tree is symmetric

        queue < TreeNode* > q;

        while(!q.empty()) {
            TreeNode* node1 = q.front();
            q.pop();
            TreeNode* node2 = q.front();
            q.pop();

            if (!node1 && node2) return false;
            if (node1 && !node2) return false;
            if (node1 && node2) {
                if (node1 -> val != node2 -> val) return false;
                q.push(node1 -> left);
                q.push(node2 -> right);
                q.push(node1 -> right);
                q.push(node2 -> left);
            }

        }
        return true;
    }
};