class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; ++i) {
            for (int coin = 0; coin < coins.size(); ++coin) {
                if (i - coins[coin] >= 0 && dp[i - coins[coin]] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i-coins[coin]]);
                }
            }
        }
        
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};