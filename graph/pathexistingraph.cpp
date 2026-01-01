#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<int>& visited, vector<vector<int>>& graph, int node) {
        queue<int> q;
        cout << "BFS start node: " << node << endl;
        q.push(node);
        visited[node] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << "visiting: " << curr << endl;
            for (auto neighbours : graph[curr]) {   // FIXED: use curr instead of node
                cout << "  neighbor: " << neighbours;
                if (!visited[neighbours]) {
                    cout << " (not visited) -> push" << endl;
                    q.push(neighbours);
                    visited[neighbours] = 1;
                }
                else {
                    cout << " (already visited)" << endl;
                }
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n, 0);
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bfs(visited, graph, source);
        return visited[destination];
    }
};

//DRIVER CODE
int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int source, destination;
    cout << "Enter source and destination: ";
    cin >> source >> destination;

    Solution sol;
    bool ans = sol.validPath(n, edges, source, destination);

    if (ans)
        cout << "Path exists between " << source << " and " << destination << "\n";
    else
        cout << "No path exists between " << source << " and " << destination << "\n";

    return 0;
}