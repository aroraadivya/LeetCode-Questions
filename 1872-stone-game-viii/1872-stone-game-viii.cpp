class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix = stones;

        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

        int best = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            best = max(best, prefix[i] - best);
        }

        return best;
    }
};