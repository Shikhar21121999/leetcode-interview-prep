#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node () {
        this -> val = 0;
        this -> prev = nullptr;
        this -> next = nullptr;
        this -> child = nullptr;
    }
};

Node* flattenModified (Node* head) {
    Node *curr = head;
    Node *tail;
    while (curr != NULL) {
        tail = curr;
        if (curr -> child != NULL) {
            Node* flatChildTail = flattenModified(curr -> child);
            Node *currNext = curr -> next;
            curr -> child -> prev = curr;
            curr -> next = curr -> child;
            flatChildTail -> next = currNext;
            if (currNext != NULL) {
                currNext -> prev = flatChildTail;
            }
            curr -> child = NULL;
        }
        curr = curr -> next;
    }
    return tail;
}

Node* flatten(Node* head) {
    // base case
    if (head == NULL) {
        return head;
    } 

    flattenModified(head);
    return head;
}


int main () {

}