#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
    WordDictionary *next[26];
    bool wordEnd;
    WordDictionary() {
        for (int i = 0; i < 26; i++) {
            this -> next[i] = nullptr;
        }
        this -> wordEnd = false;
    }
    
    void addWord(string word) {
        // traverse from the beginning
        // to convert strings to character int index
        WordDictionary *curr = this;
        for (int i = 0; i < word.length(); i++) {
            int charInd = int(word[i]) - 97;
            if (curr -> next[charInd] == nullptr) {
                // create a new node and attach
                curr -> next[charInd] = new WordDictionary();
            }
            curr = curr -> next[charInd];
        }
        curr -> wordEnd = true;
    }

    void printTrie(WordDictionary *curr, string prev = "") {
        // cout << prev << curr -> wordEnd << endl;
        for (int i = 0 ; i < 26; i++) {
            if (curr -> next[i] != nullptr) {
                printTrie(curr -> next[i], prev + char(i+97));
            }
        }
        if (curr -> wordEnd) {
            cout << prev << "\n";
        }
        return;
    }

    bool searchHelper(WordDictionary *curr, string &word, int st) {
        cout << word << " " << st << endl;
        // see if the word can be found
        for (int i = st; i < word.length(); i++) {
            if (word[i] == '.') {
                bool found = false;
                for (int j = 0; j < 26; j++) {
                    if (curr -> next[j] != nullptr and searchHelper(curr -> next[j], word, i + 1)) {
                        found = true;
                        break;
                    }
                }
                return found;
            } else {
                int charInd = int(word[i]) - 97;
                if (curr -> next[charInd] == nullptr) {
                    return false;
                }
                curr = curr -> next[charInd];
            }
        }
        return curr -> wordEnd;
    }
    
    bool search(string word) {
        return searchHelper(this, word, 0);
    }
};

int main () {
    WordDictionary *obj = new WordDictionary();
    obj -> addWord("bad");
    obj -> addWord("dad");
    obj -> addWord("pad");
    obj -> printTrie(obj);
    cout << obj -> search("bap");
}