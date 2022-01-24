#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>

bool detectCapitalUse(string word) {
    int cnt = 0;
    for (auto x: word) {
        if(isupper(x)) {
            cnt++;
        }
    }

    return (cnt == word.length() || cnt == 0 || (cnt == 1 && isupper(word[0])));
}

int main () {
    cout << detectCapitalUse("Shikhar");
}