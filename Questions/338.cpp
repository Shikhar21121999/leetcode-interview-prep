#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector <int> dp(n+1, 0);
    int offset = 1;
    for (int i = 1; i <= n; i++) {
        if (i == 2 * offset) {
            offset = 2 * offset;
        }
        dp[i] = dp[i - offset] + 1;
    }
    return dp;
}

int main () {

}