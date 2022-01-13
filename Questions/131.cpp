#include <bits/stdc++.h>
using namespace std;
# define vs vector <string>
# define vvs vector <vs>


void printVector (vector <string> a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;
}

bool isPallindrome(string s) {
    int n = s.length();

    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n - i - 1]){
            return false;
        }
    }
    return true;
}

vector < vector <string> > partition (string s) {
    vector < vector < string > > ans;
    // base case
    if (s.length() == 1) {
        ans.push_back(vector <string> {s});
        return ans;
    }

    // is string pallindrome
    if (isPallindrome(s)) {
        ans.push_back(vs {s});
    }
    unordered_map < string, int > recd;

    // try splitting the string into two strings and create partition out of it
    for (int len = 1; len < s.size(); len++) {
        vvs first = partition(s.substr(0, len));
        vvs second = partition(s.substr(len, s.size()));

        for (auto x: first) {
            for (auto y: second) {
                vs temp = x;
                temp.insert(temp.end(), y.begin(), y.end());
                string key = "";
                for (auto z: temp) {
                    key = key + z + "#"
                }
                if (recd[key] == 0) {
                    recd[key] = 1;
                    ans.push_back(temp);
                }
            }
        }
    }

    return ans;
}

// denote string as an index which denotes starting point
// till end

vector < vector <string> > partition (string s) {
    vector < vector <string > > result;
    vector < string > path;
    helper(0, s, path, result);
    return result;
}

bool isPallindrome1(string &s, int start, int end) {
    while(start <= end) {
        if (s[start] != s[end]) {
            return false;
        }
    }
    return true;
}

void helper(int index, string &s, vector <string> &path, vector < vector <string>> result ) {
    // base case
    if (index == s.size()) {
        result.push_back(path);
        return;
    }

    // recursively look for all the partitions
    for (int i=index; i < s.size(); i++) {
        if (isPallindrome1(s, index, i)) {
            // do
            path.push_back(s.substr(index, i - index + 1));
            // recur
            helper(i+1, s, path, result);
            // revert
            path.pop_back();
        }
    }
}

// backtracking approach

// base case (final answer collection)
// add the pallindrome partitioning of whole string to answer

// recursive cases
// backtracking says
// change
// recur
// reverse



int main() {

}