#include <bits/stdc++.h>
using namespace std;

// brute force optimized
// here we split the array into 4 smaller arrays
// we hash one of the array and then find the solution in 0(N^3)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector < vector <int> > res;
    int n = nums.size();
    int firstEnd = n/4;
    int secondEnd = (2*n)/4;
    int thirdEnd = n;

    unordered_map <int, int> recd;
    // hash the last array
    for (int i = secondEnd; i < n; i++) {
        recd[nums[i]]++;
    }

    for (int i = 0; i < firstEnd; i++) {
        for (int j = firstEnd; j < secondEnd; j++) {
            for (int k = secondEnd; k < thirdEnd; k++) {
                int checkSum = target - (nums[i] + nums[j] + nums[k]);
                if (recd[checkSum]) {
                    for (int l = 0; l < recd[checkSum]; l++) {
                        res.push_back({nums[i], nums[j], nums[k], checkSum});
                    }
                }
            }
        }
    }
    return res;
}

int main () {

}