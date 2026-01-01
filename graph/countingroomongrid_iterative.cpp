#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    auto in_bounds = [&](int r, int c){
        return r >= 0 && r < n && c >= 0 && c < m;
    };

    int rooms = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '.') continue;

            // iterative DFS using stack
            stack<pair<int,int>> st;
            st.push({i,j});

            while (!st.empty()) {
                auto [r,c] = st.top(); st.pop();

                if (!in_bounds(r,c)) continue;
                if (grid[r][c] != '.') continue;

                grid[r][c] = '#'; // mark visited

                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (in_bounds(nr,nc) && grid[nr][nc] == '.') st.push({nr,nc});
                }
            }

            rooms++;
        }
    }

    cout << rooms << '\n';
    return 0;
}
