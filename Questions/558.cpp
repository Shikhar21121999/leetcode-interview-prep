#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node () {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node* intersect(Node* quadTree1, Node* quadTree2) {
    // base case
    if (quadTree1 -> isLeaf and quadTree2 -> isLeaf) {
        quadTree1 -> val = quadTree1 -> val or quadTree2 -> val;
        return quadTree1;
    }

    // if one of them is leaf
    if (quadTree1 -> isLeaf or quadTree2 -> isLeaf) {
        Node *leafTree = quadTree1 -> isLeaf ? quadTree1 : quadTree2;
        Node *nonLeafTree = quadTree1 == leafTree ? quadTree2 : quadTree1;
        if (leafTree -> val == 1) {
            return leafTree;
        }
        return nonLeafTree;
    }

    // none of the trees are leaf trees hence
    // equivalent tree will be constructed by getting or of child trees
    Node* topLeft = intersect(quadTree1 -> topLeft, quadTree2 -> topLeft);
    Node* topRight = intersect(quadTree1 -> topRight, quadTree2 -> topRight);
    Node* bottomLeft = intersect(quadTree1 -> bottomLeft, quadTree2 -> bottomLeft);
    Node* bottomRight = intersect(quadTree1 -> bottomRight, quadTree2 -> bottomRight);

    // if all the child are 1 this tree becomes 1
    if (topLeft -> isLeaf and topRight -> isLeaf and bottomLeft -> isLeaf and bottomRight -> isLeaf) {
        // if all are true
        bool allAreSame = (topLeft -> val and topRight -> val and bottomLeft -> val and bottomRight -> val) or 
            !(topLeft -> val or topRight -> val or bottomLeft -> val or bottomRight -> val);
        
        if (allAreSame) {
            Node *root = new Node(topLeft -> val, true);
            return root;
        }
    }
    Node *root = new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    return root;
}

int main () {

}