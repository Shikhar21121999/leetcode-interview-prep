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
        TreeNode (int data, TreeNode* left, TreeNode *right) {
            this -> val = data;
            this -> left = left;
            this -> right = right;
        }
};

/*
Approach is to perform level order traversal and get nodes at level depth -1
and add nodes accordingly below the nodes at this level
*/

void levelNodes(TreeNode* root, int depth, vector <TreeNode*> &nodes) {
    queue < TreeNode* > q;
    q.push(root);

    int curr_depth = 1;
    while(!q.empty() and curr_depth < depth - 1) {
        int n = q.size();
        for (int i=0; i<n; i++) {
            TreeNode *curr = q.front();
            q.pop();
            if (curr -> left != nullptr) {
                q.push(curr -> left);
            }
            if (curr -> right != nullptr) {
                q.push(curr -> right);
            }
            curr_depth ++;
        }
    }
    // get nodes at depth depth - 1
    while(!q.empty()) {
        nodes.push_back(q.front());
        q.pop();
    }
}

TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    // base case
    if (depth == 1) {
        TreeNode* temp = new TreeNode(val);
        temp -> left = root;
        return temp;
    }

    // get all the nodes at depth depth - 1
    vector <TreeNode*> nodes;
    levelNodes(root, depth, nodes);
    for (auto x: nodes) {
        TreeNode* leftSubtree = new TreeNode(val, x -> left, nullptr);
        TreeNode* rightSubtree = new TreeNode(val, nullptr, x -> right);
        x -> left = leftSubtree;
        x -> right = rightSubtree;
    }
    return root;
}

int main() {
    
}