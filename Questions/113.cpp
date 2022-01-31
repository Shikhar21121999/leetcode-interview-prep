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

void backTrack (TreeNode *root, vector <vector <int> > &ans, vector <int> &curr_path, int &currSum, int &targetSum) {
    // base case
    if (root -> left == nullptr and root -> right == nullptr) {
        if (currSum == targetSum) {
            ans.push_back(curr_path);
        }
        return;
    }

    // recursive step
    if (root -> left != nullptr) {
        // do
        curr_path.push_back(root -> left -> val);
        currSum += root -> left -> val;
        // recur
        backTrack(root -> left, ans, curr_path, currSum, targetSum);
        // undo
        curr_path.pop_back();
        currSum -= root -> left -> val;
    }
    if (root -> right != nullptr) {
        curr_path.push_back(root -> right -> val);
        currSum += root -> right -> val;
        // recur
        backTrack(root -> right, ans, curr_path, currSum, targetSum);
        // undo
        curr_path.pop_back();
        currSum -= root -> right -> val;
    }
    return;
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector <vector <int> > ans;
    if (root == nullptr) {
        return ans;
    }
    int currSum = root -> val;
    vector <int> currPath;
    currPath.push_back(root -> val);
    backTrack(root, ans, currPath, currSum, targetSum);

    return ans;
}