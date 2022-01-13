#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>

// complement of base 10 integer

int bitWiseComplement(int N, int c=1) {
    while(c < N) c = (c << 1) + 1;
    return N ^ c;
}