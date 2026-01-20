#include <bits/stdc++.h>
using namespace std;
#include "findeventualsafestate.cpp"

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
