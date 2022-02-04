#include <bits/stdc++.h>
using namespace std;

/*
We use sliding window approach for this
*/

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while(left <= right) {
        int tempSum = numbers[left] + numbers[right];
        if ( tempSum == target) {
            vector <int> ans = {left, right};
            return ans;
        } else {
            if (tempSum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
}
int main () {

}