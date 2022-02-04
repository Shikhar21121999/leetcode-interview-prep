#include <bits/stdc++.h>
using namespace std;

// brute force approach
// for each element check if a another element to the left of it exists

// optimized approach
// create a vis array and keep seeing if element is visited already

// optimal approach (best) (key question)
/*
Observations => for length n of linked list
element in the array will be in the range 1 to n-1
Assume we are visiting element of the array in fashion such that
arr[i] represent the next index
that we traverse after visiting element at i
Now for this we need some confirmations 
we should never we going out of bound
as we said 1 <= arr[i] <= n-1 is the range for arr[i]
hence we conclude we never go out of bound
and we should never get stuck that is visiting a node again and again
this can be assured by starting with initial index as n-1
and we visit next number nums[i-1]
hence to get stuck we would need a number to point to n which is not possible
*/

/*
After this discussion question reduces to finding
beginning of cycle in linked list
Use tortoise hare algo here
*/

int findDuplicate(vector<int>& nums) {
    int n = nums.size();

    int slow = n;
    int fast = n;

    do {
        slow = nums[slow - 1];
        fast = nums[nums[fast - 1]-1];
    } while (slow != fast);

    fast = n;
    while(slow != fast) {
        slow = nums[slow - 1];
        fast = nums[fast - 1];
    }
    return slow;
}

int main () {

}