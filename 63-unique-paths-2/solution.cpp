class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || 
            obstacleGrid[0].empty() || 
            obstacleGrid.back().back() == 1) return 0;
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        obstacleGrid[n-1][m-1] = 1;
        
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                if ((i < n-1 || j < m-1) && obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                } else {
                    if (i < n-1) {
                        obstacleGrid[i][j] = obstacleGrid[i+1][j];
                    }
                    if (j < m-1) {
                        // hack to prevent integer overflow while keeping the solution with O(1) extra
                        // memory
                        if (int64_t(obstacleGrid[i][j]) + obstacleGrid[i][j+1] > INT_MAX) continue;
                        obstacleGrid[i][j] += obstacleGrid[i][j+1];
                    }
                }
            }
        }
        
        return obstacleGrid[0][0];
    }
};