#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> present;
        int longest = 1;

        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            present.insert(nums[i]);
        }

        unordered_set<int>::iterator it = present.begin();
        while (it != present.end())
        {
            int cur = 1;
            int prev = *it - 1;
            while (present.find(prev) != present.end())
            {
                cur++;
                present.erase(present.find(prev));
                prev--;
            }

            int next = *it + 1;
             while (present.find(next) != present.end())
            {
                cur++;
                present.erase(present.find(next));
                next++;
            }           
            
            it = present.erase(it);

            longest = max(longest, cur);
        }

        return longest;
    }
};

int main()
{
    Solution s;
    vector <int> v({100, 4, 200, 1, 3, 2});
    printf("%d\n", s.longestConsecutive(v));
    return 0;
}