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

void flatten(TreeNode* root) {
    TreeNode *tail = nullptr, *curr;
    stack <TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        curr = st.top();
        st.pop();
        if (curr -> right != nullptr) {
            st.push(curr -> right);
        }
        if (curr -> left != nullptr) {
            st.push(curr -> left);
        }
        if (tail != nullptr) {
            tail -> right = curr;
            tail -> left = nullptr;
        }
        tail = curr;
    }
}

int main() {
    
}