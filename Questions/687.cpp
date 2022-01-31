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

// Note => for path questions it is always better to note the path
// instead of noting number of nodes


int recur(TreeNode* root, int &ans) {
    if (root -> left == nullptr and root -> right == nullptr) {
        return 0;
    }

    // find greatest unique path in left and right subtree
    int greatLpath = root -> left ? recur(root -> left, ans) : 0;
    int greatRpath = root -> right ? recur(root -> right, ans) : 0;

    // if left and or right nodes match root corresponding path will be
    int lPathinclRoot = (root -> left and root -> left -> val == root -> val) ? greatLpath + 1 : 0;
    int rPathinclRoot = (root -> right and root -> right -> val == root -> val) ? greatRpath + 1 : 0;

    ans = max(ans, lPathinclRoot + rPathinclRoot);
    return max(lPathinclRoot, rPathinclRoot);
} 

int longestUnivaluePath(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int ans = 0;
    recur(root, ans);
    return ans;
}