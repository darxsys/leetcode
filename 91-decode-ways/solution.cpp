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

int main()
{
    return 0;
}