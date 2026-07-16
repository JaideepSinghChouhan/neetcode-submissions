class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {1, -1, 0, 0};
    int INF = INT_MAX;

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& dist,
             int x, int y, int n, int m, int steps) {

        if (x < 0 || y < 0 || x >= n || y >= m)
            return;

        if (grid[x][y] == -1)
            return;

        if (steps >= dist[x][y])
            return;

        dist[x][y] = steps;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            dfs(grid, dist, nx, ny, n, m, steps + 1);
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INF));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == -1)
                    dist[i][j] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, dist, i, j, n, m, 0);
                }
            }
        }

        grid = dist;
    }
};