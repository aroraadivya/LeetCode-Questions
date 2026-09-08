class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9 + 7;

        vector<int> dp(n, 1);
        vector<int> countEndWith(26, 0);

        int sum = 0;

        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';

            // New = single char + all old subsequences
            //     - duplicates ending with this char
            dp[i] = (1 + sum - countEndWith[idx] + MOD) % MOD;

            sum = (sum + dp[i]) % MOD;

            // Add all new subsequences ending with s[i]
            countEndWith[idx] = (countEndWith[idx] + dp[i]) % MOD;
        }

        return sum;
    }
};