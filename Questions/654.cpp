#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* construct (vector <int> &nums, int start, int end) {
    // base case
    if (start >= end) {
        return NULL;
    }

    // find the index of maximum element in curr allowed array
    int i = start;
    int maxInd = i;
    while (i++ < end) {
        if (nums[i] > nums[maxInd]) {
            maxInd = i;
        }
    }

    struct TreeNode* root = new TreeNode(nums[maxInd]);
    root -> left = construct(nums, start, maxInd - 1);
    root -> right = construct(nums, maxInd + 1, end);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    TreeNode *root = construct(nums, 0, nums.size() - 1);
    return root;
}

int main () {

}