class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefixRow0(n + 1, 0), prefixRow1(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixRow0[i + 1] = prefixRow0[i] + grid[0][i];
            prefixRow1[i + 1] = prefixRow1[i] + grid[1][i];
        }
        
        long long result = LLONG_MAX;
        
        for (int i = 0; i < n; ++i) {
            long long upperPoints = prefixRow0[n] - prefixRow0[i + 1];
            long long lowerPoints = prefixRow1[i];
            long long maxPointsSecondRobot = max(upperPoints, lowerPoints);
            
            result = min(result, maxPointsSecondRobot);
        }
        
        return result;
    }
};
