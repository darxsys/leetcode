class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (flights.empty()) return -1;
        
        vector<vector<int>> dp(n, vector<int>(K+2, INT_MAX));
        vector<vector<int>> adj(n, vector<int>(n, -1));
        
        for (int i = 0; i < flights.size(); ++i) {
            adj[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        
        dfs(adj, dp, src, dst, K+1);
        return dp[src][K+1] < INT_MAX ? dp[src][K+1] : -1;
    }
    
private:
    void dfs(vector<vector<int>>& adj, 
             vector<vector<int>>& dp, int src, int dst, int K) {
        if (src == dst) {
            dp[src][K] = 0;
            return;
        }
        
        if (K == 0) return;
        
        if (dp[src][K] != INT_MAX) {
            return;
        }
        
        for (int i = 0; i < adj[src].size(); ++i) {
            int weight = adj[src][i];
            if (weight != -1) {
                dfs(adj, dp, i, dst, K-1);
                
                if (dp[i][K-1] != INT_MAX) {
                    dp[src][K] = min(dp[src][K], weight + dp[i][K-1]);
                }
            }
        }
    }
};