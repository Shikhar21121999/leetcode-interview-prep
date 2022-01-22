#include <bits/stdc++.h>
using namespace std;

// first node of loop in a linked list

class ListNode {
public:
	int data;
	ListNode* next;

	ListNode () {
		this -> next = NULL;
	}

	ListNode (int data) {
		this -> data = data;
		this -> next = NULL;
	}
};

/*
Approach is to use floyds cycle detection algo
here we use two pointers slow and fast
if slow and fast meet, a cycle detected
*/
ListNode *detectCycle(ListNode *head) {
	ListNode *slow = head, *fast = head;

	while(fast != nullptr && fast -> next != nullptr) {
		slow = slow -> next;
		fast = fast -> next -> next;
		if (slow == fast) {
			break;
		}
	}

	if (slow != fast) {
		return nullptr;
	}

	// find origin of cycle
	slow = head;
	while(slow != fast) {
		slow = slow -> next;
		fast = fast -> next;
	}
	return slow;
}