#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    vector <int> sp(26, 0);
    if (s.length() != t.length()) {
        return false;
    }
    for (int i = 0; i < s.length(); i++) {
        sp[s[i] - 'a'] += 1;
        sp[t[i] - 'a'] -= 1;
    }
    vector <int> zero(26, 0);
    return (sp == zero);
}

int main () {

}