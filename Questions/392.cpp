#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0;
    int j = 0;

    while(i < s.length() and j < t.length()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return (i == s.length());
}

int main () {

}