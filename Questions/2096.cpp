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

bool findPath(TreeNode* parent, int child, vector<TreeNode*> &path) {
    // base case
    if (parent == nullptr) return false;
    // base case
    if (parent -> val == child) {
        path.push_back(parent);
        return true;
    }
    bool ans = false;
    // recursive case
    if (findPath(parent -> left, child, path)) {
        ans = true;
        path.push_back(parent);
    } else if (findPath(parent -> right, child, path)) {
        ans = true;
        path.push_back(parent);
    }
    return ans;
}

/*
Approach is to first find the path from root to startValue
and from root to destValue
Find the lowest common ancestor
start of the string will compose of 'U' x times
where x is the number of nodes after lca in the path of startValue
now move from lca to destValue checking if the next value is at left or right
of the current node
*/

string getDirections(TreeNode* root, int startValue, int destValue) {
    
    vector < TreeNode* > startPath, destPath;

    findPath(root, startValue, startPath);
    findPath(root, destValue, destPath);

    // reverse the paths
    reverse(startPath.begin(), startPath.end());
    reverse(destPath.begin(), destPath.end());

    int i = 0;

    for(; i < startPath.size(); i++) {
        if (startPath[i] != destPath[i]) {
            break;
        }
    }

    string Ans = string(startPath.size() - i, 'U');
    for(int j = i-1; j < destPath.size() - 1; j++) {
        if (destPath[j] -> left == destPath[j+1]) {
            Ans += 'L';
        } else if (destPath[j] -> right == destPath[j+1]){
            Ans += 'R';
        } else {
            cout << "Unexpected result";
        }
    }
    
    return Ans;
}