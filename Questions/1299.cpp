#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    int maxSoFar = -1;
    for (int i = arr.size() - 1; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = maxSoFar;
        maxSoFar = max(maxSoFar, temp);
    }
    return arr;
}

int main () {

}