class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if (stones.empty()) return 0;
        
        int n = stones.size();
        int sum = 0;
        int result = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            sum += stones[i];
        }
        
        int sum2 = sum/2;
        vector<vector<int>> dp(n, vector<int>(sum2+1, 0));
        
        for (int i = stones[0]; i <= sum2; ++i) {
            dp[0][i] = stones[0];
        }
      
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= sum2; ++j) {
                dp[i][j] = dp[i-1][j];
                
                if (stones[i] <= j) {
                    dp[i][j] = max(dp[i][j], stones[i] + dp[i-1][j-stones[i]]);
                }
                
                result = min(result, sum - 2 * dp[i][j]);
            }
        }
        
        return result;
    }
};

// Better solution
class Solution2 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if (stones.empty()) return 0;
        
        int n = stones.size();
        int sum = 0;
        
        for (int i = 0; i < n; ++i) {
            sum += stones[i];
        }
        
        int sum2 = sum/2;
        vector<int> dp(sum2+1, 0);
        
        for (int i = stones[0]; i <= sum2; ++i) {
            dp[i] = stones[0];
        }
      
        for (int i = 1; i < n; ++i) {
            for (int j = sum2; j >= 0; --j) {
                if (stones[i] <= j) {
                    dp[j] = max(dp[j], stones[i] + dp[j-stones[i]]);
                }
                
                // result = min(result, sum - 2 * dp[i][j]);
            }
        }
        
        return sum - 2 * dp[sum2];
    }
};