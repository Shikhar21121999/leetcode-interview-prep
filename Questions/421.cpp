#include <bits/stdc++.h>
using namespace std;

/*
This code is not yet completely bug free
please check and correct later
*/

/*
Approach is to use trie,
we create a trie starting from the leftmost bit
this in turn helps denote number in terms of common bits
then we for each number we generate the closest possible complement
this in turn finds the greatest xor possible for this number
at end we see the max result possible
*/

class TrieNode {
    public:
        TrieNode *next[2];
        TrieNode () {
            this -> next[0] = nullptr;
            this -> next[1] = nullptr;
        }
};

TrieNode* buildTrie(vector <int> &nums) {
    TrieNode *root = new TrieNode();
    TrieNode *curr;
    for (int i = 0; i < nums.size(); i++) {
        curr = root;
        for (int j = 31; j >= 0; j--) {
            int index = (nums[i] >> j) & 1;
            if (curr -> next[index] == nullptr) {
                curr -> next[index] = new TrieNode();
            }
            curr = curr -> next[index];
        }
    }
    return root;
}

// conditions
// for a number num
// we are finding the xor of num with a number such that xor found is max
// for this we get a bit numbit (from left) of num
// for this numbit we traverse down the trie
// such that TrieNode is traversed (thereby trying to keep left bits active in xor)
// keep on generating equivalent xor

// find the maximum possible xor for this number
// corresponding to elements present in the trie
int findMaxXor(TrieNode *&curr, int num) {
    int res = 0;

    for (int i = 31; i >= 0; i--) {
        int numbit = (num >> i) & 1;
        int index = numbit ? 0 : 1;
        if (curr -> next[index]) {
            // now either next trie node for this index exists
            curr = curr -> next[index];
            res = (res << 1) | 1;
        } else {
            // in case it does not exist
            // we choose same bit and try to find more set bits later
            res = (res << 1) & 0;
            curr = curr -> next[index ? 0 : 1];
        }
    }
    return res;
}

int findMaximumXOR(vector<int>& nums) {
    int ans = 0;
    TrieNode *root = buildTrie(nums);

    int res = 0;
    for(auto num: nums) {
        res = max(res, findMaxXor(root, num));
    }
    return res;
}

int findMaxXORNaieve(vector <int> &nums) {
    int ans = 0;
    pair <int, int > greatest;
    sort(nums.begin(), nums.end());
    for (int i=0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if ((nums[i] ^ nums[j]) > ans) {
                ans = nums[i] ^ nums[j];
                greatest = make_pair(nums[i], nums[j]);
                cout << greatest.first << " " << greatest.second << endl;
            }
        }
    }
    return ans;
}

int main () {
    vector <int> a = {14,70,53,83,49,91,36,80,92,51,66,70};
    cout << findMaxXORNaieve(a);
}