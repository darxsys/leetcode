class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (flights.empty()) return -1;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K+2, INT_MAX)));
        vector<vector<bool>> visited(n, vector<bool>(K+2, false));
        
        for (int i = 0; i < flights.size(); ++i) {
            for (int k = 1; k <= K+1; ++k) {
                dp[flights[i][0]][flights[i][1]][k] = flights[i][2];
            }
        }
        
        dfs(visited, dp, src, dst, K+1);
        return dp[src][dst][K+1] != INT_MAX ? dp[src][dst][K+1] : -1;
    }
    
private:
    void dfs(vector<vector<bool>>& visited, 
             vector<vector<vector<int>>>& dp, int src, int dst, int K) {
        if (src == dst) {
            dp[src][dst][K] = 0;
            return;
        }
        
        if (K == 0) return;
        
        if (dp[src][dst][K] != INT_MAX && visited[src][K]) {
            return;
        }
        
        visited[src][K]= true;
        
        for (int i = 0; i < dp[src].size(); ++i) {
            if (dp[src][i][K] != INT_MAX) {
                dfs(visited, dp, i, dst, K-1);
                
                if (dp[i][dst][K-1] != INT_MAX) {
                    dp[src][dst][K] = min(dp[src][dst][K], dp[src][i][K] + dp[i][dst][K-1]);
                }
            }
        }
    }
};