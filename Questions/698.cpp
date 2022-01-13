#include <bits/stdc++.h>
using namespace std;

# define vi vector<int>
# define vvi vector<vi>
# define pii pair<int,int>
# define vpii vector<pii>
# define vvpii vector<vpii>
# define space " "
# define newLine "\n"

// Given an integer array nums and an integer k, return true if it is possible 
// to divide this array into k non-empty subsets whose sums are all equal.

// Constraints => 

// 1 <= k <= nums.length <= 16
// 1 <= nums[i] <= 104
// The frequency of each element is in the range [1, 4].

// Observations
// Constraints are pretty low

// Solution => all the sets are identical
// Brute force
// see if it is possible to find k sets totalling sum/k provided we are not using elements already used

// see if it is possible to find 1 subset totalling sum/k using given array and mark the ones using as more than sum/k

// dp + bit manipulation
// we use bit manipulation (bitmask) to represent a state
// where some elements of the overall array are selected
// and have been put in several subsets
// dp[i] => represnt sum remaining from target in the last subset filled
// we fill subset one after the other

int dp[(1<<16)+2];
bool canPartition(vector<int>& nums, int k) {
    int n = nums.size(); int reqdSum=0;

    // fill the dp array
    fill(dp, dp+(1<<16)+2, -1);
    dp[0] = 0;

    for (auto num: nums) {
        reqdSum += num;
    }

    if (reqdSum % k) {
        cout << "exitting here" << newLine;
        return false;
    }
    int target = reqdSum / k;

    for (int mask = 0; mask < (1<<n); mask ++) {
        if (dp[mask] == -1) continue; // ignore invalid state
        for (int i = 0; i < n; i++) {
            // check if this number is already included in the mask
            // and inclusion of this number will not make sum greater than target
            if (!(mask&(1<<i)) && dp[mask] + nums[i] <= target) {
                dp[mask|(1<<i)] = (dp[mask] + nums[i]) % target;
            }
        }
    }
    return dp[(1<<n)-1] == 0;
}


int main() {
    vi sampl{4,3,2,3,5,2,1};
    cout << canPartition(sampl, 4);
}