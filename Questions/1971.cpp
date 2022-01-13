#include <bits/stdc++.h>
using namespace  std;
#define vi vector <int>
#define vvi vector <vi>

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        // create a adj list graph
        vvi adj(n);

        for (auto x: edges) {
            // bi-directional
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vi vis(n,0);

        // bfs iterative traversal to check
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == end) {
                return true;
            } 
            for (auto x: adj[curr]) {
                if (!vis[x]) {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        return vis[end];
    }
};