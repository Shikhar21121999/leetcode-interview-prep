#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    TreeNode *left, *right;
    int val;
    TreeNode () {
        this -> left = nullptr;
        this -> right = nullptr;
        this -> val = 0;
    }
};

string hashPath(vector <int> &path) {
    string ans = "";
    int n = path.size();
    for (int i = 0; i < n; i++) {
        ans += to_string(path[i]);
        if (i < n-1) {
            ans += "->";
        }
    }
    return ans;
}

void backTrack (TreeNode *root, vector <string> &ans, vector <int> &currPath) {
    // path ends at leaf node
    if (root -> left == nullptr and root -> right == nullptr) {
        currPath.push_back(root -> val);
        ans.push_back(hashPath(currPath));
        currPath.pop_back();
        return;
    }

    // recur for both path
    if (root -> left != nullptr) {
        currPath.push_back(root -> val);
        backTrack(root -> left, ans, currPath);
        currPath.pop_back();
    }
    if (root -> right != nullptr) {
        currPath.push_back(root -> val);
        backTrack(root -> right, ans, currPath);
        currPath.pop_back();
    }
    return;
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector < string > ans;
    if (root == nullptr) {
        return ans;
    }
    vector <int> currPath;
    currPath.push_back(root -> val);
    backTrack(root, ans, currPath);
    return ans;
}