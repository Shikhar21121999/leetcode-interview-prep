#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    // choose atleast one
    // if all are negative choose the max ele

    int localMax = 0;
    int gMax = 0;
    int maxEle = INT_MIN;

    for (auto x: nums) {
        localMax += x;
        maxEle = max(maxEle, x);
        if (localMax > gMax) {
            gMax = localMax;
        }
        if (localMax < 0) {
            localMax = 0;
        }
    }
    return (gMax == 0 ? maxEle : gMax);
}

int main() {
    vector <int> a = {-2,-1,-3};
    cout << maxSubArray(a);
}