#include <bits/stdc++.h>
using namespace std;

// Merge two sorted arrays

// Brute force approach
/*
Merge the two arrays and sort the resultant array
TC -> O(PlogP) where p = nums1.size() + nums2.size()
SC -> O(P) // since we require to store all the elements first 
before sorting
*/

// Insertion Sort
/*
perform two pointer swap method,
make sure second array is sorted using insertion sort algo
implementation
TC => O(N*M)
SC => O(1)
*/

// helper function to put element at index ind to right place
// in a, such that a is sorted for all index except for ind
void helper (vector <int> &a, int ind) {
    while(ind < (a.size() - 1) and a[ind] < a[ind+1]) {
        swap(a[ind], a[ind+1]);
        ind++;
    }
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    // fill elements after m-1 with INT_MAX
    // so that at end elements from nums2 are filled

    for (int i = m; i < nums1.size(); i++) {
        nums1[i] = INT_MAX;
    }

    // two pointer shell sort implementation
    int curr1 = 0;
    int curr2 = 0;

    while (curr1 < nums1.size()) {
        if (nums1[curr1] > nums2[curr2]) {
            swap(nums1[curr1], nums2[curr2]);
            // put curr2 at right index in nums2
            helper(nums2, curr2);
        }
        curr1++;
    }
}

// Gap method or shell sort
/*
important point to remember is initial gap or shell size is
total ceil(length / 2) 
*/

int main () {
    vector <int> nums1 = {1,2,3,0,0,0};
    vector <int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    merge(nums1, m, nums2, n);
}