class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j] = 1 + dp[i-1][j-1] if i==j, else max(dp[i-1][j], dp[i][j-1]);
        
        int n = text1.size();
        int m = text2.size();
        
        if (n == 0 || m == 0) {
            return 0;
        }
        
        vector<int> dp(m+1, 0);
        vector<int> dp2(m+1, 0);
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[j] = 1 + dp2[j-1];
                }
                
                int dropOne = max(dp2[j], dp[j-1]);
                dp[j] = max(dp[j], dropOne);
            }
            
            swap(dp, dp2);
        }
        
        return dp2[m];
    }
};