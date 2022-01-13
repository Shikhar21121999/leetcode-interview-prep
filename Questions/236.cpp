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

bool findPath(TreeNode* parent, TreeNode* &child, vector<TreeNode*> &path) {
    // base case
    if (parent == nullptr) return false;
    // base case
    if (parent == child) {
        path.push_back(parent);
        return true;
    }
    bool ans = false;
    // recursive case
    if (findPath(parent -> left, child, path)) {
        ans = true;
        path.push_back(parent);
    } else if (findPath(parent -> right, child, path)) {
        ans = true;
        path.push_back(parent);
    }
    return ans;
}

/*
Here we find lca by first finding the path of p and q from root
find the last node which is common in the path
this last node is the lca
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector <TreeNode*> toP, toQ;
    // findPath from root to p
    findPath(root, p, toP);
    findPath(root, q, toQ);

    // reverse to get the paths from root to nodes
    reverse(toP.begin(), toP.end());
    reverse(toQ.begin(), toQ.end());

    // find the last commont point between the two paths
    int i=0, j=0;
    TreeNode* ans = root;
    for (; i < toP.size() && j < toQ.size(); i++, j++) {
        if (toP[i] == toQ[i]) {
            ans = toP[i];
        } else {
            break;
        }
    }
    return ans;
}

/*
Approach is to recursively find the lca for the node p and q
in the binary tree rooted at root
*/

TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr or root == p or root == q) return root;
    TreeNode* left = lowestCommonAncestor1(root -> left, p, q);
    TreeNode* right = lowestCommonAncestor1(root -> right, p, q);

    if (left != nullptr) return right;
    if (right != nullptr) return left;
    return root;

}

