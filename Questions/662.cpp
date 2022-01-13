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

int widthOfBinaryTree(TreeNode* root) {
    int ans = 0;
    queue < pair < TreeNode*, int> > q;

    q.push({root, 0});
    // width of level is defined as the distance between two non null nodes
    // in between nulls are allowed

    while(!q.empty()) {
        
        int n = q.size();
        int first, last;
        for (int i = 0; i < n; i++) {
            auto curr = q.front();
            if (i == 0) {
                first = curr.second;
            } else if ( i == n - 1) {
                first = curr.second;
            }
            q.pop();
            if (curr.first -> left != nullptr) {
                q.push({curr.first -> left, curr.second*2});
            }
            if (curr.first -> right != nullptr) {
                q.push({curr.first -> right, curr.second*2 + 1});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return  ans;
}

int main() {
    
}