#include <bits/stdc++.h>
using namespace std;

// optimized approach
/*
preSum + hashmap
Here we take advantage of the fact that
array is binary,so instead of counting number of 0's and 1s
seprately and then comparing, we count relative 0's and 1's
by keep a variable sum and incrementing or decrementing it
on the basis of value at nums[i]
we memoize values of sum and see if they had already been found
before
*/
int findMaxLength(vector<int>& nums) {
    int sum=0, maxLen=0;
    map<int, int> seen{{0, -1}};
    
    for(int i=0; i<nums.size(); i++){
        sum += nums[i]==1 ? 1 : -1;
        if(seen.count(sum)) maxLen = max(maxLen, i-seen[sum]);
        else seen[sum] = i;
    }
    return maxLen;
}

int main () {
    vector <int> a = {0,1,1,0,1,1,1,0};
    cout << findMaxLength(a);
}