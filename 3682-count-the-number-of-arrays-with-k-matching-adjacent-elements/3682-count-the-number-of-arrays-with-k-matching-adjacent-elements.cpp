class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 100005;
    vector<long long> fact, invFact;

    Solution() {
        precomputeFactorials(MAX);
    }

    void precomputeFactorials(int n) {
        fact.resize(n);
        invFact.resize(n);
        fact[0] = 1;
        for (int i = 1; i < n; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n - 1] = modPow(fact[n - 1], MOD - 2);
        for (int i = n - 2; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long modPow(long long a, long long b) {
        long long result = 1;
        a %= MOD;
        while (b > 0) {
            if (b % 2)
                result = result * a % MOD;
            a = a * a % MOD;
            b /= 2;
        }
        return result;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        long long comb = nCr(n - 1, k);
        long long groupWays = modPow(m - 1, n - 1 - k);
        long long total = comb * m % MOD * groupWays % MOD;
        return total;
    }
};