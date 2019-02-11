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
    string countAndSay(int n) {
        string out = "1";
        for(int k = 2; k <= n; ++k)
        {
            int i = 1;
            int count = 1;
            char c = out[0];
            string tmp = "";
            while (true)
            {
                while (i < out.size() && out[i] == out[i-1])
                {
                    count++;
                    i++;
                }
                
                tmp += to_string(count) + c;
                if (i < out.size())
                {
                    c = out[i++];
                    count = 1;
                }
                else
                {
                    out = tmp;
                    break;
                }
            }
        }      

        return out;
    }
};


int main()
{
    Solution s;
    printf("%s\n", s.countAndSay(1).c_str());
    printf("%s\n", s.countAndSay(2).c_str());
    printf("%s\n", s.countAndSay(3).c_str());
    printf("%s\n", s.countAndSay(4).c_str());
    printf("%s\n", s.countAndSay(5).c_str());
    printf("%s\n", s.countAndSay(6).c_str());
    printf("%s\n", s.countAndSay(7).c_str());
    printf("%s\n", s.countAndSay(8).c_str());
    printf("%s\n", s.countAndSay(9).c_str());
    printf("%s\n", s.countAndSay(10).c_str());
    return 0;
}