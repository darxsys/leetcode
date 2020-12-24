class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty() || s.size() == 1) return 0;
        
        int n = s.size();
        
        // ()
        // (()))...
        vector<int> dp(n+2, 0);
        int result = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '(' && s[i+1] == ')') {
                dp[i] = 2 + dp[i+2];
            } else if (s[i] == '(' && s[i+1] == '(') {
                if (s[i + dp[i+1] + 1] == ')') {
                    dp[i] = 2 + dp[i+1] + dp[i + dp[i+1] + 2];
                }
            }
            
            result = max(result, dp[i]);
            
        }

        return result;
    }
};