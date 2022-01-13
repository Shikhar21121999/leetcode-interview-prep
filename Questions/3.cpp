#include <bits/stdc++.h>
using namespace std;

# define vi vector<int>
# define vvi vector<vi>
# define pii pair<int,int>
# define vpii vector<pii>
# define vvpii vector<vpii>
# define space " "
# define newLine "\n"

// Longest substring without repeating characters

// condition -> characters should not be repeated
// optimize for longest

// length 5*10^4  => soluction should be < O(N^2)

// hashing will be used to keep track of duplicate characters encountered till now

// condtion for including an element will be to check if it has been encountered or not

// can be done using two pointer technique
// the two pointers define a substring which does not have any duplicate strings
// if at any point a duplicate string is included we move the first one forward till we haven't removed the duplicate
// from first boundary

// defing the boundary or substring => keep both of them included
// hash map => since there are only english characters we can get away with an array

// abcdefghijklmnopqgtuvwxyz

int lengthOfLongestSubstring(string s) {
    int first = 0, last = 0;
    
    // base condition
    if (s.length() < 1) {
        return s.length();
    }
    int ans = 1;
    // map to store frequency of characters
    unordered_map <char, int> recd;

    while(last < s.length()) {
        // check if character at last can be included
        // cout << first << space << last << newLine;
        // for (auto x: recd) {
        //     cout << x.first << space << x.second << newLine;
        // }
        // cout << newLine;
        
        // if last character is not included
        if (recd[s[last]] == 0) {
            // include it
            recd[s[last]] += 1;
            ans = max(ans, last - first + 1);
            last ++;
        } else {
            // exclude first occurence of the character and include it from end

            while(recd[s[last]] > 0) {
                recd[s[first]] -= 1;
                first ++;
            }

            // include it from end
            recd[s[last]] += 1;
            last ++;
        }
    }
    return ans;
}

int main() {
    string inp;
    cin>>inp;
    // cout << "Heloo party"<<newLine;
    int ans = lengthOfLongestSubstring(inp);
    cout<<ans;

}