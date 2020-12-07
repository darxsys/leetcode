class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int n = nums.size();
        if (n  == 1) { return nums.back(); }
        
        // dp[i] = (val[i] + dp[i+2], val[i+1] + dp[i+3]
        vector<int> dp(3, 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        if (n > 2) {
            dp[2] = max(nums[1], nums[0] + nums[2]);
        }

        for (int i = 3; i < n; ++i) {
            dp[i % 3] = max(nums[i] + dp[(i-2) % 3], nums[i-1] + dp[(i-3) % 3]);
        }
        
        return dp[(n-1) % 3];
    }
};