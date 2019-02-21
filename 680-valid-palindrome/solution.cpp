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
    bool validPalindrome(string s) {
        int i = 0; int j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return isPalin(s, i+1, j) || isPalin(s, i, j-1);

            i++; j--;
        }

        return true;
    }
private:
    bool isPalin(string& s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--]) return false;
        }

        return true;
    }
};

int main()
{
    return 0;
}