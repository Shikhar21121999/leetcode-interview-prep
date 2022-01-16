#include <bits/stdc++.h>
using namespace std;
#define vi vector <int>
#define vvi vector <vi>

/*
Approach is to create a directed graph from the pre-requisites
it is possible to complete the courses only when a valid topoSort
exists for the graph
also we can topoSort only on the nodes which do not have a pre-requisite
*/

/*
The main problem is to only visit a node or complete the course
if all the pre-requisites are complete
we can't get the pre-requisites of the node if we create the graph
by making edges as course1 -> coruse 2 here course1 is pre-req for course2
to solve this we also store degree for each node
thereby a node can only be visited if its degree is 0 or num of pre-req = 0
so while creating the graph we store the degree of nodes and decrease it
once it becomes visitable from one of the parent node,
but we only visit this node(push into q)  when its degree becomes 0
*/

bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vvi adj(n);
    vi degree(n,0);
    for (auto x: prerequisites) {
        adj[x[1]].push_back(x[0]);
        degree[x[0]]++;
    }

    queue <int> q;
    for(int i = 0; i < n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        n--; //decrease remaining course 
        for(auto x: adj[curr]) {
            if (--degree[x] == 0) { 
                // this checks if the courses pre-req are met
                // and also ensures that we are not processing node
                // more than once in case of cycle
                q.push(x);
            }
        }
    }
    return n == 0; // checks if all the courses are completed only once
}