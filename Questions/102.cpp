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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            // empty out all the nodes
            // vector <TreeNode*> temp;
            int n = q.size();
            vector <int> ans(n);
            for (int i = 0; i < n ; i++) {
                TreeNode* curr = q.front();
                q.pop();
                ans[i] = (curr -> val);
                if (curr -> left != nullptr) {
                    q.push(curr -> left);
                } if (curr -> right != nullptr) {
                    q.push(curr -> right);
                }
            }
            result.push_back(ans);
        }
        return result;
    }
};