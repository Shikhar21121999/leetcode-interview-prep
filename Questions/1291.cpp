#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>


/*
Generate first unique digit num for given number of digits
*/
int firstNumDigit(int dig) {
    if (dig > 9) {
        return 0;
    }
    int num = 0;
    for (int i = 1; i <= dig; i++) {
        num = num * 10 + i;
    }
    return num;
}

int firstDigit(int n)
{
    // Remove last digit from number
    // till only one digit is left
    while (n >= 10)
        n /= 10;
     
    // return the first digit
    return n;
}

int nextSeqDigit(int prev, int &dig) {
    int temp = int (pow(10, dig - 1));
    int lastDig = prev % 10;
    int firstDig = firstDigit(prev);
    if (lastDig == 9 or prev == 1) {
        dig += 1;
        return firstNumDigit(dig);
    }
    int nextNum = prev - firstDig*temp;
    nextNum = nextNum * 10 + lastDig + 1;
    return nextNum;
}

int getNumDigits (int num) {
    int numDigits = 0;
    while(num > 0) {
        numDigits++;
        num /= 10;
    }
    return numDigits;
}

vector<int> sequentialDigits(int low, int high) {
    int numDigits = getNumDigits(low);

    int seqDigit = firstNumDigit(numDigits);
    vector <int> ans;
    while (seqDigit <= high and seqDigit > 0) {
        if (seqDigit <= high and seqDigit >= low) {
            ans.push_back(seqDigit);
        }
        seqDigit = nextSeqDigit(seqDigit, numDigits);
    }
    return ans;
}

vector<int> sequentialDigits(int l, int h) {
    queue<int> q;
    for(int i = 1; i <= 9; i++) {
        q.push(i);
    }
    vector<int> ret;
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        if(f <= h && f >= l) {
            ret.push_back(f);
        }
        if(f > h)
            break;
        int num = f % 10;
        if(num < 9) {
            q.push(f * 10 + (num + 1));
        }
    }
    return ret;
}

int main() {
    int low = 10000000;
    int hi = 1000000000;
    vi ans = sequentialDigits(low, hi);
    for (auto x: ans) {
        cout << x << " ";
    }
    // int curr = 123;
    // int dig = 3;
    // cout << nextSeqDigit(curr, dig) << endl;
}