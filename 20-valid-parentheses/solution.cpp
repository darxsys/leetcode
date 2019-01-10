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
    bool isValid(string s) {
        if (s == "") return true;

        stack<char> parens;
        parens.push('-');

        for (int i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
                case '(':
                case '[':
                case '{':
                    parens.push(s[i]);
                    break;

                case ')':
                    if (parens.top() != '(') return false;
                    parens.pop();
                    break;
                case ']':
                    if (parens.top() != '[') return false;
                    parens.pop();
                    break;
                case '}':
                    if (parens.top() != '{') return false;
                    parens.pop();
                    break;
                
            }
        }

        return parens.top() == '-';
    }
};


int main()
{
    Solution s;

    assert(s.isValid(""));
    assert(s.isValid("()"));
    assert(!s.isValid("(]"));
    assert(s.isValid("()[]{}"));
    assert(!s.isValid("([)]"));

    return 0;
}