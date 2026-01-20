#include<iostream>
using namespace std;
const int MAX = 1000;
int graph[MAX][MAX];
bool visited[MAX];
int n;
void dfs(int node) {
    visited[node] = true;
    for (int neighbor = 0; neighbor < n; neighbor++) {
        if (graph[node][neighbor] && !visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cin >> start;

    dfs(start);

    cout << "Nodes reachable from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }
    cout << '\n';

    return 0;
}