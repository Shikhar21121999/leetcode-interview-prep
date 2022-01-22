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

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252273/C%2B%2B-O(n-log-n)-and-O(n)

/*
Approach is to simply creat BST from preorder
Points to keep in mind
Preorder => Root Left Right
On careful observation roots are created one after the other form the index
Smart recursion has been done for space optimization, that is basically we use p_val
and reference to idx to avoid split array implementation
for first root idx is zero and p_val = INT_MAX
p_val denotes that all the nodes in the child-subtree should he less than
this value (either parnet node value for left or grand parent value for right)
*/

int idx = 0;
TreeNode* bstFromPreorder(vector<int>& preorder, int p_val = INT_MAX) {
    // base case
    if (preorder[idx] > p_val || idx >= preorder.size()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[idx]);
    idx++;

    root -> left = bstFromPreorder(preorder, root -> val);
    root -> right = bstFromPreorder(preorder, p_val);

    return root;

}