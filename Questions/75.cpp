#include <bits/stdc++.h>
using namespace std;

// brute force
/*
Perform sorting 
TC -> O(NlogN)
SC -< O(0)
*/

// Optimized
/*
Perform count sort 
TC -> O(N) => Double Pass
SC -< O(0)
*/

// Most Optimized
/*
Use Dutch Flag Algo
TC -> O(N) -> single pass
SC -< O(0)
*/

void sortColors(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int hi = nums.size() - 1;

    while(mid <= hi) {
        if (nums[mid] == 0) {
            swap(nums[low++], nums[mid++]);
        } else if (nums[mid == 1]) {
            mid++;
        } else {
            // nums[mid] == 2
            swap(nums[mid], nums[hi--]);
        }
    }
}
int main () {

}