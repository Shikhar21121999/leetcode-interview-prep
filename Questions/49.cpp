#include <bits/stdc++.h>
using namespace std;

// brute force with optimization

// TC = O(s.length())
bool isAnagram(string s, string t) {
    vector <int> sp(26, 0);
    if (s.length() != t.length()) {
        return false;
    }
    for (int i = 0; i < s.length(); i++) {
        sp[s[i] - 'a'] += 1;
        sp[t[i] - 'a'] -= 1;
    }
    vector <int> zero(26, 0);
    return (sp == zero);
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector < vector < string > > ans;
    int n = strs.size();
    vector <int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector <string> ani;
        ani.push_back(strs[i]);
        for (int j = i + 1; j < n; j++) {
            if (vis[j]) continue;
            if (isAnagram(strs[i], strs[j])) {
                ani.push_back(strs[j]);
                vis[j] = 1;
            }
        }
        ans.push_back(ani);
    }
    return ans;
}

// anagrams have a property that after sorting the two anagrams become 1 string
// we can use this to make sorted version as key
// and storing them in vector at end getting all the different anagram groups
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map <string, vector <string> > recd;

    for (string curr: strs) {
        string t = curr;
        sort(t.begin(), t.end());
        recd[t].push_back(curr);
    }

    vector <vector <string>> ans;
    for (auto strVec: recd) {
        ans.push_back(strVec.second);
    }
    return ans;
}


int main () {
    vector <string> a = {"eat","tea","tan","ate","nat","bat"};
    auto ans = groupAnagrams(a);
    for (auto group: ans) {
        for(auto word: group) {
            cout << word << " ";
        }
        cout << endl;
    }
}