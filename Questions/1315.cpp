#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode () {
        this -> left = nullptr;
        this -> right = nullptr;
        this -> val = 0;
    }
};

void recur (TreeNode *root, TreeNode *parent, TreeNode *gp, int &sum) {
    if (gp != nullptr and gp -> val % 2 == 0) {
        sum += gp -> val;
    }
    if (root -> left) {
        recur(root -> left, root, parent, sum);
    }
    if (root -> left) {
        recur(root -> left, root, parent, sum);
    }
}

int sumEvenGrandparent(TreeNode* root) {
    int ans = 0;
    recur(root, nullptr, nullptr, ans);
    return ans;
}

int main () {

}