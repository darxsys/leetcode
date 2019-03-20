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
        int n = s.size();
        vector<long long int> dp(s.size()+2, -1);
        dp[n+1] = 0;
        dp[n] = 1;
        
        for (int i = n - 1; i >= 0; --i)
        {
            dp[i] = 0;
            if (s[i] == '*')
            {
                dp[i] = (dp[i] + (9 * dp[i+1])) % mod; // * as one char

                if (i < s.size()-1) // * -> 2 and then whatever that is <= 6.
                {
                    if (s[i+1] == '*')
                    {
                        dp[i] = (dp[i] + 9 * dp[i+2]) % mod; // * -> 1 and then whatever
                        dp[i] = (dp[i] + 6 * dp[i+2]) % mod;
                    }
                    else
                    {
                        dp[i] = (dp[i] + dp[i+2]) % mod;
                        if (s[i+1] <= '6')
                            dp[i] = (dp[i] + dp[i+2]) % mod;
                    }
                }
            }
            else if (s[i] != '0')
            {
                dp[i] = (dp[i] + dp[i+1]) % mod;
            }

            if (i < s.size()-1)
            {
                if (s[i] == '1')
                {
                    if (s[i+1] == '*')
                        dp[i] = (dp[i] + (9 * dp[i+2])) % mod;
                    else
                        dp[i] = (dp[i] + dp[i+2]) % mod;
                }
                else if (s[i] == '2')
                {
                    if (s[i+1] == '*')
                        dp[i] = (dp[i] + (6 * dp[i+2]) % mod);
                    else if (s[i+1] <= '6')
                        dp[i] = (dp[i] + dp[i+2]) % mod;
                }
            }
        }
        
        return dp[0];
    }
private:
    int mod = 1e9 + 7;
};
int main()
{
    return 0;
}