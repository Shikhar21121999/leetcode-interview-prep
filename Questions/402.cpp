#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    if (num.length() == k) {
        return "0";
    }

    for (int i = 0; i < num.length() - 1; i++) {
        if (num[i] >= num[i+1] and k > 0) {
            k--;
            num[i] = 'x';
        }
    }

    // construct the ans string
    string ans = "";
    bool trailing = true;
    for (auto ch: num) {
        auto chr = ch - '0';
        if (chr >= 0 and chr <= 9) {
            if (chr != 0) {
                trailing = false;
                ans += ch;
            }
            if (chr == 0 and !trailing) {
                ans += ch;
            }
        }
    }
    return ans;
}

int main () {
    // cout << '9' - '9' << endl;
    cout << removeKdigits("1432219", 3);
}