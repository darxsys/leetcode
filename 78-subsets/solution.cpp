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
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return vector<vector<int>>();

        int n = nums.size();
        vector<int> v;
        vector<vector<int> > sol(1 << n, v);
        long long int bitmask = 0;

        for (int i = 0; i < n; ++i)
        {
            bitmask |= (1 << i);
        }

        for (int i = 0; i <= bitmask; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((1 << j) & i)
                {
                    sol[i].push_back(nums[j]);
                }
            }
        }

        return sol;
    }
};


void printVecOfVec(const vector<vector<int>>& v)
{
    printf("[\n");

    for (int i = 0; i < v.size(); ++i)
    {
        printf("[");
        for (int j = 0; j < v[i].size(); ++j)
        {
            printf("%d ", v[i][j]);
        }

        printf("]\n");
    }

    printf("]\n");
}

int main()
{
    Solution s;
    vector<int> input = {1, 2, 3};
    printVecOfVec(s.subsets(input));
    return 0;
}