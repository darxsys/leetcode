class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int result = -1;
        
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    q.push(pair<int, int>(i, j));
                } else if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        
        if (count == 0) return 0;
        
        while (!q.empty()) {
            result++;
            int s = q.size();
            
            for (int i = 0; i < s; ++i) {
                auto cur = q.front();
                q.pop();
                
                for (int j = 0; j < 4; ++j) {
                    int nextx = cur.first + xdir[j];
                    int nexty = cur.second + ydir[j];
                    if (nextx < 0 || nextx >= grid.size() || 
                        nexty < 0 || nexty >= grid[0].size()) continue;
                    
                    if (grid[nextx][nexty] == 1) {
                        grid[nextx][nexty] = 2;
                        count--;
                        q.push(pair<int, int>(nextx, nexty));
                    }
                }
            }
        }
        
        return count == 0 ? result : -1;
    }
    
private:
    static constexpr int xdir[4] = {-1, 0, 1, 0};
    static constexpr int ydir[4] = {0, -1, 0, 1};
};