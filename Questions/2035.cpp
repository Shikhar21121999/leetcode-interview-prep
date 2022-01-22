#include <bits/stdc++.h>
using namespace  std;
#define vi vector <int>

/*
Approach is to use bit-mask
*/

int minimumDifference(vector<int>& nums) {
    int n = nums.size();

    // bit mask of n bits
    int mask_max = pow(2,n) - 1;
    int ans = INT_MAX;
    cout << mask_max << "\n";

    // for (int num = 1; num <= mask_max; num++) {
    //     // number check active bits and split them
    //     int cnt_1 = 0;
    //     int set1_sum = 0; // sum of elements in set1
    //     int set2_sum = 0; // sum of elements not in set1

    //     for (int j = 0; j < n; j++) {
    //         if (num & (1 << j)) {
    //             set1_sum += nums[j];
    //             cnt_1++;
    //         } else {
    //             set2_sum += nums[j];
    //         }
    //     }
    //     // cout << num << " " << cnt_1 << "\n";
    //     // cout << set1_sum << " " << set2_sum << "\n";
    //     // check if numbers are divided evenly
    //     if (cnt_1 == n/2) {
    //         ans = min(ans, abs(set1_sum-set2_sum));
    //     }
    // }
    return ans;
}

int main() {
    vi t_c = {7772197,4460211,-7641449,-8856364,546755,-3673029,527497,-9392076,3130315,-5309187,-4781283,5919119,3093450,1132720,6380128,-3954678,-1651499,-7944388,-3056827,1610628,7711173,6595873,302974,7656726,-2572679,0,2121026,-5743797,-8897395,-9699694};
    // cout << minimumDifference(t_c);
    cout << t_c.size() << "\n";
    cout << pow(2, 15) << "\n";
}