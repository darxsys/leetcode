class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        if (books.empty() || shelf_width == 0) return 0;
        
        int n = books.size();
        // dp[i] = min height up to element [i]
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            // start new shelf
            dp[i] = dp[i-1] + books[i-1][1];
            
            // or try to group the book with some previous ones
            int cap = 0;
            int maxH = books[i-1][1];
            for (int j = i; j > 0 && ((cap + books[j-1][0]) <= shelf_width); --j) {
                cap += books[j-1][0];
                maxH = max(maxH, books[j-1][1]);
                dp[i] = min(dp[i], maxH + dp[j-1]);
            }

        }
        
        return dp[n];
    }
};