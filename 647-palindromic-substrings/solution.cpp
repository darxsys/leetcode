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
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() == 0) return 0;

        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            count++;

            int j = i-1;
            int k = i+1;
            while (j > -1 && k < n && s[j--] == s[k++])
                count++;

            j = i;
            k = i + 1;

            while (j > -1 && k < n && s[j--] == s[k++])
                count++;
        }

        return count;      
    }
};

int main()
{
    Solution s;
    string input = "abc";
    assert(s.countSubstrings(input) == 3);

    input = "aaa";
    assert(s.countSubstrings(input) == 6);    
    return 0;
}