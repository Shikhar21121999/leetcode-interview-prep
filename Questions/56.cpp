#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define space " "
#define newLine "\n"

// Given an array of intervals where intervals[i] = [starti, endi],
// merge all overlapping intervals, and return an array of 
// the non-overlapping intervals that cover all the intervals in the input.

bool compare (vi a, vi b) {
    return a[0] <= b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // sort + two pointer technique
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), compare);

    for (auto x: intervals) {
        cout << x[0] << space << x[1] << newLine;
    }

    if (intervals.size() == 1) {
        return intervals;
    } 

    vvi result;
    int start = 0;
    int next = 1;

    while(next < n) {
        // check if interval at next can be combined with start interval
        cout << "{" << intervals[start][0] << space << intervals[start][1] <<  "}" << space << "{" << intervals[next][0] << space << intervals[next][1] << "}" << newLine;
        if (intervals[start][1] >= intervals[next][0]) {
            // combine the next interval into first
            intervals[start][1] = max(intervals[start][1], intervals[next][1]);
        }
        else {
            result.push_back(intervals[start]);
            start = next;
        }
        next ++;
    }
    result.push_back(intervals[start]);
    // last interval will be left out
    // last interval can be start if merged
    // if unmerged last interval will be next
    return result;
}

int main() {
    vvi intervals = {{1,3},{2,6},{8,10},{15,18}};
    vvi ans = merge(intervals);
    cout << "answer \n";
    for (auto x: ans) {
        cout << x[0] << space << x[1] << newLine; 
    }

}