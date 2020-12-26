class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = true;
        
        for (int i = 1; i <= m; ++i) {
            if (p[i-1] == '*') {
                // dp[i-1][k], for all k
                int j = 0;
                while(j <= n && !dp[i-1][j]) ++j;
                
                while(j <= n) {
                    dp[i][j] = true;
                    ++j;
                }
            } else {
                int j = 1;
                while (j <= n) {
                    if (p[i-1] == '?' || s[j-1] == p[i-1])
                        dp[i][j] = dp[i-1][j-1];
                    ++j;
                }
            }
        }
        
        return dp[m][n];
    }
};