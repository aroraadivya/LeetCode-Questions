class Solution {
public:
    int maxFreeTime(int endT, vector<int>& s, vector<int>& e) {
        int n = s.size();
        int maxLeftGap = s[0];               // Free time before first meeting
        int maxRightGap = endT - e[n - 1];   // Free time after last meeting
        int ans = max(
            maxLeftGap + s[1] - e[0],        // Merge first gap
            maxRightGap + s[n - 1] - e[n - 2] // Merge last gap
        );

        for (int i = 1, j = n - 2; i < n && j >= 0; i++, j--) {
            int a = (i == n - 1 ? endT : s[i + 1]) - e[i - 1];
            int b = (e[i] - s[i] <= maxLeftGap) ? 0 : (e[i] - s[i]);
            ans = max(ans, a - b);

            int c = s[j + 1] - (j == 0 ? 0 : e[j - 1]);
            int d = (e[j] - s[j] <= maxRightGap) ? 0 : (e[j] - s[j]);
            ans = max(ans, c - d);

            maxLeftGap = max(maxLeftGap, s[i] - e[i - 1]);
            maxRightGap = max(maxRightGap, s[j + 1] - e[j]);
        }
        return ans;
    }
};