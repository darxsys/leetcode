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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;

        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int start = i;
            while (i + 1 < n && nums[i+1] == nums[i] + 1) i++;

            ret.push_back(to_string(nums[start]) + (i > start ? "->" + to_string(nums[i]) : ""));
        }

        return ret;
    }
};

void printVec(const vector<string>& vec)
{
    printf("[");
    for (int i = 0; i < vec.size(); ++i)
    {
        printf("%s,", vec[i].c_str());
    }

    printf("]\n");
}

int main()
{
    Solution s;
    vector<int> input({0, 1, 2, 4, 5, 7});
    printVec(s.summaryRanges(input));

    input = {0,2,3,4,6,8,9};
    printVec(s.summaryRanges(input));
    return 0;
}