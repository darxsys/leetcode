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
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        sums[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            if (k != 0)
                sum %= k;

            if (sums.find(sum) != sums.end())
            {
                printf("HERE %d %d %d\n", i, sums[sum], i - sums[sum]);
                if ((i - sums[sum]) > 1)
                    return true;

                printf("%d\n", i - sums[sum]);
            }
            else
            {
                sums[sum] = i;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums({23, 2, 4, 6, 7});
   // assert(s.checkSubarraySum(nums, 6) == true);

    nums = {23, 2, 6, 4, 7};
    //assert(s.checkSubarraySum(nums, 6) == true);

    nums = {0, 0, 0};
    assert(s.checkSubarraySum(nums, 0) == true);
    return 0;
}