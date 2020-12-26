#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> all;
        int n = nums.size();
        all.push_back(1);
        for (int i = 0; i < n; ++i)
        {
            all.push_back(nums[i]);
        }

        all.push_back(1);

        vector<int> v(n+2, -1);
        vector<vector<int> > dp(n+2, v);
        return solve(dp, all, 0, n+1);
    }

private:
    int solve(vector<vector<int> >& dp, vector<int>& nums, int i, int j)
    {
        if (i + 1 == j) return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        for (int k = i+1; k < j; ++k)
        {
            dp[i][j] = max(dp[i][j], solve(dp, nums, i, k) + solve(dp, nums, k, j) + nums[k] * nums[i] * nums[j]);
        }

        return dp[i][j];
    }
};

class Solution2 {
public:
    int maxCoins(vector<int>& nums) {        
        int n = nums.size();
        vector<int> padded(n+2, 0);
        padded[0] = padded[n+1] = 1;
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for (int i = 1; i < n + 1; ++i) {
            padded[i] = nums[i-1];
        }
        
        for (int i = n; i > 0; --i) {
            for (int j = i; j < n+1; ++j) {
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + padded[k] * padded[i-1] * padded[j+1]);                  
                }
            }
        }
        
        return dp[1][n];
    }
};

int main()
{
    vector<int> nums({3, 1, 5, 8});

    Solution s;
    printf("%d\n", s.maxCoins(nums));
    return 0;
}