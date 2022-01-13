#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>

/*
Approach is to get min un-mergable insertion intervals and return count of them
a interval is mergable if second interval shares some part with interval
points[j][0] < points[i][1], here we keep intersected part of interval
new interval after merging would be 
max(points[i][0], points[j][0]), min(points[i][1], points[j][1])
at any point when intervals are consecutive intervals are un-mergable
increment the counter and consider next interval 
*/

// compare two vectors by first element
bool compare(vi a, vi b) {
    return a[0] < b[0];
}

int findMinArrowShots(vector<vector<int>>& points) {
    // to count un-mergable intervals
    int int_counter = 0;

    // sort the points
    sort(points.begin(), points.end(), compare);
    if (points.size() == 1) {
        return 1;
    }

    vi last_interval = points[0];

    // counting un-mergable points
    for(int curr = 1; curr < points.size(); curr ++) {
        // mergable condition
        if (points[curr][0] < last_interval[1]) {
            // intersect intervals to create new interval
            last_interval[0] = max(last_interval[0], points[curr][0]);
            last_interval[1] = min(last_interval[1], points[curr][1]);
        } else {
            // the two intervals are non intersecting
            int_counter ++;
            last_interval = points[curr];
        }
    }
    return int_counter;
}

int main() {

}