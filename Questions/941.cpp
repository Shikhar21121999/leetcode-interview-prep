#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>

bool validMountainArray (vector <int> &arr) {
    int seq = -1;
    // here seq represent ascending 0 or descending 1

    // initially strictly increasing
    // then after a point strictly decreasing
    // only 1 peak
    int n = arr.size();
    int seq = 0;
    // 0 represent strictly increasing
    // 1 represent strictly decreasing
    for (int i = 1; i < n-1 ; i++) {
        if (seq == 0 and arr[i] > arr[i-1]) {
            // strictly increasing
            continue;
        }
        if (seq == 0 and arr[i] < arr[i-1]) {
            // switch to decreasing
            seq = 1;
            continue;
        }
        else if (seq == 1 and arr[i] < arr[i-1]) {
            // strictly decreasing
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}