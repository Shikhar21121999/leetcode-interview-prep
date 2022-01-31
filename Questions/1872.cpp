#include <bits/stdc++.h>
using namespace std;

/*
Approach is to use simple implementation
traverse each row and keep adding previous element to next
at end of this each row's last element is the total sum
find max by comparing last element of each row (account)
*/
int maximumWealth(vector<vector<int>>& accounts) {
    int ans = 0;
    int n = accounts[0].size();
    for (auto account : accounts) {
        for (int i = 1; i < n; i++) {
            account[i] += account[i-1];
            if (i == n-1) {
                ans = max(ans, account[i]);
            }
        }
    }
    return ans;
}

int main () {

}