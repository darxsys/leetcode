#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

void printVec(const vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return vector<int>();

        vector<int> res;
        spiral(matrix, res, 0, 0, 0, 0, 0, matrix[0].size(), matrix.size());
        return res;
    }
private:
    void spiral(const vector<vector<int> > &matrix, vector<int>& res, int m, int n, int hdir, int vdir, int curDir, int rowLim, int colLim)
    {
        if (rowLim == 0 || colLim == 0) return;

        if (curDir == 0 && rowLim > 0) // print current row
        {
            for (int c = 1; c <= rowLim; n += dir[hdir], c++)
            {
                res.push_back(matrix[m][n]);
            }
            spiral(matrix, res, m+dir[hdir], n-dir[hdir], hdir ^ 1, vdir, 1, rowLim, colLim-1);
        }
        else if (colLim > 0) // print current column
        {
            for (int c = 1; c <= colLim; m += dir[vdir], c++)
            {
                res.push_back(matrix[m][n]);
            }
            spiral(matrix, res, m-dir[vdir], n-dir[vdir], hdir, vdir ^ 1, 0, rowLim - 1, colLim);
        }
    }

    vector<int> dir = {1, -1};
};

int main()
{
    Solution s;
    vector<vector<int> > matrix({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    s.spiralOrder(matrix);
    printVec(s.spiralOrder(matrix));

    matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    s.spiralOrder(matrix);
    printVec(s.spiralOrder(matrix));

    matrix = {{1}, {5}, {9}};
    s.spiralOrder(matrix);
    printVec(s.spiralOrder(matrix));

    matrix = {{1, 2, 3}};
    s.spiralOrder(matrix);
    printVec(s.spiralOrder(matrix));

    matrix = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    s.spiralOrder(matrix);
    printVec(s.spiralOrder(matrix));


    return 0;
}