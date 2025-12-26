#include<bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u <= n && v >= 0 && v <= n) {
            adj[u].push_back(v);
            adj[v].push_back(u); // assume undirected graph
        }
    }

    int start;
    cin >> start;
    vector<bool> visited(n + 1, false);
    bfs(start, adj, visited);
    cout << '\n';
    return 0;
}