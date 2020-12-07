class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        
        int n = costs.size();
        for (int i = 1; i < n; ++i) {
            costs[i][0] = costs[i][0] + min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] = costs[i][1] + min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] = costs[i][2] + min(costs[i-1][0], costs[i-1][1]);
        }
        
        int result = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            result = min(result, costs[n-1][i]);
        }
        
        return result;
    }
};