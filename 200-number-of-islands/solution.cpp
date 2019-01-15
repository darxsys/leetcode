#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        vector<int> v(n, 0);
        vector<vector<int>> visited(m, v);

        int count = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return count;
    }
private:
    void dfs(const vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        visited[i][j] = 1;
        for (int k = 0; k < 4; ++k)
        {
            int nexty = i + ydir[k];
            int nextx = j + xdir[k];

            if (nextx >= 0 && nexty >= 0 && nextx < n && nexty < m && !visited[nexty][nextx] && grid[nexty][nextx] == '1')
                dfs(grid, visited, nexty, nextx);
        }
    }

    int xdir[4] = {0, 1, 0, -1};
    int ydir[4] = {1, 0, -1, 0};
};

int main()
{
    Solution s;
    assert(s.numIslands)
    return 0;
}