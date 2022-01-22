#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

int divideroundUp(int a, int b) {
    int ans = a / b;
    if (a % b) {
        return ++ans;
    }
    return ans;
}

// function to check if this speed allows us to complete
// the array within hours
bool isSpeedAllowed(vi &nums, int k, int hours) {
    for (auto x: nums) {
        hours -= divideroundUp(x, k);
    }
    return hours >= 0;
}

int maxInArr(vi &a) {
    int ans = 0;
    for (auto x: a) {
        ans = max(ans, x);
    }
    return ans;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int maxEle = maxInArr(piles);

    // base case
    if (h == piles.size()) {
        return maxEle;
    }

    // use binary search to find the min possible speed
    int lo = 1;
    int hi = maxEle;
    int ans;
    cout << maxEle << endl;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        cout << mid << " ";
        if (isSpeedAllowed(piles, mid, h)) {
            ans = mid;
            // if this speed is allowed check for smaller speed
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
    return ans;
}

int main() {
    int h = 8;
    vi piles = {3,6,7,11};
}