#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>

int main() {
    int num = 5;
    unsigned mask = ~0;
    cout << mask << endl;
    while (num & mask) {
        cout << num << " " << mask << endl;
        mask <<= 1;
    }
    cout << (~mask) << " " << (~num) << endl;
    cout << (~mask & ~num);
}