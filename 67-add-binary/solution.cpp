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
    string addBinary(string a, string b) {
        string out;

        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        char res;
        while (i >= 0 || j >= 0)
        {
            res = 0;
            if (i >= 0)
                res += (a[i] - '0');

            if (j >= 0)
                res += (b[j] - '0');

            res += carry;
            carry = res / 2;
            res %= 2;

            out += (res + '0');             
            i--; j--;
        }

        if (carry)
            out += '1';

        reverse(out.begin(), out.end());
        return out;
    }
};

int main()
{
    Solution s;
    printf("%s\n", s.addBinary("0", "0").c_str());
    printf("%s\n", s.addBinary("0", "1").c_str());
    printf("%s\n", s.addBinary("1", "1").c_str());
    printf("%s\n", s.addBinary("11", "1").c_str());
    printf("%s\n", s.addBinary("111", "11").c_str());
    printf("%s\n", s.addBinary("1010", "1111").c_str());
    return 0;
}