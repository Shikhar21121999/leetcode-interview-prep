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
Approach is to recursively compare the two trees
two trees are same if root node is same (data equal)
and left subtrees are equal
and right subtrees are equal
*/
bool isSameTree(TreeNode* p, TreeNode* q) {
    // base case
    if (p == nullptr and q == nullptr) return true;
    // recursive true condition
    if (p -> val == q -> val and isSameTree(p -> left, q -> left) and isSameTree(p -> right, q -> right)) {
        return true;
    }
    return false;
}