class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        // dp[i][j] -> number of ways to get sum j with dies up to i.
        // solution dp[d][target]
        
        if (d < 1) return 0;
        
        vector<int> dp(target+1, 0);
        vector<int> dp2(target+1, 0);

        for (int i = 1; i <= min(f, target); ++i) {
            dp2[i] = 1;
        }
        
        for (int i = d-2; i >= 0; --i) {
            for (int k = 1; k <= target; ++k) {
                dp[k] = 0;
                for (int j = 1; j <= f; ++j) {
                    if (j <= k) {
                        dp[k] = (dp[k] + dp2[k-j]) % (1000000000 + 7);
                    }
                }
            }
            swap(dp, dp2);
        }
        
        return dp2[target];
    }
};