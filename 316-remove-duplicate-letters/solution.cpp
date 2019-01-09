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
        int pos = 0;

        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            num[s[i] - 'a']++;
        }

        for (int i = 0; i < n; ++i)
        {
            if (s[i] < s[pos]) 
            {
                pos = i;
            }

            if (--num[s[i]-'a'] == 0) break;
        }

        string next = s.substr(pos+1);
        next.erase(std::remove(next.begin(), next.end(), s[pos]), next.end());

        return s[pos] + removeDuplicateLetters(next);
    }
};


int main()
{
    Solution s;
    printf("%s\n", s.removeDuplicateLetters("cbacdcbc").c_str());
    printf("%s\n", s.removeDuplicateLetters("bcabc").c_str());
    printf("%s\n", s.removeDuplicateLetters("abacb").c_str());
    printf("%s\n", s.removeDuplicateLetters("bbcaac").c_str());
    return 0;
}