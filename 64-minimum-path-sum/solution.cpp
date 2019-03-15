#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = m-1; i >= 0; --i)
        {
            for (int j = n-1; j >=0; --j)
            {
                int sum = grid[i][j];
                int down = i < m - 1 ? grid[i+1][j] : INT_MAX;
                int right = j < n - 1 ? grid[i][j+1] : INT_MAX;
                
                int m = min(down, right);
                if (m < INT_MAX) grid[i][j] += m;
            }
        }
        
        return grid[0][0];
    }
};

int main()
{
    return 0;
}