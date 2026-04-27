class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> connects = {
            {}, {0,1}, {2,3}, {0,3}, {1,3}, {0,2}, {1,2},
        };

        vector<int> dr = {0,0,-1,1};
        vector<int> dc = {-1,1,0,0};
        vector<int> opp = {1,0,3,2};

        auto hasDir = [&](int type, int dir) {
            for (int d : connects[type]) if (d == dir) return true;
            return false;
        };

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == m-1 && c == n-1) return true;
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;
                if (hasDir(grid[r][c], d) && hasDir(grid[nr][nc], opp[d])) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
};