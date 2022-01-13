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

// left is inclusive right is exclusive
TreeNode* recur(vi &nums, int left, int right) {

    // base cases
    if (left == right) {
        return nullptr;
    }
    if (right - left == 1) {
        return new TreeNode(nums[left]);
    }

    // recursive case
    int mid = left + (right - left) / 2;

    TreeNode* root = new TreeNode(nums[mid]);
    TreeNode* lTree = recur(nums, left, mid);
    TreeNode* rTree = recur(nums, mid+1, right);
    root -> left = lTree;
    root -> right = rTree;
    return root;
}

class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return recur(nums, 0, nums.size());
        }
};