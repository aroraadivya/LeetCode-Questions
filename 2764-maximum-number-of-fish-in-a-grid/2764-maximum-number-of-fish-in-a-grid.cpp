class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;

        function<int(int, int)> dfs = [&](int r, int c) -> int {
            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
                return 0;
            
            int fish = grid[r][c];
            grid[r][c] = 0;
            fish += dfs(r + 1, c);
            fish += dfs(r - 1, c);
            fish += dfs(r, c + 1);
            fish += dfs(r, c - 1);

            return fish;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, dfs(i, j));
                }
            }
        }

        return maxFish;
    }
};
