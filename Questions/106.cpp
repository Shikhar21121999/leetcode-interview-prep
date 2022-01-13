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

unordered_map < int, int > mp;
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart = 0, int inEnd = -1, int postStart = 0, int postEnd = -1) {
    if (inEnd == -1 && postEnd == -1) {
        inEnd = inorder.size() -1;
        postEnd = postorder.size() -1;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
    }

    // base conditions
    if (inStart > inEnd || inStart >= inorder.size() || postStart > postEnd || postStart >= postorder.size()) return nullptr;

    // root is the last node in the postOrder traversal
    TreeNode *root = new TreeNode(postorder[postEnd]);

    int index = mp[root -> val];

    int leftNodes = index - inStart;

    root -> left = buildTree(inorder, postorder, inStart, index -1, postStart, postStart + leftNodes - 1);
    root -> right = buildTree(inorder, postorder, index + 1, inEnd, postStart + leftNodes, postStart - 1);
    return root;
}

int main() {
    
}