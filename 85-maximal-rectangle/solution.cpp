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
    int maximalRectangle(vector<vector<char>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 1; j < matrix.front().size(); ++j)
            {
                if (matrix[i][j] != '0')
                {
                    matrix[i][j] = matrix[i][j-1] + 1;
                }
            }
        }

        int ret = 0;

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix.front().size(); ++j)
            {
                if (matrix[i][j] == '0') continue;

                int minW = matrix[i][j] - '0';
                ret = max(ret, minW);

                for (int k = i + 1; k < matrix.size() && minW; ++k)
                {
                    minW = min(minW, matrix[k][j] - '0');
                    ret = max((k - i + 1) * minW, ret);

                    if (matrix[k][j] - '0' == minW) matrix[k][j] = '0';
                }
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix = {
              {'1','0','1','0','0'},
              {'1','0','1','1','1'},
              {'1','1','1','1','1'},
              {'1','0','0','1','0'}
            };

    assert(s.maximalRectangle(matrix) == 6);
    return 0;
}