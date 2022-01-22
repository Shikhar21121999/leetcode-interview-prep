#include <bits/stdc++.h>
using namespace  std;
#define vi vector <int>

/*
dp[i] denotes wether a player wins if he starts at i
player wins if starts at i if the next player can be made to loose
therefore we see if dp[i-k] == false where k is a perfect square
dp[i] is true
*/

vi perfect_sqare_coll;
vi dp;

bool recur(int n) {
    cout << n << "\n";
    // base case
    if (dp[n] != -1) {
        return bool(dp[n]);
    }

    // recursive case
    for (auto x: perfect_sqare_coll) {
        if (n-x >= 1 and !recur(n-x)) {
            dp[n] = 1;
            return bool(dp[n]);
        }
    }
    dp[n] = 0;
    return bool(dp[n]);
}

bool winnerSquareGame(int n) {
    perfect_sqare_coll.reserve(n);
    dp.resize(n+1, -1);

    // find perfect squares less than n
    // at perfect square player wins
    for (int i = 1; i*i <=n; i++) {
        perfect_sqare_coll.push_back(i*i);
        dp[i*i] = 1;
    }
    if (dp[n] == 1) return true;

    return recur(n);
}

int main() {
    vi cases = {17};
    for (auto x: cases) {
        cout << winnerSquareGame(x) << "\n";
    }
}