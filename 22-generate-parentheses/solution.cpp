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
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return vector<string>();

        vector<string> ret;
        backtrack(ret, "", 0, 0, n);
        return ret;
    }
private:
    void backtrack(vector<string> &res, string cur, int left, int right, int max)
    {
        if (cur.size() == 2 * max)
        {
            res.emplace_back(cur);
            return;
        }

        if (left < max)
            backtrack(res, cur + "(", left+1, right, max);

        if (right < left)
            backtrack(res, cur + ")", left, right + 1, max);
    }
};

int main()
{
    Solution s;
    printf("%lu\n", s.generateParenthesis(3).size());
    return 0;
}