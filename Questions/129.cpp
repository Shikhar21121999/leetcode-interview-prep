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

void recur (TreeNode *root, int prevSum, int &tSum) {
    if (root == nullptr) {
        tSum += prevSum;
    }
    prevSum = prevSum * 10 + root -> val;
    recur(root -> left, prevSum, tSum);
    recur(root -> right, prevSum, tSum);
}

int sumNumbers(TreeNode* root, int prevSum = 0) {
    int tSum = 0;
    recur(root, 0, tSum);
    return tSum;
}

int main () {

}