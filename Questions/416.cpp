#include <bits/stdc++.h>
using namespace std;

# define vi vector<int>
# define vvi vector<vi>
# define pii pair<int,int>
# define vpii vector<pii>
# define vvpii vector<vpii>
# define space " "
# define newLine "\n"

// partition equal subset sum

// Given a non-empty array nums containing only positive integers, 
// find if the array can be partitioned into two subsets
// such that the sum of elements in both subsets is equal.

// see if its possible to get a subset such that sum of elements in it is tsum/2
// or another variation can be => se if its possibe to get sum using some or all elements of the array

// recursive solution

// returns if it is possible to get sum, using first n elements of arr
bool recur(vi &arr, int n, int sum) {
    // cout << n << space << sum << newLine;
    // base case
    if (sum == 0) return true;

    if (n < 0) return false;

    // recursive cases

    // there are two possibilities in which we can get sum
    
    // use element at n and see if it is possible to get sum - arr[n] in first n-1 elements
    // don't use nth element and see if it is possible to get sum using first n-1 elements
    return arr[n] <= sum ? recur(arr, n -1, sum - arr[n]) || recur(arr, n-1, sum) : recur(arr, n-1, sum);
}

// dp solution
// we can do it by using a 2-D array where dp[i][j]
// represent if its possible to get sum j using first i elements

// dp[0][any_sum] = false or 0 always
// dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]]

// another 1d array solution
// like we do in knapsack

bool canPartition(vector<int>& nums) {
    int reqdSum = 0;
    for (auto x: nums) {
        reqdSum += x;
    }
    if (reqdSum % 2) {
        return false;
    }
    reqdSum /= 2;
    
    vector <bool> dp(reqdSum+1, false);

    // it is always possible to get 0 by not choosing any
    dp[0] = true;

    for (auto num: nums) {
        for (int i=reqdSum; i>0; i--) {
            if (i >= num) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
    }
    return dp[reqdSum];
}

int main() {
    vi arr{2,3,5,6};
    cout << canPartition(arr);
}