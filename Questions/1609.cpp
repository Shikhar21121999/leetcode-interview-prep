#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// brute force
// check and try to match each node of 1 linked list with other

// optimized
// use hashmap to store visited listNodes from 1 linked list
// traverse the second linked list and return the first that is already visited

// optimal 1
// find the length of the lists len1 and len2
// get the difference
// have a pointer to beginning of the two lists
// move pointer at bigger list diff times in advance
// start moving the two pointers till they both point to same thing
// this same node is the answer


// optimal 2
// this is a more cleaner way of doing optimal1
// basic approach is that somehow we have to remove the difference
// between the two pointers when they begin
// start traversing the ll from start
// when the pointer reachers null point it to opposite
// the point at which they meet is the intersection

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // base case
        if (headA == NULL or headB == NULL) {
            return NULL;
        }
        ListNode *curr1 = headA, *curr2 = headB;

        while (curr1 != curr2) {
            curr1 = curr1 ? curr1 -> next : headB;
            curr2 = curr2 ? curr2 -> next : headA;
        }
        return curr1;
    }
};