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
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preStart = 0, int inStart = 0, int inEnd = -4) {
    // initialize inEnd initially
    if (inEnd == -4) {
        inEnd = inorder.size() -1 ;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
    }
    if (preStart >= preorder.size()) return NULL;
    if (inStart >= inorder.size() || inEnd < inStart) return NULL;

    // node at preStart is the current Root
    TreeNode* root = new TreeNode(preorder[preStart]);

    // find this node in the inorder
    int index = mp[root -> val];

    int leftNodes = index - inStart;

    // recursively create left subtree
    root -> left = buildTree(preorder, inorder, preStart+1, inStart, index - 1);

    // recursively create right subtree
    root -> right = buildTree(preorder, inorder, preStart + leftNodes + 1, index + 1, inEnd);
    return root;
}

int main() {
    
}