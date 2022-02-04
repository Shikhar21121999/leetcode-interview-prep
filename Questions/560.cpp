#include <bits/stdc++.h>
using namespace std;

/*
Brute force approach
For each subarray find the sum
and see if it equals k
O(N^3)
*/


/*
Optimized brute force
preCalculate sum between indexes prefixSum
TC => O(N^2)
SC => O(N)
*/

/*
Optimal Solution
preSum + hashMap
Observation => if we are keeping track of preSum, we can observe
if we would have gotten a previous sum of currSum - k,
implies that we have found subArray with sum equal to K
Here we also need to mention we need to keep a count of prevSum
encountered since we have negative values here
*/

int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    map <int, int> recd;
    int cnt = 0;
    recd[0]++;

    for (auto x: nums) {
        sum += x;
        cnt += recd[sum - k];
        recd[sum]++;
    }
    return cnt;
}

int main () {

}