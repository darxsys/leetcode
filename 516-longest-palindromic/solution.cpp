class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return recurse(0, n-1, s, dp);
    }
private:
    int recurse(int start, int end, string& s, vector<vector<int>>& dp) {
        if (start == end) return 1;
        
        if (start > end) return 0;
        
        if (dp[start][end] != -1) return dp[start][end];
        
        if (s[start] == s[end]) {
            dp[start][end] = 2 + recurse(start+1, end-1, s, dp);
        } else {
           dp[start][end] = max(recurse(start+1, end, s, dp), recurse(start, end-1, s, dp));
        }
        
        return dp[start][end];
    }
};

class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        
        int n = s.size();
        vector<int> dp(n, 0);
        vector<int> dp2(n, 0);
        
        for (int i = n-1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i+1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[j] = 2 + dp2[j-1];
                } else {
                    dp[j] = max(dp2[j], dp[j-1]);
                }
            }
            
            swap(dp, dp2);
        }
        
        return dp2[n-1];
    }
};