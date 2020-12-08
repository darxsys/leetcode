#include <cstdio>
#include <cstring>
#include <climits>
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
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return recurse(s, 0, memo);
    }
private:
    int recurse(string& s, int i, vector<int>& memo)
    {
        if (i == s.size()) return 1;
        if (i > s.size()) return 0;
        if (memo[i] != -1) return memo[i];
        
        int tot = 0;
        if (s[i] != '0')
            tot += recurse(s, i+1, memo);
        
        if (i < s.size()-1)
        {
            if (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')
                tot += recurse(s, i+2, memo);
        }
        
        memo[i] = tot;
        return tot;
    }
};

class Solution2 {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            if (s[i-1] != '0')
                dp[i] = dp[i-1];
            
            if (s[i-2] == '1' || s[i-2] == '2' && s[i-1] <= '6') {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};

int main()
{
    return 0;
}