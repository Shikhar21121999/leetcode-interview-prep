#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s2.length() < s1.length()) {
        return false;
    }
    vector <int> dp(s1.length(), 0);
    for (auto ch: s1) {
        dp[ch-'a']--;
    }
    vector <int> zero(26, 0);

    // create a window

    int right = 0;
    while (right < s1.length()) {
        dp[s2[right++] - 'a']++;
    }
    // check
    if (dp == zero) {
        return true;
    }

    while(right < s2.length()) {
        dp[s2[right] - 'a']++;
        dp[s2[right - s1.length()] - 'a']--;
        if (dp == zero) {
            return true;
        }
        right++;
    }
    return false;

}

int main () {

}