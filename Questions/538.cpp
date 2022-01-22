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

TreeNode* recur(TreeNode* root, int &sum) {
    // call for right subtree
    if (root -> right != nullptr) {
        recur(root -> right, sum);
    }
    root -> val += sum;
    sum = root -> val;

    if (root -> left != nullptr) {
        recur(root -> left, sum);
    }
    return root;

}

TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    return recur(root, sum);
}