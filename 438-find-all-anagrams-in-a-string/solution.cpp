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
    vector<int> findAnagrams(string s, string p) {
        vector<int> sol;
        if (s.empty()) return sol;

        int k = p.size();
        vector<int> chars(30, -1);
        int target = 0;
        for (int i = 0; i < p.size(); ++i)
        {
            if (chars[p[i]-'a'] == -1) 
            {
                chars[p[i]-'a'] = 1;
                target++;
            }
            else
            {
                chars[p[i]-'a']++;
            }
        }

        int left = 0;
        int right = 0;
        int count = 0;
        int n = s.size();
        while (right < n)
        {
            if (right < n && chars[s[right]-'a'] == -1) // not in original string
            {
                count = 0;
                while (left <= right)
                {
                    if (chars[s[left]-'a'] != -1)
                        chars[s[left]-'a']++;
                    left++;
                }

                right++;
                continue;
            }

            if (chars[s[right]-'a'] == 0)
            {
                if (chars[s[left]-'a'] != -1)
                    if (chars[s[left]-'a']++ == 0) count--;
                left++;
                continue;
            }

            if (chars[s[right++]-'a']-- == 1) count++;

            if (count == target)
            {
                sol.push_back(left);
                chars[s[left++]-'a']++;
                count--;
            }
        }

        return sol;
    }
};


int main()
{
    Solution s;
    s.findAnagrams("cbaebabacd", "abc");
    return 0;
}