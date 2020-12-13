class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[strs.size()+1][m+1][n+1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[0][i][j] = 0;
            }
        }
        
        for (int i = 1; i <= strs.size(); ++i) {
            int zcount = std::count(strs[i-1].begin(), strs[i-1].end(), '0');
            int ocount = std::count(strs[i-1].begin(), strs[i-1].end(), '1');
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][j][k] = dp[i-1][j][k];
                    
                    if (j >= zcount && k >= ocount) {
                        dp[i][j][k] = max(dp[i][j][k], 1 + dp[i-1][j-zcount][k-ocount]);
                    } 
                }
            }
        }
        
        return dp[strs.size()][m][n];
    }
}; 