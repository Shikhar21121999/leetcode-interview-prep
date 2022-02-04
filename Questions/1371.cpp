#include <bits/stdc++.h>
using namespace std;

/*
Approach is to use bitMask + hashMap
*/

/*
Observations
We do not require number of vowels
We only require to check if vowels are equal
This is a subArray problem
If we can somehow determine that vowels occuring between two indexes
are even, we can say that this subString can be an answer
*/

/*
Thought process,
We need to keep track of wether vowels found are even or odd
between two indexes,
even or odd can be thought as in binary,
for 5 vowels we can in turn generate a bitMask,
which at each point stores info about vowels frequency
We use XOR such that vowels bit cancel out for even frequency
*/

/*
Now we have a way to denote state of vowels,
next step is to just check this state (running state),
for each index and see the first index for which we got this state
we are storing only for first index since we get longest length
for that
*/

/*
mask will be a integer with 5 bit,
the bits in mask will be manipulated using XOR,
*/

/*
We need a hashMap or vi implementation
to store the first index for which we got this state 
*/


int findTheLongestSubstring (string s) {
    map < char, int > vi; // to store vowel bit representation
    vi['a'] = 1;
    vi['e'] = 2;
    vi['i'] = 4;
    vi['o'] = 8;
    vi['u'] = 16;
    vector <int> maskMap(32, -1); // 32 combinations for 5 bit integer
    int mask = 0, ans = 0; // ans is used to optimize for length

    for (int i = 0; i < s.length(); i++) {
        // check for vowel
        if (vi.count(s[i]) > 0) {
            mask = mask ^ s[i];
        }
        // check if mask has been encountered before
        if (mask != 0 and maskMap[mask] == -1) { // special condition for mask = 0 since initial also -1
            maskMap[mask] = i;
        } else {
            ans = max(ans, i-maskMap[mask]);
        }
    }
    return ans;
}

int main () {

}