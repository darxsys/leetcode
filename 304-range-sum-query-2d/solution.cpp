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
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> v(n, 0);
        sums = vector<vector<int>>(m, v);
        
        for (int j = 0; j < n; ++j)
            sums[0][j] = matrix[0][j] + (j > 0 ? sums[0][j-1] : 0);
        
        for (int i = 0; i < m; ++i)
        {
            sums[i][0] = matrix[i][0] + (i > 0 ? sums[i-1][0] : 0);
        }
        
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                sums[i][j] = matrix[i][j] + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = sums[row2][col2];
        
        if (row1-1 >= 0)
            res -= sums[row1-1][col2];
        
        if (col1-1 >= 0)
            res -= sums[row2][col1-1];
        
        if (row1-1 >= 0 && col1-1 >= 0)
            res += sums[row1-1][col1-1];
        
        return res;
    }
    
private:
    vector<vector<int>> sums;
};

int main()
{
    return 0;
}