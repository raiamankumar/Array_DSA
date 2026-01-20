#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> topologicalsort(int v,vector<vector<int>>&adj){
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto nbr:adj[i]){
                indegree[nbr]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto nbr:adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return topo;
    }
};

int main(){
    Solution sol;
    int v,e;
    if(!(cin>>v>>e)){
        // No input provided; use example graph
        v = 6; e = 6;
        vector<vector<int>> adj(v);
        vector<pair<int,int>> edges = {{5,2},{5,0},{4,0},{4,1},{2,3},{3,1}};
        for(auto &p: edges) adj[p.first].push_back(p.second);
        auto topo = sol.topologicalsort(v, adj);
        for(size_t i=0;i<topo.size();++i){
            if(i) cout<<" ";
            cout<<topo[i];
        }
        cout<<"\n";
        return 0;
    }

    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int a,b; cin>>a>>b; // directed edge a -> b
        adj[a].push_back(b);
    }
    auto topo = sol.topologicalsort(v, adj);
    if((int)topo.size() != v){
        cout<<"Graph has a cycle; topological ordering not possible\n";
        return 0;
    }
    for(size_t i=0;i<topo.size();++i){
        if(i) cout<<" ";
        cout<<topo[i];
    }
    cout<<"\n";
    return 0;
}
