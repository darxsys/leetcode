#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
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
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return vector<int>();

        int n = digits.size();
        vector<int> res;

        int sum = digits[n-1] + 1;
        int carry = sum / 10;
        sum %= 10;
        res.emplace_back(sum);

        for (int i = n - 2; i >= 0; i--)
        {
            sum = digits[i] + carry;
            carry = sum / 10;
            sum = sum % 10;
            res.emplace_back(sum);
        }

        if (carry)
        {
            res.emplace_back(carry);
        }

        reverse(res.begin(), res.end());
        return res;
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
    vector<int> input({1, 2, 3});
    printVec(s.plusOne(input));

    input = {1, 2, 3, 9};
    printVec(s.plusOne(input));

    input = {9, 9, 9, 9};
    printVec(s.plusOne(input));

    return 0;
}