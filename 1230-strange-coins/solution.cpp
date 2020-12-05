class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        if (target > prob.size()) return 0;
        if (target < 0) return 0;
        
        int n = prob.size();
        
        // Probability that n will be head starting with coin i is
        // probability that i is head and there are n-1 heads in the remaining,
        // or i is tails and there are n heads in the rest.
        // dp[i][n] = prob[i] * (dp[i+1][n-1]) + (1-prob[i]) * dp[i+1][n];
        vector<double> inner(target+1, 0);
        vector<vector<double>> dp(n, inner);
        
        dp[n-1][0] = 1 - prob[n-1];
        for (int i = n-2; i >= 0; --i) {
            dp[i][0] = (1-prob[i]) * dp[i+1][0];
        }
        
        if (target > 0) {
            dp[n-1][1] = prob[n-1];
        }
        
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 1; j <= target; ++j) {
                dp[i][j] = prob[i] * dp[i+1][j-1] + (1-prob[i]) * dp[i+1][j];
            }
        }
        
        return dp[0][target];
    }
};