#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

bool topologicalSortDfs(vvi &graph, vi &vis, int node, vi &order) {
    vis[node] = 1; // represent gray 
    for (auto x: graph[node]) {
        // visit the unvisited nodes (vis[x] = 0)
        if (vis[x] == 0) {
            if (topologicalSortDfs(graph, vis, x, order)) {
                return true;
            }
        } else if(vis[x] == 1) {
            // do we find a node already visited (gray colored)
            return true;
        }
    }
    order.push_back(node);
    return false;
}

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        // create a adjacency list graph
        vvi adj(n);


        for (auto x: edges) {
            adj[x[0]].push_back(x[1]);
        }

        // helper storage
        vi vis(n,0);
        vi order;
        bool isCyclic = false;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0 && topologicalSortDfs(adj, vis, i, order)) {
                isCyclic = true;
                break;
            }
        }

        if (isCyclic) {
            return vi {};
        } else {
            reverse(order.begin(), order.end());
            return order;
        }
    }
};