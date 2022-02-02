#include <bits/stdc++.h>
using namespace std;

// optimized brute force
int maxDistance(vector<int>& colors) {
    int n = colors.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; (j - i) > ans; j--) {
            cout << i << " " << j << endl;
            if (colors[j] != colors[i]) {
                ans = max(ans, abs(j-i));
            }
        }
    }
    return ans;
}

// Smart solution O(n)
/*
We can conclude that there are only two possible answers
which give max difference
first element with some element from end
last element with some element from beginning
we can do two traversals and find the max of both
*/
int maxDistance(vector<int>& colors) {
    int n = colors.size();
    // first element with some element from end
    for (int r = n -1; r > 0; r--) {

    }
    int ans = 0;
    int r = n-1;
    while (r > 0) {
        if (colors[0] != colors[r--]) {
            ans = r + 1;
            break;
        }
    } 
    // check for last element with element in beginning
    int l = 0;
    while (l < n) {
        if (colors[l++] != colors[n-1]) {
            ans = max(ans, (n - l));
            break;
        }
    }
    return ans;
}