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
    bool wordBreak(string s, vector<string>& wordDict) {
        int memo[s.size()];
        memset(memo, -1, sizeof(int) * s.size());
        return inner(s, wordDict, 0, memo);
    }

private:
    bool inner(const string& s, const vector<string>& wordDict, int start, int* memo)
    {
        if (start == s.size()) return true;
        if (memo[start] != -1) return memo[start];

        for (const string& word : wordDict)
        {
            int l = word.size();
            int c = s.size();

            int end = start + l;
            if (end <= c && word == s.substr(start, l) && inner(s, wordDict, end, memo))
            {
                memo[start] = true;
                return true;
            }
        }

        memo[start] = false;
        return false;
    }
};

class Solution2 { // DP solution
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        bool dp[n+1];
        dp[n] = true;
        
        for (int i = n -1; i >= 0; --i)
        {
            dp[i] = false;
            for (const string& word: wordDict)
            {
                if (word.size() + i <= n && word == s.substr(i, word.size()))
                {
                    dp[i] = dp[i + word.size()];
                    if (dp[i])
                        break;
                }
            }
        }
        
        return dp[0];
    }
};

int main()
{
    Solution s;

    string word = "leetcode";
    vector<string> dict = {"leet", "code"};

    assert(s.wordBreak(word, dict) == true);

    word = "applepenapple";
    dict = {"apple", "pen"};
    assert(s.wordBreak(word, dict) == true);

    word = "catsandog";
    dict = {"cats", "dog", "sand", "and", "cat"};
    assert(s.wordBreak(word, dict) == false);

    return 0;
}