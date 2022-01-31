#include <bits/stdc++.h>
using namespace std;

class history {
    public:
        string url;
        history *prev;
        history *next;
    history (string url) {
        this -> url = url;
        this -> prev = nullptr;
        this -> next = nullptr;
    }
};

class BrowserHistory {
public:
    history *head;
    history *curr;
    BrowserHistory(string homepage) {
        this -> head -> url = homepage;
        this -> curr = this -> head;
    }
    
    void visit(string url) {
        history *newSite = new history(url);
        this -> curr -> next = newSite;
        newSite -> prev = this -> curr;
        this -> curr = newSite;
    }
    
    string back(int steps) {
        while (this -> curr -> prev != nullptr and steps--) {
            this -> curr = this -> curr -> prev;
        }
        return this -> curr -> url;
    }
    
    string forward(int steps) {
        while (this -> curr -> next != nullptr and steps--) {
            this -> curr = this -> curr -> next;
        } 
        return this -> curr -> url;
    }

    void fullHistory () {
        history *curr = this -> head;
        while (curr != nullptr) {
            cout << curr -> url << endl;
            curr = curr -> next;
        }
    }
};

int main () {
    string homepage = "google";
    BrowserHistory* obj = new BrowserHistory(homepage);
    obj->visit("leetcode");
    obj->visit("leetcode1");
    obj->visit("leetcode2");
    obj->visit("leetcode3");
    cout << obj->back(2) << endl;
    cout << obj->forward(1) << endl;
}