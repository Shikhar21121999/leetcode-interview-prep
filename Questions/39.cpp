#include <bits/stdc++.h>
using namespace std;

#define vi vector <int>
#define vvi vector <vi>

void backtrack(int i, int currSum, vi &currCandidates, vi &candidates, int &target, vvi &res) {
    // base case
    if (currSum == target) {
        res.push_back(currCandidates);
        return;
    }

    // recursive case
    for (int j = i; j < candidates.size(); j++) {
        if (candidates[j]+ currSum <= target) {
            // do
            currCandidates.push_back(candidates[j]);
            // recur
            backtrack(j, currSum + candidates[j], currCandidates, candidates, target, res);
            // undo
            currCandidates.pop_back();
        }
    }
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vvi res;
    vi currCandidates;
    backtrack(0, 0, currCandidates, candidates, target, res);
    return res;
}

void printVector(vi a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;
}

int main () {
    int target = 7;
    vector <int> candidates = {2,3,6,7};
    for (auto x: combinationSum(candidates, target)) {
        printVector(x);
    }
}