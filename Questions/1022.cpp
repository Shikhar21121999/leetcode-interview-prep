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
Approach is to recursively keeping on adding bit at the end of number
if we reach a null node, number is formed and we add it to the the sum
*/
class Solution {
public:
    void recur(TreeNode* root, int num, int &sum) {
        num = (num << 1) | root -> val;
        if (root -> left == nullptr && root -> right == nullptr) {
            cout << num << endl;
            sum += num;
            return;
        }
        if (root -> left != nullptr) {
            recur(root -> left, num, sum);
        }
        if (root -> right != nullptr) {
            recur(root -> right, num, sum);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        recur(root, 0, sum);
        return sum;
    }
};