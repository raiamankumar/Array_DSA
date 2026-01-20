#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void dfs(int r, int c, vector<vector<char>>& grid, int n, int m){
        // boundary check
        if(r < 0 || c < 0 || r >= n || c >= m)
            return;

        // rotten orange check
        if(grid[r][c] != '1')
            return;

        // mark visited (rotten)
        grid[r][c] = '2';
        

        // 4 directions
        dfs(r+1, c, grid, n, m);
        dfs(r-1, c, grid, n, m);
        dfs(r, c+1, grid, n, m);
        dfs(r, c-1, grid, n, m);
    }
    int rottenOranges(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();

        int rotten_count = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '2'){
                    dfs(i, j, grid, n, m);
                }
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '1'){
                    rotten_count++;
                }
            }
        }

        return rotten_count;
    }
}