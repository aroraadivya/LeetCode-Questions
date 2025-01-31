class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int dfs(vector<vector<int>>& grid, int x, int y, int islandIndex, unordered_map<int, int>& islandSize) {
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 1) return 0;
        
        grid[x][y] = islandIndex;
        int size = 1;
        for (auto& dir : directions) {
            size += dfs(grid, x + dir[0], y + dir[1], islandIndex, islandSize);
        }
        
        return size;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandSize;
        int index = 2, maxIsland = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    islandSize[index] = dfs(grid, i, j, index, islandSize);
                    maxIsland = max(maxIsland, islandSize[index]);
                    index++;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> adjacentIslands;
                    int newSize = 1;
                    
                    for (auto& dir : directions) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
                            adjacentIslands.insert(grid[x][y]);
                        }
                    }
                    
                    for (int island : adjacentIslands) {
                        newSize += islandSize[island];
                    }
                    
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }
        
        return maxIsland;
    }
};
