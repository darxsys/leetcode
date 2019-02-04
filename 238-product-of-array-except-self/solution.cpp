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
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return vector<int>();

        int n = nums.size();
        vector<int> sol(n, 0);

        sol[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            sol[i] = sol[i-1] * nums[i-1];
        }

        int prod = 1;
        for (int j = n-1; j >= 0; --j)
        {
            sol[j] = sol[j] * prod;
            prod *= nums[j];
        }

        return sol;
    }
};

void printVec(const vector<int>& vec)
{
    int n = vec.size();
    printf("[");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", vec[i]);
    }

    printf("]\n");
}

int main()
{
    Solution s;
    vector<int> input = {1, 2, 3, 4};
    printVec(s.productExceptSelf(input));

    return 0;
}