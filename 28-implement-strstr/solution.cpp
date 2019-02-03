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
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int m = haystack.size();
        int n = needle.size();

        if (n > m) return -1;

        for (int i = 0; i <= m-n; ++i)
        {
            int j = 0;
            for (; j < n; ++j)
            {
                if (haystack[i+j] != needle[j]) break;
            }

            if (j == n)
                return i;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    assert(s.strStr("hello", "ll") == 2);
    assert(s.strStr("aaaaa", "bba") == -1);
    assert(s.strStr("mississippi", "mississippi") == 0);
    return 0;
}