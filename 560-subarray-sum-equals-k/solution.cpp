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

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sol = 0;
        unordered_map<int, int> sums;
        sums[0] = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (sums.find(sum-k) != sums.end())
                sol += sums[sum-k];

            if (sums.find(sum) != sums.end())
                sums[sum]++;
            else
                sums[sum] = 1;
        }

        return sol;
    }
};

int main()
{
    vector<int> input({1, 1, 1});
    Solution s;
    assert(s.subarraySum(input, 2) == 2);
    assert(s.subarraySum(input, 3) == 1);
    assert(s.subarraySum(input, 1) == 3);
    return 0;
}