#include<bits/stdc++.h>
using namespace std;

class solution{
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& current_path) {
        visited[node] = 1;
        current_path[node] = 1;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, current_path)) {
                    return true;
                }
            } else if (current_path[neighbor]) {
                return true; // Cycle detected
            }
        }

        current_path[node] = 0; // Remove from recursion stack
        return false;
    }
    bool is_cyclic(int v, vector<vector<int>>& adj){
        vector<int> visited(v, 0);
        vector<int> current_path(v, 0);

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, current_path)) {
                    return true;
                }
            }
        }
        return false;
    }
}