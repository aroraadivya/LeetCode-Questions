class Solution 
{
public:
    int numTilings(int n) 
    {
        int MOD = 1e9 + 7;

        // Step 1: Handle base cases
        if (n == 1)
        {
            return 1;
        }

        if (n == 2)
        {
            return 2;
        } 

        // Step 2: Create a dp array
        vector<long long> dp(n + 1);
        dp[0] = 1;  // Empty board
        dp[1] = 1;  // One vertical domino
        dp[2] = 2;  // Two verticals or two horizontals

        // Step 3: Fill dp array using recurrence
        for (int i = 3; i <= n; ++i) 
        {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
        }

        // Step 4: Return final result
        return dp[n];
    }
};