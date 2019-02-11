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
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0) return -1;

        int lo = 0;
        int n = nums.size();
        int hi = n-1;
        int mid;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if ((mid == 0 || nums[mid-1] < nums[mid]) && (mid == n-1 || nums[mid+1] < nums[mid]))
                return mid;

            if (mid == n-1 || mid > 0 && nums[mid-1] > nums[mid])
                hi = mid-1;
            else
                lo = mid+1;
        }

        return -1;
    }
};

int main()
{
    vector<int> input({1, 2, 3, 1});
    Solution s;
    printf("%d\n", s.findPeakElement(input));

    input = {1, 2, 1, 3, 5, 6, 4};
    printf("%d\n", s.findPeakElement(input));

    input = {1, 2};
    printf("%d\n", s.findPeakElement(input));
    return 0;
}