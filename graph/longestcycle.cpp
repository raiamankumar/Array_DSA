#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCycleLen=-1;
    void DfsForLongestCycle(int cyclelen,int node,vector<int>&current_path,vector<int>&visited,vector<int>&edges){
        cyclelen++;
        current_path[node]=cyclelen;
        visited[node]=1;
        int nbr=edges[node];
        if(nbr !=-1){
            if(!visited[nbr]){
                DfsForLongestCycle(cyclelen,nbr,current_path,visited,edges);
            }
            else{
                if(current_path[nbr]!=0){
                    int currentcyclelen=current_path[node]-current_path[nbr]+1;
                    longestCycleLen=max(longestCycleLen,currentcyclelen);
                }
            }
        }
        current_path[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>current_path(n,0);
        vector<int>visited(n,0);
            for(int i=0;i<n;i++){
            if(visited[i]==0){
                DfsForLongestCycle(0,i,current_path,visited,edges);
            }
        }

        return longestCycleLen;
    }
};
int main(){
    Solution s;
    int n;
    if(!(cin>>n)){
        // No input provided; use example
        vector<int> edges={3,3,4,2,3};
        int res=s.longestCycle(edges);
        cout<<res<<"\n";
        return 0;
    }

    vector<int> edges(n);
    for(int i=0;i<n;i++) cin>>edges[i];
    int res=s.longestCycle(edges);
    cout<<res<<"\n";
    return 0;
}