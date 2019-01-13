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
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return;

        int n = nums.size();
        int k;
        for (k = n - 2; k >= 0; --k)
        {
            if (nums[k] < nums[k+1])
                break;
        }

        if (k == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int l = n-1;
            for (; l > k; --l)
            {
                if (nums[l] > nums[k]) break;
            }

            swap(nums[l], nums[k]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

void printVec(const vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");
}

int main()
{
    Solution s;
    vector<int> nums({1, 2, 3});
    s.nextPermutation(nums);
    printVec(nums);

    nums = {1, 3, 2};
    s.nextPermutation(nums);
    printVec(nums);

    nums = {1, 2, 3, 5, 4, 7, 6};
    s.nextPermutation(nums);
    printVec(nums);

    nums = {5,4,7,5,3,2};
    s.nextPermutation(nums);
    printVec(nums);

    nums = {2, 3, 1};
    s.nextPermutation(nums);
    printVec(nums);

    nums = {1, 5, 1};
    s.nextPermutation(nums);
    printVec(nums);

    nums = {2,2,7,5,4,3,2,2,1};
    s.nextPermutation(nums);
    printVec(nums);

    nums = {4,2,4,4,3};
    s.nextPermutation(nums);
    printVec(nums);

    return 0;
}