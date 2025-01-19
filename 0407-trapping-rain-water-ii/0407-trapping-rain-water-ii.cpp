#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; ++j) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m - 1][j], {m - 1, j}});
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }
        
        int trappedWater = 0;
        vector<int> directions = {-1, 0, 1, 0, 0, -1, 0, 1};
        
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int height = current.first;
            int x = current.second.first;
            int y = current.second.second;
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i * 2];
                int ny = y + directions[i * 2 + 1];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (height > heightMap[nx][ny]) {
                        trappedWater += height - heightMap[nx][ny];
                    }
                    pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }
        
        return trappedWater;
    }
};
