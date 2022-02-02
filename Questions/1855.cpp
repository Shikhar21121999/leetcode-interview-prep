#include <bits/stdc++.h>
using namespace std;

void printVector (vector <int> &a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;
}

int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    vector <int> dp(n1);

    int j = 0;
    for (int i = 0; i < n1; i++) {
        j = i < n2 ? max(j, i) : i;
        if (j >= n2 or nums2[j] < nums1[i]) {
            dp[i] = i;
        } else {
            dp[i] = j;
        }
        while(j+1 < n2 and nums2[j + 1] >= nums1[i]) {
            j++;
            dp[i] = j;
        }
        cout << j << endl;
    }
    // printVector(nums1);
    // printVector(nums2);
    // printVector(dp);

    int ans = 0;
    for (int i = 0; i < n1; i++) {
        ans = max(ans, (dp[i] - i));
    }

    return ans;
}

// optimized without extra space
int maxDistance1(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    vector <int> dp(n1);

    int j = 0;
    int ans = 0;
    for (int i = 0; i < n1; i++) {
        j = i < n2 ? max(j, i) : i;
        int temp;
        if (j >= n2 or nums2[j] < nums1[i]) {
            temp = i;
        } else {
            temp = j;
        }
        while(j+1 < n2 and nums2[j + 1] >= nums1[i]) {
            j++;
            temp = j;
        }
        ans = max(ans, temp - i);
    }

    return ans;
}

int main () {
    vector <int> nums1 = {9370,8977,8227,7831,7761,7716,7426,7309,6925,6515,6112,5170,4720,3629,2624,2583,1731,418};
    vector <int> nums2 = {9633,9529,9459,9282,9256,9175,9169,8975,8880,8837,8805,8747,8625,8405};
    maxDistance(nums1, nums2);
}