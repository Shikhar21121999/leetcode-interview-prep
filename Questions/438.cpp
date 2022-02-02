#include <bits/stdc++.h>
using namespace std;

/*
using hashmap is expensive in this case
since comparing hasmap is expensive,
hence we implement the same using vector <int> for 26 chars
this reduces the compare time to o(26) which in handsight is 0(1)
*/

vector<int> findAnagrams(string s, string p) {
    // base case
    vector <int> ans;
    if (s.length() < p.length()) {
        return ans;
    }

    vector <int> sm(26,0), pm(26,0);

    // fill p map with count of characters in p
    for (auto ch: p) {
        pm[ch - 'a'] += 1;
    }

    // initialize a window of p.length() size for characters in s
    int right = 0;
    while(right < p.length()) {
        sm[s[right++] - 'a'] += 1;
    }

    // check and fill
    if (sm == pm) {
        ans.push_back(0);
    }

    // here right becomes equal to p.length()
    while(right < s.length()) {
        // cout << right << endl;
        // include the right character
        sm[s[right] - 'a']++;
        // exclude the left character
        sm[s[right - p.length()] - 'a']--;

        // check for this new window
        if (sm == pm) {
            ans.push_back(right - p.length() + 1);
        }
        right++;
    }
    return ans;
}


int main () {
    string s = "abab", p = "ab";
    vector <int> ans = findAnagrams(s, p);
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
}