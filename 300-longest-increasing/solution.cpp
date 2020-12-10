class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        int result = 0;
        for (int i = n-1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i+1; j < n; ++j) {
                if (nums[j] > nums[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            
            result = max(result, dp[i]);
        }
        
        return result;
    }
};