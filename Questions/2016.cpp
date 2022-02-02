#include <bits/stdc++.h>
using namespace std;

int maximumDifference(vector<int>& nums) {
    int n = nums.size();
    int minPrice = nums[0];
    int ans = 0;
    bool ansExists = false;
    for (int i = 1; i < n; i++) {
        minPrice = min(minPrice, nums[i]);
        if (nums[i] > minPrice) {
            ansExists = true;
            ans = max(ans, nums[i] - minPrice);
        }
    }
    return (ansExists ? ans : -1);
}

int main () {

}