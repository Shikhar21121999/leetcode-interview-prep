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

int pathSum(TreeNode* root, int targetSum) {
    // base case
    if (root == nullptr) {
        return 0;
    }
    
    int possiblePath = 0;
    if (targetSum == root -> val) {
        possiblePath+= 1;
    }

    if (root -> left != nullptr) {
        possiblePath += pathSum(root -> left, targetSum - root -> val);
        possiblePath += pathSum(root -> left, targetSum);
    }
    if (root -> right != nullptr) {
        possiblePath += pathSum(root -> right, targetSum - root -> val);
        possiblePath += pathSum(root -> right, targetSum);
    }
    return possiblePath;
}