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
    int totalFruit(vector<int>& tree) {
        if (tree.empty()) return 0;

        int sol = 1;
        int prev = -1;
        int cur = tree[0];
        int seen = 1;
        int cur_len = 1;

        for (int i = 1; i < tree.size(); ++i)
        {
            int next = tree[i];
            if (next == cur)
            {
                cur_len++;
                sol = max(sol, cur_len);
                seen++;
            }
            else if (next == prev)
            {
                cur_len++;
                sol = max(sol, cur_len);
                seen = 1;
                int a = cur;
                cur = next;
                prev = a;
            }
            else
            {
               cur_len = seen + 1;
               seen = 1;
               sol = max(sol, cur_len);
               int a = cur;
               cur = next;
               prev = a; 
            }
        }

        return sol;
    }
};

int main()
{
    Solution s;
    vector<int> input({1, 2, 1});
    assert(s.totalFruit(input) == 3);

    input = {0, 1, 2, 2};
    assert(s.totalFruit(input) == 3);

    input = {1, 2, 3, 2, 2};
    assert(s.totalFruit(input) == 4);

    input = {3,3,3,1,2,1,1,2,3,3,4};
    assert(s.totalFruit(input) == 5);

    input = {0, 0, 0, 0, 0, 1};
    assert(s.totalFruit(input) == 6);
    return 0;
}