#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();

    if (n <= 2){
        return n;
    }
    int beg = 0;
    int curr = 1;
    int dup = 0;

    while(curr < n) {
        if (nums[beg] == nums[curr]) {
            if (dup < 1) {
                dup++;
                nums[++beg] = nums[curr];
            }
        } else {
            nums[++beg] = nums[curr];
            dup = 0;
        }
        curr++;
    }
    return beg+1;
}

int main () {
    vector <int> imp = {0,0,1,1,1,1,2,3,3};
    int ans = removeDuplicates(imp);
    for (int i = 0; i < ans; i++) {
        cout << imp[i] << " ";
    }
    cout << endl;
}