#include <bits/stdc++.h>
using namespace std;

# define vi vector<int>
# define vvi vector<vi>
# define pii pair<int,int>
# define vpii vector<pii>
# define vvpii vector<vpii>
# define space " "
# define newLine "\n"

// Add two numbers

// linked list are given as reversed

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // traverse the linked list and keep adding the two nodes

        // one of the linked list can be smaller
        // last digit can equate to greater than 10

        ListNode ansHead(0), *curr = &ansHead;
        int prevCarry = 0;
        while(l1 || l2 || prevCarry) {
            int newSum = (l1 ? l1 -> val : 0 ) + (l2 ? l2 -> val : 0 ) + prevCarry;
            prevCarry = newSum / 10;
            curr -> next = new ListNode(newSum % 10);
            curr = curr -> next;
            l1 = l1 ? l1 -> next : l1;
            l2 = l2 ? l2 -> next : l2;
        }
        return ansHead.next;
    }
};

int main() {
	
}