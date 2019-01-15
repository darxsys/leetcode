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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int memo[n];
        memset(memo, -1, sizeof(int) * n);
        vector<vector<string>> subs(n);
        vector<string> res;

        inner(s, wordDict, 0, memo, subs, res);
        return res;
    }
private:
    bool inner(const string& s, const vector<string>& wordDict, int start, int* memo, vector<vector<string>>& subs, vector<string>& res)
    {
        if (start == s.size())
        {
            res.push_back("");
            return true;
        }

        if (memo[start] != -1)
        {
            res = subs[start];
            return true;
        }

        memo[start] = false;
        for (const string& word : wordDict)
        {
            int n = s.size();
            int c = word.size();
            vector<string> substrings;
            if (start + c <= n && word == s.substr(start, c) && inner(s, wordDict, start + c, memo, subs, substrings))
            {
                memo[start] = true;
                for (const string& sub : substrings)
                {
                    if (sub != "")
                        subs[start].push_back(s.substr(start, c) + " " + sub);
                    else
                        subs[start].push_back(s.substr(start, c));
                }
            }
        }

        res = subs[start];
        return memo[start];
    }
};

void printVec(const vector<string>& strings)
{
    for (int i = 0; i < strings.size(); ++i)
    {
        printf("%s\n", strings[i].c_str());
    }
}

int main()
{
    Solution s;
    string input = "catsanddog";
    vector<string> dict = {"cat", "cats", "and", "sand", "dog"};
    printVec(s.wordBreak(input, dict));

    input = "pineapplepenapple";
    dict = {"apple", "pen", "applepen", "pine", "pineapple"};
    printVec(s.wordBreak(input, dict));

    input = "catsandog";
    dict = {"cats", "dog", "sand", "and", "cat"};
    printVec(s.wordBreak(input, dict));
    return 0;
}