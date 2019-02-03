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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int i = 0;
        int j = 0;
        int n = nums.size();

        while (true)
        {
            nums[i++] = nums[j++];

            while (j < n && nums[j] == nums[j-1])
                j++;

            if (j == n) break;
        }

        return i;        
    }
};

int main()
{
    return 0;
}