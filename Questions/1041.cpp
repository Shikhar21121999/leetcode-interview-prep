#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>
#define vvi vector <vi>

/*
Approach is simple straight forward implementation
*/
bool isRobotBounded(string instructions) {
    // represents north
    int direction_code = 0;
    vector <pair <int, int>> recd = {
        make_pair(0,1),
        make_pair(-1,0),
        make_pair(0,-1),
        make_pair(1,0)
    };
    pair <int, int> position = {0,0};
    for(int i=0; i<4; i++) {
        for (auto dir:instructions) {
            if (dir == 'G') {
                // increment one position to current position
                position.first += recd[direction_code].first;
                position.second += recd[direction_code].second;
            } else {
                // change direction
                if (dir == 'L') {
                    direction_code += 1;
                } else {
                    direction_code -= 1;
                }
            }
            if (direction_code < 0) {
                direction_code = 0;
            } else {
                direction_code = direction_code % 4;
            }
            cout << i << " " << position.first << " " << position.second << " " << direction_code << endl;
        }
    }

    return (position.first == 0 and position.second == 0 && direction_code == 0);
}

int main() {
    string inp;
    cin >> inp;

    cout << isRobotBounded(inp);
}
