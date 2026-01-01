#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> map;

// Direction arrays for moving Up, Down, Left, Right
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// Depth First Search to visit all connected floor tiles
void dfs(int r, int c) {
    // Boundary checks and Wall check
    if (r < 0 || r >= n || c < 0 || c >= m || map[r][c] == '#') {
        return;
    }

    // Mark current cell as visited (turn it into a wall)
    map[r][c] = '#';

    // Visit all 4 neighbors
    for (int i = 0; i < 4; i++) {
        dfs(r + dr[i], c + dc[i]);
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    map.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    int rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If we find a floor, it's a new room
            if (map[i][j] == '.') {
                dfs(i, j);
                rooms++;
            }
        }
    }

    cout << rooms << endl;

    return 0;
}