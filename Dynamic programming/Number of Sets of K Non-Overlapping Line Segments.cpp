class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1'000'000'007;

        vector<long long> dp(k + 1, 0);
        vector<long long> open(k + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= 0; --j) {
                // Close an existing segment at point i.
                if (j > 0) {
                    dp[j] = (dp[j] + open[j - 1]) % MOD;
                }

                // Start a new segment at point i.
                open[j] = (open[j] + dp[j]) % MOD;
            }
        }

        return dp[k];
    }
};
