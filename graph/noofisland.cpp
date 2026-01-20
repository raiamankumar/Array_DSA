#include<bits/stdc++.h>
using namespace std;
class Solution{
   public:
    void dfs(int r, int c, vector<vector<char>>& grid, int n, int m){
        // boundary check
        if(r < 0 || c < 0 || r >= n || c >= m)
            return;

        // water check
        if(grid[r][c] == '0')
            return;

        // mark visited
        grid[r][c] = '0';

        // 4 directions
        dfs(r+1, c, grid, n, m);
        dfs(r-1, c, grid, n, m);
        dfs(r, c+1, grid, n, m);
        dfs(r, c-1, grid, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();

        int islands = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid, n, m);
                    islands++;
                }
            }
        }

        return islands;
    }

};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if(!(cin >> n >> m))
        return 0;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> grid[i][j];

    Solution sol;
    int result = sol.numIslands(grid);
    cout << result << '\n';

    return 0;
}
