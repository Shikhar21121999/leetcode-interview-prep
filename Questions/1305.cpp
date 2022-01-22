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
Approach is to get inorder traversal of bsts (sorted array),
problem reduces to getting sorted elements in the two sorted array
*/

// function to get inorder traversal iterative
vi inorderIterative (TreeNode *root) {
    stack <TreeNode*> st;
    TreeNode *curr = root;
    vi ans;

    while(curr != nullptr or !st.empty()) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr -> left;
        } else {
            curr = st.top();
            st.pop();
            ans.push_back(curr -> val);
            curr = curr -> right;
        }
    }
    return ans;
}

void printVector (vi &a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vi t1 = inorderIterative(root1);
    vi t2 = inorderIterative(root2);

    vi ans;
    int i = 0;
    int j = 0;

    while(i < t1.size() and j  < t2.size()) {
        if (t1[i] <= t2[j]) {
            ans.push_back(t1[i]);
            i++;
        } else {
            ans.push_back(t2[j]);
            j++;
        }
    }
    
    // collect remaining elements
    while(i < t1.size() or j < t2.size()) {
        if (i < t1.size()) {
            ans.push_back(t1[i]);
            i++;
        }
        if (j < t2.size()) {
            ans.push_back(t2[j]);
            j++;
        }
    }
    printVector(ans);
    return ans;
}

/*
Method 2
O(N) single pass
We traverse the two 
*/

// push left children of the root into the stack
void pushLeft(stack<TreeNode*> &st, TreeNode* root) {
    TreeNode* curr = root;
    while (curr != nullptr){
        st.push(curr);
        curr = curr->left;
    }
}
vector<int> getAllElements1(TreeNode* root1, TreeNode* root2) {
    vector<int> res;
    stack<TreeNode*> s1, s2;

    // pushing left of trees recursively
    pushLeft(s1, root1);
    pushLeft(s2, root2);

    while (!s1.empty() || !s2.empty()) {
        // select the stack which contains smaller element
        stack <TreeNode*> st;

        // base case if one of the stack is empty choose the other one
        if (s1.empty()) {
            st = s2;
        } else if (s2.empty()) {
            st = s1;
        }
        // if both the stack are not empty
        // choose the stack which has smaller element
        else if (s1.top() -> val < s2.top() -> val) {
            st = s1;
        } else {
            st = s2;
        }

        // get the element from the selected stack
        // and push it to the array
        // acessing root
        auto n = st.top(); st.pop();
        res.push_back(n->val);

        // recursing for right
        pushLeft(st, n->right);
    }
    return res;
}