#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int ans = 0;
    int last_stock_ind = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < prices[last_stock_ind]) {
            last_stock_ind = i;
        } else if (prices[i] > prices[last_stock_ind]) {
            ans += prices[i] - prices[last_stock_ind];
            last_stock_ind = i;
        }
    }
    return ans;
}


int main () {

}