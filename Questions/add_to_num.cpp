#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main()
{
    int firstNum, secondNum;
    cin >> firstNum >> secondNum;
    int sumOfTwoNumbers;
    auto start = chrono::high_resolution_clock::now();
    sumOfTwoNumbers = firstNum + secondNum;
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cout << "Sum of numbers " << firstNum << " " << secondNum << endl;
    cout << "Time taken by function: " << duration.count() << " nanoseconds" << endl;

    return 0;
}

