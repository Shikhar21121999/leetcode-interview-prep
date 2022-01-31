#include <bits/stdc++.h>
using namespace std;

// smart brute force
// using extra space
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (k > n) {
        k = k % n;
    }
    queue <int> q;
    // push last k elements into the queue
    cout << n - k << endl;
    for (int i = n - k; i < n; i++) {
        q.push(nums[i]);
    }
    cout << endl;

    // push elements k forward
    // fill from last
    for (int i = n - 1; i - k >= 0; i--) {
        cout << i << endl;
        nums[i] = nums[i - k];
    }

    cout << endl;
    for (int i = 0; i < k; i++) {
        cout << i << endl;
        nums[i] = q.front();
        q.pop();
    }
}

int main () {
    vector <int> a = {1, 2, 3, 4, 5, 6, 7};
    rotate(a, 3);
    for (auto x: a) {
        cout << x << " ";
    }
}