#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& image,
             int oldColor, int newColor) {

        int n = image.size();
        int m = image[0].size();

        // boundary + color check
        if (r < 0 || c < 0 || r >= n || c >= m)
            return;

        if (image[r][c] != oldColor)
            return;

        // fill color
        image[r][c] = newColor;

        // 4 directions
        dfs(r+1, c, image, oldColor, newColor);
        dfs(r-1, c, image, oldColor, newColor);
        dfs(r, c+1, image, oldColor, newColor);
        dfs(r, c-1, image, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int newColor) {

        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;

        dfs(sr, sc, image, oldColor, newColor);
        return image;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<vector<int>> image(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> image[i][j];

    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;

    Solution sol;
    vector<vector<int>> res = sol.floodFill(image, sr, sc, newColor);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << res[i][j];
            if (j + 1 < m) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
