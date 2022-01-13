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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector < vector <int> > ans;
        queue < TreeNode* > q;
        bool rev = false;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector <int> temp;
            
            for (int i=0; i < n; i++) {
                TreeNode* curr = q.front();
                temp.push_back(curr -> val);
                if (curr -> left != nullptr) {
                    q.push(curr -> left);
                }
                if (curr -> right != nullptr) {
                    q.push(curr -> right);
                }
            }
            if (rev) {
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            rev = !rev;
        }
        return ans;
    }
};