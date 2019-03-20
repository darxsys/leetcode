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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.empty()) return 0;
        
        int n = s.size();
        int counter = 0;
        unordered_map<char, int> chars;
        int left = 0, right = 0;
        int m = 0;
        
        while (right < n)
        {
            if (chars[s[right++]-'a']++ == 0) counter++;
            while (counter > k)
            {
                if (chars[s[left++]-'a']-- == 1) counter--;
            }
            
            if (right - left > m) m = right - left;
        }
        
        return m;
    }
};
int main()
{
    return 0;
}
