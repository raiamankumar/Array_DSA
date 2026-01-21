#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1){
             return false;
        }

        vector<vector<int>> graph(n);
        for(const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        int count_visit=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count_visit++;
            for(auto &nbr:graph[node]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
        }
        return count_visit == n;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution sol;
    bool result = sol.validTree(n, edges);
    cout << (result ? "true" : "false") << '\n';

    return 0;
}