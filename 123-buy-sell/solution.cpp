class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        int n = prices.size();
        vector<int> dp(n, 0);
        
        int minSoFar = prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i-1], prices[i] - minSoFar);
            minSoFar = min(minSoFar, prices[i]);
        }
        
        int result = dp[n-1];
        dp[n-1] = 0;
        int maxSoFar = prices[n-1];
        for (int i = n - 2; i >= 0; --i) {
            result = max(result, dp[i] + dp[i+1]);
            dp[i] = max(dp[i+1], maxSoFar - prices[i]);
            maxSoFar = max(maxSoFar, prices[i]);
        }

        result = max(result, dp[0]);
        return result;
    }
};