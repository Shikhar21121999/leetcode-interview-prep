#include <bits/stdc++.h>
using namespace std;

/*
This is a key question almost
Approach is to use bit manipulation mainly XOR
we find the xor of whole array and store in xorResult
xorResult = p ^ q; where p and q are numbers that are
not repeated in the nums array
next we find a bit which we can use to find one of the number
get an active bit (rightMost) in xorResult
this bit would be active in one of the p or q and inactive in other
next traverse throught nums array and xor xorResult only with those elements
which have this bit active, this would cancel out one number
in xorResult and we get one of the number in answers
*/

vector <int> singleNumbers(vector <int> nums) {
    long long xorResult = 0;
    for (auto num: nums) {
        xorResult ^= long(num);
    }

    int setBitNo = xorResult & ~(xorResult - 1);

    vector <int> ans(2,0);

    for (auto num: nums) {
        if (num & setBitNo) {
            ans[0] ^= num;
        }
    }
    ans[1] = xorResult ^ ans[0];
    return ans;
}

int main () {

}