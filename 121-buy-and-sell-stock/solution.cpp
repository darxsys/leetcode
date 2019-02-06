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
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int minSoFar = prices[0];

        int profit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            profit = max(profit, prices[i] - minSoFar);
            minSoFar = min(minSoFar, prices[i]);
        }

        return profit;
    }
};

int main()
{
    Solution s;
    vector<int> input = {7, 1, 5, 3, 6, 4};
    assert(s.maxProfit(input) == 5);

    input = {7, 6, 4, 3, 1};
    assert(s.maxProfit(input) == 0);
    return 0;
}