#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>
#define vvi vector <vi>

void maxSelf(int &a, int b) {
    a = max(a, b);
}

int maxDistToClosest(vector<int>& seats) {
    vector <int> fill_seats_ind;
    fill_seats_ind.reserve(2*10^4);
    int n = seats.size();
    for (int i = 0; i < n; i++) {
        if (seats[i] == 1) {
            fill_seats_ind.push_back(i);
        }
    }
    int k = fill_seats_ind.size();
    int ans = 0;
    // first and last chair only possible if first and last seats are empty
    if (seats[0] == 0) {
        ans = fill_seats_ind[0];
    }
    if (seats[n-1] == 0) {
        maxSelf(ans, n-1 - fill_seats_ind[k-1]);
    }
    // try to insert seats between any two seats
    for (int i = 1; i < k; i++) {
        cout << i << endl;
        int seats_in_mid = fill_seats_ind[i] - fill_seats_ind[i-1] - 1;
        int max_dist_closest = seats_in_mid/2;
        if (seats_in_mid % 2) {
            max_dist_closest++;
        }
        maxSelf(ans, max_dist_closest);
    }
    return ans;
}

int main() {

}