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

class SolutionKMP {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        vector<int> prefix = prefixArray(needle);

        int m = haystack.size();
        int n = needle.size();

        // KMP
        for (int i = 0, j = 0; i < m;)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j == 0) i++;
                else
                    j = prefix[j-1];
            }

            if (j == n) return i - j;
        }

        return -1;
    };

private:
    vector<int> prefixArray(const string& in)
    {
        int n = in.size();
        vector<int> lps(n, 0);

        for (int j = 1, i = 0; j < n;)
        {
            if (in[j] == in[i])
            {
                lps[j++] = ++i;
            }
            else if (i > 0)
            {
                i = lps[i-1];
            }
            else
            {
                lps[j++] = 0;
            }
        }

        return lps;
    }
};

int main()
{
    SolutionKMP s;
    assert(s.strStr("hello", "ll") == 2);
    assert(s.strStr("aaaaa", "bba") == -1);
    assert(s.strStr("mississippi", "mississippi") == 0);
    assert(s.strStr("mississippi", "issipi") == -1);
    return 0;
}