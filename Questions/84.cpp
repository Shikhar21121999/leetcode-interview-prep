#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int >
#define vpii vector < pii >
#define vi vector <int>
/*
Approach
Think it like we are on a certain element or height index i,
we consider a rectangle of height h that can be formed
this can be done by finding the boundary on left and right
for which a[left] < ele and a[right] < ele
this in turn gives us width as right - left + 1
a[i] * width becomes a possible arr
now we just need to maximize for arr
*/

// returns an array of index of previous smaller element for the array
vector <int> generatePrevSmallerElementIndex(vector <int> &nums) {
    int n = nums.size();
    stack <pii> st;
    // storing only index in ans
    vector <int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        while(!st.empty() and st.top().first >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top().second;
        }
        st.push(make_pair(nums[i], i));
    }
    return ans;
}

// returns an array of index of next smaller element for the array
vector <int> generateNextSmallerElementIndex(vector <int> &nums) {
    int n = nums.size();
    stack <pii> st;
    vector <int> ans(n, n);
    for (int i = n-1; i >= 0; i--) {
        while(!st.empty() and st.top().first >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top().second;
        }
        st.push(make_pair(nums[i], i));
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    
    // we need to fetch next smaller element index
    // and previous smaller element for an index in O(1)
    int n = heights.size();

    vector <int> PSI = generatePrevSmallerElementIndex(heights);
    vector <int> NSI = generateNextSmallerElementIndex(heights);

    int maxArra = 0;

    for (int i = 0 ; i < n; i++) {
        int width = NSI[i] - PSI[i] -1;
        cout << heights[i] << " " << NSI[i] << " " << PSI[i] << " " << width << "\n"; 
        maxArra = max(maxArra, width * heights[i]);
    }
    return maxArra;

}

void printVector (vi &a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << "\n";
}

int main () {
    vector <int> a = {4,2,0,3,2,4,3,4};
    printVector(a);
    vi PSI = generatePrevSmallerElementIndex(a);
    printVector(PSI);
    vi NSI = generateNextSmallerElementIndex(a);
    printVector(NSI);
    cout << largestRectangleArea(a);

}