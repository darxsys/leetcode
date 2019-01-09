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
    string removeDuplicateLetters(string s) {
        if (s == "")
            return "";

        vector<int> num(30, 0);
        int n = s.size();
        vector<bool> in(n, false);

        char stack[n+1];
        stack[n] = '\0';

        for (int i = 0; i < n; ++i)
        {
            num[s[i] - 'a']++;
        }

        int i = 0;
        int j = -1;

        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            while (!in[c-'a'] && j >= 0 && stack[j] >= c && num[stack[j]-'a'] >= 1)
            {
                in[stack[j] - 'a'] = false;
                stack[j] = '\0';
                j--;
            }

            if (!in[c-'a'])
            {
                stack[++j] = c;
                in[c-'a'] = true;
            }

            num[c-'a']--;
        }

        stack[++j] = '\0';
        return string(stack);
    }
};


int main()
{
    Solution s;
    printf("%s\n", s.removeDuplicateLetters("cbacdcbc").c_str());
    printf("%s\n", s.removeDuplicateLetters("bcabc").c_str());
    printf("%s\n", s.removeDuplicateLetters("abacb").c_str());
    return 0;
}