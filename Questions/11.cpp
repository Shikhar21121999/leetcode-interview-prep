#include <bits/stdc++.h>
using namespace std;

# define vi vector<int>
# define vvi vector<vi>
# define pii pair<int,int>
# define vpii vector<pii>
# define vvpii vector<vpii>
# define space " "
# define newLine "\n"

int maxArea(vector<int>& height) {
    int first = 0; int last = height.size() - 1;

    int ans = 0;
    while(first <= last) {
        ans = max(ans, min cost(height[first], height[last]) * (last - first));
        cout << first << space << last << space << ans <<  newLine;
        if (height[first] <= height[last]) {
            first ++;
        } else {
            last --;
        }
    }
    return ans;
}

// [1,8,6,2,5,4,8,3,7]
// select two elements from the list x, y at index i, j
// ans = min(x, y) * (j - i) or ans = min(height[i] - height[j]) * (j - i)
// do this for each i and j provided j is always after i
// Time Complexity = O(N^2)

// Optimize
// simply use two pointer technique
// consider both the indexes as edge of continaer at a time inclusive
// at each time area = min(height[i] - height[j]) * (j - i) maximize it
// increment or decrement according to the min of height

int main() {
    vi height{1,8,6,2,5,4,8,3};
    cout << maxArea(height) << newLine;
}