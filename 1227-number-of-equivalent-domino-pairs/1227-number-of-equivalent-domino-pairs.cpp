class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int arr[10][10] = {0}; // Only digits 1-9 used

        for (auto &d : dominoes) {
            int x = min(d[0], d[1]);
            int y = max(d[0], d[1]);
            arr[x][y]++;
        }

        int ans = 0;
        for (int i = 1; i < 10; ++i) {
            for (int j = 1; j < 10; ++j) {
                int count = arr[i][j];
                if (count > 1) {
                    ans += count * (count - 1) / 2;
                }
            }
        }

        return ans;
    }
};