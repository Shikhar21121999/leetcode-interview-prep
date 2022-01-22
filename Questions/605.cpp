#include <bits/stdc++.h>
using namespace std;

void printVector (vector <int> a) {
    for (auto x: a) {
        cout << x << " ";
    }
}

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    flowerbed.insert(flowerbed.begin(),0);
    flowerbed.push_back(0);
    for(int i = 1; i < flowerbed.size()-1; ++i)
    {
        if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0)
        {
            --n;
            ++i;
        }
            
    }
    return n <=0;
}

int main() {

}