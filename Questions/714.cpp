#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector <int> dp(n, 0);
    int minPriceInd = 0;
    for (int i = 1; i < n; i++) {
        // there are three possibilities
        // sell the minPrice Stock till now directly on this day
        if (prices[i] < prices[minPriceInd]) {
            minPriceInd = i;
        }
        int profit1 = prices[i] - prices[minPriceInd] - fee + dp[minPriceInd];
        int profit2 = dp[i-1];
        int profit3 = dp[i-1] + prices[i] - prices[i-1] - fee;
        cout << prices[i] << " " << prices[minPriceInd] << " " << profit1 << " " << profit2 << " " << profit3 << endl; 
        dp[i] = max(max(profit1, max(profit2, profit3)), dp[i]);
    }
    return dp[n-1];
}

int main () {
    vector <int> a = {1,4,6,2,8,3,10,14};
    maxProfit(a, 3);
}