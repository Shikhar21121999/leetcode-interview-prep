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

/*
We perform a simple level order traversal
get the sum of nodes in the last row
*/

int deepestLeavesSum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else if (root -> left == nullptr and root -> right == nullptr) {
        return root -> val;
    }
    queue <TreeNode*> q;
    q.push(root);
    int sum = 0;
    while (!q.empty()) {
        int n = q.size();
        sum = 0;
        for (int i = 0; i < n; i++) {
            TreeNode *curr = q.front();
            q.pop();
            sum += curr -> val;
            if (curr -> left != nullptr) {
                q.push(curr -> left);
            }
            if (curr -> right != nullptr) {
                q.push(curr -> right);
            }
        }
    }
    return sum;
}

// there can be a recursive solution
// for that we traverse the tree twice
// 1 for getting the greatest height
// 2 for getting sum of nodes at the greatest level calculated
// in 1 traversal

int main () {

}