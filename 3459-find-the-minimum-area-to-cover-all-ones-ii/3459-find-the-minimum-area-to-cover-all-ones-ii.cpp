class Solution {
public:
    int getarea(vector<vector<int>>& grid, int sr, int er, int sc, int ec) {
        int minr = INT_MAX;
        int minc = INT_MAX;
        int maxr = INT_MIN;
        int maxc = INT_MIN;
        bool foundOne = false;

        for (int i = sr; i <= er; ++i) {
            for (int j = sc; j <= ec; ++j) {
                if (grid[i][j] == 1) {
                    foundOne = true;
                    minr = min(minr, i);
                    minc = min(minc, j);
                    maxr = max(maxr, i);
                    maxc = max(maxc, j);
                }
            }
        }
        
        if (!foundOne) {
            return 0;
        }

        return (maxr - minr + 1) * (maxc - minc + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MAX;

        // --- All 6 Partition Cases ---

        // Case 1 & 2: Horizontal cut, then one side split vertically
        for (int r = 0; r < m - 1; ++r) {
            for (int c = 0; c < n - 1; ++c) {
                // Case 1a: Top is one rect, bottom is split vertically
                int area1 = getarea(grid, 0, r, 0, n - 1);
                int area2 = getarea(grid, r + 1, m - 1, 0, c);
                int area3 = getarea(grid, r + 1, m - 1, c + 1, n - 1);
                ans = min(ans, area1 + area2 + area3);

                // Case 1b (FIX): Bottom is one rect, top is split vertically
                int area4 = getarea(grid, r + 1, m - 1, 0, n - 1);
                int area5 = getarea(grid, 0, r, 0, c);
                int area6 = getarea(grid, 0, r, c + 1, n - 1);
                ans = min(ans, area4 + area5 + area6);
            }
        }
        
        for (int c = 0; c < n - 1; ++c) {
            for (int r = 0; r < m - 1; ++r) {
                int area1 = getarea(grid, 0, m - 1, 0, c);
                int area2 = getarea(grid, 0, r, c + 1, n - 1);
                int area3 = getarea(grid, r + 1, m - 1, c + 1, n - 1);
                ans = min(ans, area1 + area2 + area3);

                int area4 = getarea(grid, 0, m - 1, c + 1, n - 1);
                int area5 = getarea(grid, 0, r, 0, c);
                int area6 = getarea(grid, r + 1, m - 1, 0, c);
                ans = min(ans, area4 + area5 + area6);
            }
        }

        for (int r1 = 0; r1 < m - 2; ++r1) {
            for (int r2 = r1 + 1; r2 < m - 1; ++r2) {
                int top = getarea(grid, 0, r1, 0, n - 1);
                int mid = getarea(grid, r1 + 1, r2, 0, n - 1);
                int bottom = getarea(grid, r2 + 1, m - 1, 0, n - 1);
                ans = min(ans, top + mid + bottom);
            }
        }
        
        for (int c1 = 0; c1 < n - 2; ++c1) {
            for (int c2 = c1 + 1; c2 < n - 1; ++c2) {
                int left = getarea(grid, 0, m - 1, 0, c1);
                int mid = getarea(grid, 0, m - 1, c1 + 1, c2);
                int right = getarea(grid, 0, m - 1, c2 + 1, n - 1);
                ans = min(ans, left + mid + right);
            }
        }

        return ans;
    }
};