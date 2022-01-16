#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>
#define vvi vector <vi>

/*
Bottom up approach filling from the end
*/

void printRecd(unordered_map <int, vi> recd) {
    for (auto x: recd) {
        cout << x.first << "\t";
        for (auto y: x.second) {
            cout << y << " ";
        }
        cout << "\n";
    }
}

void minSelf (int &a, int b) {
    a = min(a, b);
}

void printVector(vi &a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << "\n";
}

int minJumps(vector<int>& arr) {
    int n = arr.size();
    // here dp denotes minimum number of steps required
    // to reach the last index of the array
    vector <int> dp(n, INT_MAX);
    unordered_map <int, vector <int>> recd;
    
    for (int i = 0; i < n; i++) {
        recd[arr[i]].push_back(i);
    }

    // basic states
    dp[n-1] = 0;
    for (auto x: recd[arr[n-1]]) {
        if (x != n - 1) {
            dp[x] = dp[n-1] + 1;
        }
    }

    for (int i = n-2; i >= 0; i--) {
        
        if (i > 0 && (dp[i+1] < dp[i] or dp[i-1] < dp[i])) {
            minSelf(dp[i], dp[i+1]);
            minSelf(dp[i], dp[i-1]);
            dp[i]++;
        }
        if (i == 0 and dp[i+1] < dp[i]) {
            minSelf(dp[i], dp[i+1]);
            dp[i]++;
        }
        for (auto x: recd[arr[i]]) {
            if (x != i) {
                minSelf(dp[x], dp[i]+1);
            }
        }
    }

    return dp[0];
}

int main() {
    vi inp = {100,-23,-23,404,100,23,23,23,3,404};

    cout << minJumps(inp) << "\n";
}