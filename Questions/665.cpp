#include <bits/stdc++.h>
using namespace std;

# define vi vector<int>
# define vvi vector<vi>
# define pii pair<int,int>
# define vpii vector<pii>
# define vvpii vector<vpii>
# define space " "
# define newLine "\n"

bool checkPossibility(vector<int>& nums) {
    int cnt = 0;
    for(int i=0; i < nums.size() - 1; i++ ) {
        // problem
        if (nums[i] > nums[i+1]) {
            
            // two fixes possible
            if (i-1 < 0 || nums[i-1] <= nums[i+1]) {
                nums[i] = nums[i+1]
            } else {
                nums[i+1] = nums[i];
            }
            cnt ++;
        }
    }
    return cnt < 2;
}

// first approach is to see if there are two occurences
// that voilate non-decreasing property
// conditions nums[i] <= nums[i+1] should always be satisfied

// nums[i] > nums[i+1] needs to be fixed where ever find
// two points to remember => there should only 1 problem and that too should be fixable


[5,7,1,8]

int main() {
    vi height{1,8,6,2,5,4,8,3};
    cout << maxArea(height) << newLine;
}