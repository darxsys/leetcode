class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        int result = 0;
        int n = prices.size();
        
        vector<int> dp(n, 0);
        vector<int> dp2(n+1, 0);
        
        int minSoFar = prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i-1], prices[i] - minSoFar);
            minSoFar = min(minSoFar, prices[i]);
        }
        
        int maxSoFar = prices[n-1];
        for (int i = n - 2; i >= 0; --i) {
            dp2[i] = max(dp2[i+1], maxSoFar - prices[i]);
            maxSoFar = max(maxSoFar, prices[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            result = max(result, dp[i] + dp2[i+1]);
        }
        
        return result;
    }
};