#include <bits/stdc++.h>
using namespace std;

# define vi vector<int>
# define vvi vector<vi>
# define pii pair<int,int>
# define vpii vector<pii>
# define vvpii vector<vpii>
# define space " "
# define newLine "\n"

// initial position is start of the array given
// if at index i can reach i + arr[i] and i - arr[i]
// see if can reach a index with value 0

// observations or base cases =>
// no if no element with value 0
// otherwise recurse for both

// constraints
// 1 <= arr.length <= 5 * 104
// 0 <= arr[i] < arr.length
// 0 <= start < arr.length

int recur(vector<int>& arr, int current, vector<int> &dp) {
    // base case
    cout << current << space <<dp[current] <<newLine;
    if (arr[current] == 0) {
        return dp[current] = 1;
    } else if (dp[current] == -1){
        int firstPos = current + arr[current] < arr.size() ? recur(arr, current + arr[current], dp) : 0;
        int secondPos = current - arr[current] >= 0 ? recur(arr, current - arr[current], dp) : 0;
        dp[current] = firstPos + secondPos;
        return dp[current];
    } else {
        return dp[current];
    }
}

bool canReach(vector<int>& arr, int start) {
    vector <int> dp(arr.size(), -1);
    // base case
    return bool(recur(arr, start, dp));
}

int main() {
    vi arr{3,0,2,1,2};
    int start = 2;

    cout << canReach(arr, start) << newLine;
}