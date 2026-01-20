#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&visited,vector<int>&current_path){
        visited[node]=1;
        current_path[node]=1;
        for(auto nbr:graph[node]){
            if(!visited[nbr]){
                bool isCyclic=dfs(nbr,graph,visited,current_path);
                if(isCyclic){
                    return true;
                }
            }
            else{
                if(current_path[nbr]==1){
                    return true;
                }
            }
        }
        current_path[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>visited;
        vector<int>current_path;
        for(int i=0;i<graph.size()-1;i++){
            if(!visited[i]){
                dfs(i,graph,visited,current_path);
            }
        }
        vector<int>res;
        for(int i=0;i<graph.size()-1;i++){
            if(current_path[i]==0){
                res.push_back(i);
            }
        }
        return res;
    }
};
int main(){
    // Example graph from LeetCode
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    Solution s;
    vector<int> res = s.eventualSafeNodes(graph);
    for(size_t i=0;i<res.size();++i){
        cout<<res[i];
        if(i+1<res.size()) cout<<" ";
    }
    cout<<"\n";
    return 0;
}
