#include <bits/stdc++.h>
using namespace std;

/*
Approach is to use Stack
We use stack to keep track of previous adjacent characters
and push and pop new characters with adjacent count accordingly
*/

string removeDuplicates(string s, int k) {
    stack < pair <char, int> > st;

    for (auto ch: s) {
        if (st.empty()) {
            // cout << "stack empty pushing \n";
            st.push({ch, 1});
        } else {
            auto top_pair = st.top();
            // cout << ch << " " << top_pair.first << " " << top_pair.second << endl;
            if (ch == top_pair.first) {
                // pop since we either need to push updated
                // or not push at all
                st.pop();
                // check if including curr character
                // we have total k adjacent
                if (top_pair.second < k-1) {
                    top_pair.second++;
                    st.push(top_pair);
                }
            } else {
                st.push({ch, 1});
            }
        }
    }

    string ans = "";
    while (!st.empty()) {
        auto top_pair = st.top();
        st.pop();
        // cout << top_pair.first << " " << top_pair.second << endl;
        char ch = top_pair.first;
        int cnt = top_pair.second;
        for (int i = 0; i < cnt; i++) {
            ans += ch;
        }
    }
    reverse(ans.begin(), ans.end());
    // cout << ans;
    return ans;
}

/*
Possible optimization is to use a vector as stack,
this leads to following optimizations:
1. we don't need to push and pop again for updating second element
2. We don't need to reverse the answer string, since for creation
of answer we can traverse the array from forward fashion
Another possible optimization is to use
inbuilt function append for building string from character, freq
pairs
*/

string removeDuplicatesOptimized(string s, int k) {
    vector<pair<char, int>> st;
    for (char c : s) {
        if (!st.empty() && st.back().first == c) {
            ++st.back().second;
        } else {
            st.push_back({c, 1});
        }
        if (st.back().second == k) { // If reach enough k duplicate letters -> then remove
            st.pop_back();
        }
    }
    string res;
    for (auto p : st) {
        res.append(p.second, p.first);
    }
    return res;
}

int main () {
    string inp = "pbb";
    int k = 2;
    cout << removeDuplicatesOptimized(inp, k);
}