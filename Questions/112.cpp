#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    TreeNode *left, *right;
    int val;
    TreeNode () {
        this -> left = nullptr;
        this -> right = nullptr;
        this -> val = 0;
    }
};

bool hasPathSum(TreeNode* root, int targetSum) {
    // if root is nullptr targetSum should be 0
    if (root == nullptr) {
        return (targetSum == 0);
    }

    // if a leaf node targetSum should be equal to root -> val
    if (root -> left == nullptr and root -> right == nullptr) {
        return (targetSum == root -> val);
    }

    // recursive cases
    if (root -> left) {
        if (hasPathSum(root -> left, targetSum - root -> val)) {
            return true;
        }
    }
    if (root -> right) {
        if (hasPathSum(root -> right, targetSum - root -> val)) {
            return true;
        }
    }
    return false;
}