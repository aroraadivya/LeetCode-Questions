class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros = 0, ans = 0;
        for (char c : s) ones += c == '1';
        for (int i = 0; i < s.size() - 1; ++i) {
            char c  = s[i];
            zeros += c == '0';
            ones -= c == '1';
            ans = max(ans, zeros + ones);
        }
        return ans;
    }
};