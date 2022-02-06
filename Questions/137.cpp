#include <bits/stdc++.h>
using namespace std;

// going by the examples in 
// https://leetcode.com/problems/single-number-iii/discuss/68900/Accepted-C%2B%2BJava-O(n)-time-O(1)-space-Easy-Solution-with-Detail-Explanations

/*
we have k = 3, p = 1, m = 2;
therefore we need two 32 bit integers x1 and x2
k in its binary form is 1 1
therfore mask = ~(x1 & x2)
since p = 1 that is 0 1 (binary)
return x1
if p would have been 2 that is 1 0
we would have returned x2
*/

int singleNumber(vector <int> &nums) {
    int x1 = 0;
    int x2 = 0;
    int mask = 0;
    
    for (auto num: nums) {
        x2 ^= x1 & num;
        x1 ^= num;
        mask = ~(x1 & x2);
        x2 &= mask;
        x1 &= mask;
    }
    return x1;
}

int main () {

}