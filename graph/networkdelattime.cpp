#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Step 1: Build adjacency list
    vector<pair<int,int>> adj[n+1]; // node: 1 to n
    for(auto &edge : times){
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
    }
    
    // Step 2: Distance array (1-indexed)
    vector<int> dist(n+1, INT_MAX);
    dist[k] = 0;
    
    // Step 3: Min-heap {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, k});
    
    // Step 4: Dijkstra
    while(!pq.empty()){
        auto [currDist, node] = pq.top(); pq.pop();
        
        // Skip if we already found a shorter path
        if(currDist > dist[node]) continue;
        
        for(auto [adjNode, w] : adj[node]){
            if(currDist + w < dist[adjNode]){
                dist[adjNode] = currDist + w;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    
    // Step 5: Find the maximum distance
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] == INT_MAX) return -1; // unreachable node
        ans = max(ans, dist[i]);
    }
    
    return ans;
}
