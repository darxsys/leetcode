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
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>();

        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i)
        {
            int diff = target-nums[i];
            if (m.find(diff) != m.end())
            {
                return vector<int>({i, m[diff]});
            }

            m[nums[i]] = i;
        }

        return vector<int>();
    }
};

int main()
{
    Solution s;
    vector<int> input({2, 7, 11, 15});
    vector<int> res = s.twoSum(input, 9);
    printf("%d %d\n", res[0], res[1]);
    return 0;
}
