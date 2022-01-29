#include <bits/stdc++.h>
using namespace std;

/*
Approach is to use dp
here we construct a bottom up dp
and we fill the numbers in dp array from back
*/

void printVector (vector <int> a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << "\n";
}

vector <int> getRow(int rowIndex) {
    vector <int> dp(rowIndex + 1);

    for (int curr_row = 0; curr_row <= rowIndex; curr_row++) {
        for (int j = curr_row; j >= 1; j--) {
            dp[j] = dp[j-1] + dp[j];
        }
        dp[0] = 1;
    }
    return dp;
}

int main () {
    vector <int> a = getRow(1);
    printVector(a);
}