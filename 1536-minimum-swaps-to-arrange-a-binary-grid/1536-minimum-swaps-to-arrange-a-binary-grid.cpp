class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> tail(n);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n-1; j >= 0; j--) {
                if (grid[i][j] == 0) cnt++;
                else break;
            }
            tail[i] = cnt;
        }
        
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int need = n - 1 - i;
            int j = i;
            while (j < n && tail[j] < need) j++;
            if (j == n) return -1;
            while (j > i) {
                swap(tail[j], tail[j-1]);
                j--;
                swaps++;
            }
        }
        return swaps;
    }
};