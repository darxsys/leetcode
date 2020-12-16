class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if (A.empty()) return 0;
        
        int n = A.size();
        // dp[i][j] - for ith element and difference j
        // dp[i][j] = dp[i+1][j] + 1;
        // dp[n-1][j] = 1, for each possible diff.
        int small = A[0];
        int big = A[0];
        for (int i = 1; i < n; ++i) {
            small = min(A[i], small);
            big = max(A[i], big);
        }
        
        int maxDiff = big - small;
        int minDiff = abs(small - big);
        
        vector<vector<int>> dp(n, vector<int>(maxDiff + minDiff + 1, 1));
        
        int result = 0;
        for (int i = n-2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                int diff = A[j] - A[i] + minDiff;
                dp[i][diff] = max(dp[i][diff], 1 + dp[j][diff]);
                
                result = max(result, dp[i][diff]);
            }
        }
        
        return result;
    }
};