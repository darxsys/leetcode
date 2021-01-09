class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0][0] == 1) return -1;
        
        int len = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        const int ydir[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        const int xdir[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = -1;
        
        while (!q.empty()) {
            int size = q.size();
            len++;
            
            for (int i = 0 ; i < size; ++i) {
                auto [cury, curx] = q.front();
                if (cury == n-1 && curx == m-1) return len;
                    
                q.pop();                
                for (int j = 0; j < 8; ++j) {
                    int nexty = cury + ydir[j];
                    int nextx = curx + xdir[j];
                    
                    if (nexty < 0 || nexty >= n || 
                        nextx < 0 || nextx >= m || 
                        grid[nexty][nextx] == 1 || grid[nexty][nextx] == -1) continue;
                    
                    q.push({nexty, nextx});
                    grid[nexty][nextx] = -1;
                }
            }   
        }

        return -1;
    }
};